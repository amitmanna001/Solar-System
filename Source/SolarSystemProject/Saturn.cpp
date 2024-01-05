// Fill out your copyright notice in the Description page of Project Settings.


#include "Saturn.h"

// Sets default values
ASaturn::ASaturn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 8000.0f;
	SemiMinorAxis = 7700.0f;
	EllipseSpeed = 10.0f;
	CurrentAngle = 0.0f;

	FVector CurrentLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(CurrentLocation);
}

// Called when the game starts or when spawned
void ASaturn::BeginPlay()
{
	Super::BeginPlay();
	FVector _Scale = FVector(5.8f, 5.8f, 5.8f);
	SetActorScale3D(_Scale);
}

// Called every frame
void ASaturn::Tick(float DeltaTime)
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

