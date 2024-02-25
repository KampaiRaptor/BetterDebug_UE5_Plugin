// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintUtils.h"

void UPrintUtils::BetterPrintString(const FString DebugInfo, const FString Debug, const FLinearColor Color, const int Key, const float DisplayTime, const bool bShouldDisplay)
{
	if (bShouldDisplay)
	{
		const FString DisplayString = DebugInfo + ": " + Debug;
		const FColor DisplayColor = Color.ToFColor(true); 
		GEngine->AddOnScreenDebugMessage(Key, DisplayTime, DisplayColor, DisplayString);
	}
}