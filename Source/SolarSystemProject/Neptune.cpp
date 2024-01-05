// Fill out your copyright notice in the Description page of Project Settings.


#include "Neptune.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ANeptune::ANeptune()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 10500.0f;
	SemiMinorAxis = 10200.0f;
	EllipseSpeed = 0.0f;
	CurrentAngle = 0.0f;

	FVector Location = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(Location);
}

// Called when the game starts or when spawned
void ANeptune::BeginPlay()
{
	Super::BeginPlay();
	FVector _Scale = FVector(2.5f, 2.5f, 2.5f);
	SetActorScale3D(_Scale);
}

// Called every frame
void ANeptune::Tick(float DeltaTime)
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

