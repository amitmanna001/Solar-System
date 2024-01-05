// Fill out your copyright notice in the Description page of Project Settings.


#include "Mercury.h"

AMercury::AMercury()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 4300.0f;
	SemiMinorAxis = 4000.0f;
	EllipseSpeed = 20.0f;
	CurrentAngle = 0.0f;

	FVector MercuryLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(MercuryLocation);
}
void AMercury::BeginPlay()
{
	Super::BeginPlay();

	FVector Sca = FVector(2.5f, 2.5f, 2.5f);
	SetActorScale3D(Sca);
}
void AMercury::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(NewRotation);

	CurrentAngle += EllipseSpeed * DeltaTime;
	float X = SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentAngle));
	float Y = SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentAngle));
	SetActorLocation(FVector(X, Y, GetActorLocation().Z));
	
}

