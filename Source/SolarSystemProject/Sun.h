// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sun.generated.h"

UCLASS()
class SOLARSYSTEMPROJECT_API ASun : public AActor
{
	GENERATED_BODY()
	
public:	
	ASun();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
