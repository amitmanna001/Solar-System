// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "NeptuneOrbit.generated.h"

UCLASS()
class SOLARSYSTEMPROJECT_API ANeptuneOrbit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANeptuneOrbit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProceduralMeshComponent;

	void GenerateHollowEllipseMesh();
};
