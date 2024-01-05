// Fill out your copyright notice in the Description page of Project Settings.


#include "Venus.h"

// Sets default values
AVenus::AVenus()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 4800.0f;
	SemiMinorAxis = 4500.0f;
	EllipseSpeed = 2.5f;
	CurrentAngle = 0.0f;

	FVector MercuryLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(MercuryLocation);
}

void AVenus::BeginPlay()
{
	Super::BeginPlay();
	FVector _Scale = FVector(3.0f, 3.0f, 3.0f);
	SetActorScale3D(_Scale);
}

void AVenus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate the box
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(NewRotation);

	
	CurrentAngle += EllipseSpeed * DeltaTime;

	// Calculate new position along the elliptical path
	float X = SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentAngle));
	float Y = SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentAngle));

	SetActorLocation(FVector(X, Y, GetActorLocation().Z));

}

