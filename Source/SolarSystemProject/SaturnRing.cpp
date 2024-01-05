// Fill out your copyright notice in the Description page of Project Settings.


#include "SaturnRing.h"

// Sets default values
ASaturnRing::ASaturnRing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;
	RotationSpeed = 60.0f;
	// Movement
	SemiMajorAxis = 8000.0f;
	SemiMinorAxis = 7700.0f;
	EllipseSpeed = -7.0f;
	CurrentAngle = 0.0f;

	FVector Location = FVector(0.1f, 0.1f, 0.1f);
	SetActorLocation(Location);
}

// Called when the game starts or when spawned
void ASaturnRing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASaturnRing::Tick(float DeltaTime)
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

