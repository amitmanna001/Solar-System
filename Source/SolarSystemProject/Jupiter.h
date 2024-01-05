// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Jupiter.generated.h"

UCLASS(config=Game)
class SOLARSYSTEMPROJECT_API AJupiter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJupiter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
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
