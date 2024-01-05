// Fill out your copyright notice in the Description page of Project Settings.


#include "Jupiter.h"
// Sets default values
AJupiter::AJupiter()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 6500.0f;
	SemiMinorAxis = 6200.0f;
	EllipseSpeed = 13.0f;
	CurrentAngle = 0.0f;

	FVector CurrentLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(CurrentLocation);

	
}
// Called when the game starts or when spawned
void AJupiter::BeginPlay()
{
	Super::BeginPlay();

	FVector Sc = FVector(6.2f, 6.2f, 6.2f);
	SetActorScale3D(Sc);
}

void AJupiter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Rotate the box
	
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(NewRotation);

	CurrentAngle += EllipseSpeed * DeltaTime;
	float X = SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentAngle));
	float Y = SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentAngle));
	SetActorLocation(FVector(X, Y, GetActorLocation().Z));
}

