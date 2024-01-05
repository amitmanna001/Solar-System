// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Earth.generated.h"

UCLASS(config=Game)
class SOLARSYSTEMPROJECT_API AEarth : public AActor
{
	GENERATED_BODY()
	
public:	
	AEarth();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override; 

	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	float SemiMajorAxis;
	float SemiMinorAxis;
	UPROPERTY(config)
	float EllipseSpeed;
	float CurrentAngle;
};
