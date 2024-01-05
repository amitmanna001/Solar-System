// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Venus.generated.h"

UCLASS(config=Game)
class SOLARSYSTEMPROJECT_API AVenus : public AActor
{
	GENERATED_BODY()
	
public:	
	AVenus();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	float SemiMajorAxis;
	float SemiMinorAxis;
	UPROPERTY(config)
	float EllipseSpeed;
	float CurrentAngle;

};
