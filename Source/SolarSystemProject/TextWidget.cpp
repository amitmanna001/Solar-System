// Fill out your copyright notice in the Description page of Project Settings.


#include "TextWidget.h"
#include "Components/TextBlock.h"

void UTextWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTextWidget::SetMassText(const FText& MassValue)
{
	{
		if (MassTextBlock)
		{
			MassTextBlock->SetText(MassValue);
		}
	}
}

void UTextWidget::SetVelocityText(const FText& VelocityValue)
{
	{
		if (VelocityTextBlock)
		{
			VelocityTextBlock->SetText(VelocityValue);
		}
	}
}

void UTextWidget::SetDiameterText(const FText& DiameterValue)
{
	UTextBlock* DiameterTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DiameterText")));
	if (DiameterTextBlock)
	{
		DiameterTextBlock->SetText(DiameterValue);
	}
}

void UTextWidget::SetDistanceText(const FText& DistanceValue)
{
	UTextBlock* DistanceTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DistanceText")));
	if(DistanceTextBlock)
	{
		DistanceTextBlock->SetText(DistanceValue);
	}
}
