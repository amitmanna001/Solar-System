// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "TextWidget.generated.h"

/**
 * 
 */
class UTextBlock;
UCLASS()
class SOLARSYSTEMPROJECT_API UTextWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MassTextBlock;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* VelocityTextBlock;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Planets widget")
	void SetMassText(const FText& MassValue);

	UFUNCTION(BlueprintCallable, Category = "Planets widget")
	void SetVelocityText(const FText& VelocityValue);

	UFUNCTION(BlueprintCallable, Category = "Planets widget")
	void SetDiameterText(const FText& DiameterValue);

	UFUNCTION(BlueprintCallable, Category = "Planets widget")
	void SetDistanceText(const FText& DistanceValue);

};
