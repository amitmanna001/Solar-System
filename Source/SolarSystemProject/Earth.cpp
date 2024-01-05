// Fill out your copyright notice in the Description page of Project Settings.


#include "Earth.h"

AEarth::AEarth()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 5300.0f;
	SemiMinorAxis = 5000.0f;
	EllipseSpeed = 5.0f;
	CurrentAngle = 0.0f;

	FVector CurrentLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(CurrentLocation);
}

void AEarth::BeginPlay()
{
	Super::BeginPlay();
	FVector _Scale = FVector(3.2f, 3.2f, 3.2f);
	SetActorScale3D(_Scale);
}
void AEarth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate the box
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime ;
	SetActorRotation(NewRotation);

	CurrentAngle += EllipseSpeed * DeltaTime;
	float X = SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentAngle));
	float Y = SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentAngle));
	SetActorLocation(FVector(X, Y, GetActorLocation().Z));
}

