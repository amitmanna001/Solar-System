// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "EarthOrbit.generated.h"

UCLASS() 
class SOLARSYSTEMPROJECT_API AEarthOrbit : public AActor
{
	GENERATED_BODY()
	
public:	
	AEarthOrbit();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProceduralMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GenerateHollowEllipseMesh();

};
