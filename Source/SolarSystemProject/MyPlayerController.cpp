// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include <EnhancedInputComponent.h>
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FClassFinder<UTextWidget> panelWidgetClass(TEXT("/Game/Blueprints/WBP_TextWidget"));
	WidgetClass = panelWidgetClass.Class;
}

void AMyPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	if (!WidgetInstance && WidgetClass)
	{
		WidgetInstance = CreateWidget<UTextWidget>(this, WidgetClass);
	}
}
//
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	PawnMappingContext = NewObject<UInputMappingContext>(this);

	// Bind left mouse button click to hide the widget
	MoveAction = NewObject<UInputAction>(this);
	MoveAction->ValueType = EInputActionValueType::Axis3D;
	PawnMappingContext->MapKey(MoveAction, EKeys::LeftMouseButton);
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(this->InputComponent);
	EIC->BindAction(MoveAction, ETriggerEvent::Started, this, &AMyPlayerController::performRaycast);
	// Bind right mouse button click to hide the widget
	MoveAction = NewObject<UInputAction>(this);
	MoveAction->ValueType = EInputActionValueType::Axis1D;
	PawnMappingContext->MapKey(MoveAction, EKeys::RightMouseButton);
	EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::HideWidget);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = this->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(this->PawnMappingContext, 0);
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HitActor)
	{
		//Show the widget for the selected actor

		FVector ActorLocation = HitActor->GetActorLocation();
		double XValue = ActorLocation.X;
		double YValue = ActorLocation.Y;
		double ZValue = ActorLocation.Z;
		double Distance = FMath::Sqrt(FMath::Square(XValue)+ FMath::Square(YValue)+ FMath::Square(ZValue));

		FVector ActorScale = HitActor->GetActorScale3D();
		FVector DesiredScale= FVector(10.0f, 10.0f, 10.0f);
		if (WidgetInstance)
		{
			FString Mass = "";
			FString Velocity = "";
			FString Diameter = "";

			if (Distance <= 10500.0f && Distance >= 10200.0f) {
				Mass = "Neptune Mass: 1.02 x 1026 kg";
				Velocity = "Neptune Velocity: 12,460 miles an hour";
				Diameter = "Neptune Diameter: 34,503 miles";
			}
			else if (Distance <= 9500.0f && Distance >= 9200.0f) {
				Mass = "Uranus Mass: 8.681 x 10^25 kg";
				Velocity = "Uranus Velocity: 15,290 miles per hour";
				Diameter = "Uranus Diameter: 31,000 miles";
			}
			else if (Distance <= 8000.0f && Distance >= 7700.0f) {
				Mass = "Saturn Mass: 5.683 x 10^26 kg";
				Velocity = "Saturn Velocity: 21,637 miles per hour";
				Diameter = "Saturn Diameter: 72,400 miles";
			}
			else if (Distance <= 6500.0f && Distance >= 6200.0f) {
				Mass = "Jupiter Mass: 1.899 x 1027 kg";
				Velocity = "Jupiter Velocity: 29,236 miles per hour";
				Diameter = "Jupiter Diameter: 88,695 miles";
			}
			else if (Distance <= 5800.0f && Distance >= 5500.0f) {
				Mass = "Mars Mass: 6.39 x 10^23 kg";
				Velocity = "Mars Velocity: 53,979 miles per hour";
				Diameter = "Mars Diameter: 4,222 miles";
			}
			else if (Distance <= 5300.0f && Distance >= 5000.0f) {
				Mass = "Earth Mass: 5.972 x 10^24 kg";
				Velocity = "Earth Velocity: 67,000 miles per hour";
				Diameter = "Earth Diameter: 7,926 miles";
			}
			else if (Distance <= 4800.0f && Distance >= 4500.0f) {
				Mass = "Venus Mass: 4.867 x 10^24 kg";
				Velocity = "Venus Velocity: 78,341 miles per hour";
				Diameter = "Venus Diameter: 7,520.8 miles";
			}
			else if (Distance <= 4300.0f && Distance >= 4000.0f) {
				Mass = "Mercury Mass: 3.30104 x 1023 kg";
				Velocity = "Mercury Velocity: 107,082 miles per hour";
				Diameter = "Mercury Diameter: 3,031.9 miles";
			}
			else if(Distance==0){
				if(ActorScale.Equals(DesiredScale))
				{
					Mass = "Sun Mass: 1.9891 x 1030 kg";
					Velocity = "Sun Velocity:  448,000 miles per hour";
					Diameter = "Sun Diameter: 865,000 miles";
				}
				else {
					Mass = "Clicked!";
				}
			}
			
			//WidgetInstance->AddToViewport();
			ShowWidget(Mass, Velocity, Diameter, Distance);
		}
	}
}

void AMyPlayerController::ShowWidget(FString mass, FString velocity, FString diameter, double distance)
{
	if (WidgetInstance)
	{
		WidgetInstance->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("Widget is showing."));
		WidgetInstance->SetMassText(FText::FromString(mass));
		WidgetInstance->SetVelocityText(FText::FromString(velocity));
		WidgetInstance->SetDiameterText(FText::FromString(diameter));
		FString DistanceFromSun = FString::Printf(TEXT("Current distance from sun : %f"), distance);
		if (distance == 0)DistanceFromSun = "";
		WidgetInstance->SetDistanceText(FText::FromString(DistanceFromSun));
		WidgetInstance->AddToViewport();
	}
}

void AMyPlayerController::HideWidget()
{
	HitActor = nullptr;
	WidgetInstance->SetVisibility(ESlateVisibility::Hidden);
	UE_LOG(LogTemp, Warning, TEXT("Widget is gone."));
}

void AMyPlayerController::performRaycast()
{
	FVector WorldLocation, WorldDirection;
	DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FVector Start = WorldLocation;
	FVector End = Start + WorldDirection * 10000.f; // Ray length: 10000 units
	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;

	CollisionParams.AddIgnoredActor(this); // Ignore the player controller during raycasting

	// Perform the raycast
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
	{
	//	DrawDebugLine(GetWorld(), Start, End, FColor::Red, true);
		HitActor = HitResult.GetActor();
	}
}

void AMyPlayerController::performRaycastHide()
{
	
}
