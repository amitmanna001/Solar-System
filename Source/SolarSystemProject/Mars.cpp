// Fill out your copyright notice in the Description page of Project Settings.


#include "Mars.h"

// Sets default values
AMars::AMars()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 5800.0f;
	SemiMinorAxis = 5500.0f;
	EllipseSpeed = 15.0f;
	CurrentAngle = 0.0f;

	FVector CurrentLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(CurrentLocation);
}

// Called when the game starts or when spawned
void AMars::BeginPlay()
{
	Super::BeginPlay();
	FVector _Scale = FVector(2.7f,2.7f,2.7f);
	SetActorScale3D(_Scale);
}

// Called every frame
void AMars::Tick(float DeltaTime)
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

