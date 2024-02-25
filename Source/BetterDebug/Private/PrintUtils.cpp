// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintUtils.h"

void UPrintUtils::BetterPrintString(const FString DebugInfo, const FString Debug, const FString Key, const FPrintSetting& Settings)
{
	if (Settings.bShouldDisplay)
	{
		const FString DisplayString = DebugInfo + ": " + Debug;
		const FColor DisplayColor = Settings.Color.ToFColor(true);

		//Setup key to 0, and change only when Key input is not "None"
		int32 TempKey = -1;
		if (Key != "None")
		{
			TempKey = FCString::Atoi(*Key);
		}
		
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, DisplayColor, DisplayString, true, FVector2d(Settings.TextSize));

		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}