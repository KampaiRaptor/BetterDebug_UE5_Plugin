// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintUtils.h"

void UPrintUtils::BetterPrintString(const FString DebugInfo, const FString Debug, const FString Key, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && bCategory_1 == true)
	{
		const FString DisplayString = DebugInfo + ": " + Debug;
		const FColor DisplayColor = Settings.Color.ToFColor(true);

		//Setup key to 0, and change only when Key input is not "None"
		int32 TempKey = -1;
		if (Key != "None")
		{
			TempKey = FCString::Atoi(*Key);
		}
		
		//Print on screen
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, DisplayColor, DisplayString, true, FVector2d(Settings.TextSize));
		//Print in Log
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

void UPrintUtils::PrintFloat(const FString DebugInfo, const float Debug, const FString Key, const bool bRoundFloat, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && bCategory_1 == true)
	{
		//Round or not
		FString DisplayString = "";
		if (bRoundFloat == true)
		{
			DisplayString = DebugInfo + ": " +  FString::SanitizeFloat(FMath::RoundToFloat(Debug));
		}
		else
		{
			DisplayString = FString::Printf(TEXT("%s:%.2f"), *DebugInfo, Debug);
		}
		
		const FColor DisplayColor = Settings.Color.ToFColor(true);

		//Setup key to 0, and change only when Key input is not "None"
		int32 TempKey = -1;
		if (Key != "None")
		{
			TempKey = FCString::Atoi(*Key);
		}

		//Print on screen
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, DisplayColor, DisplayString, true, FVector2d(Settings.TextSize));
		//Print in log
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}
