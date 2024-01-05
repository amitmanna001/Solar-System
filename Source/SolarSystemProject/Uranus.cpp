// Fill out your copyright notice in the Description page of Project Settings.


#include "Uranus.h"

// Sets default values
AUranus::AUranus()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 9500.0f;
	SemiMinorAxis = 9200.0f;
	EllipseSpeed = 5.0f;
	CurrentAngle = 0.0f;

	FVector CurrentLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(CurrentLocation);
}

// Called when the game starts or when spawned
void AUranus::BeginPlay()
{
	Super::BeginPlay();
	FVector _Scale = FVector(2.32f, 2.32f, 2.32f);
	SetActorScale3D(_Scale);
}

// Called every frame
void AUranus::Tick(float DeltaTime)
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

