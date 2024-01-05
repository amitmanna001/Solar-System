// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "TextWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
class UTextWidget;
class UInputMappingContext;
class UInputAction;
UCLASS()
class SOLARSYSTEMPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	AMyPlayerController();

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<class UUserWidget> WidgetClass;
	UTextWidget* WidgetInstance;

	/** Mapping context used for pawn control. */
	UPROPERTY()
	UInputMappingContext* PawnMappingContext;

	/** Action to update location */
	UPROPERTY()
	UInputAction* MoveAction;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowWidget(FString mass, FString velocity, FString diameter, double distance);
	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideWidget();

	UFUNCTION()
	void performRaycast();
	UFUNCTION()
	void performRaycastHide();

	AActor* HitActor;
};
