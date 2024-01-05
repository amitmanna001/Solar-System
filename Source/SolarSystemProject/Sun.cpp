// Fill out your copyright notice in the Description page of Project Settings.

#include "Sun.h"


ASun::ASun()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASun::BeginPlay()
{
	Super::BeginPlay();
}

void ASun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector SunScale = FVector(10.0f, 10.0f, 10.0f);
	RootComponent->SetWorldScale3D(SunScale);
}

