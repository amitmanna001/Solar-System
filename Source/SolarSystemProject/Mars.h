// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mars.generated.h"

UCLASS(config=Game)
class SOLARSYSTEMPROJECT_API AMars : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMars();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float RotationSpeed;
	UPROPERTY(EditAnyWhere)
	float CurrentAngle;
	float SemiMajorAxis;
	float SemiMinorAxis;
	UPROPERTY(config)
	float EllipseSpeed;
};
