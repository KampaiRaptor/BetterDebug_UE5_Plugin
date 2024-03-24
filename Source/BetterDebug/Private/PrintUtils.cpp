// Fill out your copyright notice in the Description page of Project Settings.

#include "Misc/Variant.h"
#include "PrintUtils.h"


// Print String
void UPrintUtils::BetterPrintString(const FString& DebugInfo, const FString& Debug, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		const FString DisplayString = DebugInfo + ": " + Debug;

		//Setup key to 0, and change only when Key input is not "None"
		int32 const TempKey = (Key != "None") ? FCString::Atoi(*Key) : -1;
		
		//Print on screen
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize));
		//Print in Log
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

// Print Float
void UPrintUtils::PrintFloat(const FString& DebugInfo, const float& Debug, const FString& Key, const bool& bRoundFloat, const int DebugIndex, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		//Round or not
		FString DisplayString = "";
		if (bRoundFloat == true)
		{
			DisplayString = DebugInfo + " = " + FString::SanitizeFloat(FMath::RoundToFloat(Debug));
		}
		else
		{
			DisplayString = FString::Printf(TEXT("%s = %.2f"), *DebugInfo, Debug);
		}
		
		//Setup key to 0, and change only when Key input is not "None"
		int32 const TempKey = (Key != "None") ? FCString::Atoi(*Key) : -1;
		
		//Print on screen
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize));
		//Print in log
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

//TODO debug key + conditions when to print
void UPrintUtils::PrintStringArray(const FString& DebugInfo, const TArray<FString>& Array, const FString& Key, const int DebugIndex,const FPrintSetting Settings)
{
	FString DisplayString = "";
	for (int32 i = 0; i < Array.Num(); i++)
	{
		DisplayString += DebugInfo + " " + FString::FromInt(i) + ": " + Array[i] + + " \n";
	}
	//DisplayString = DebugInfo + ": " + DisplayString;
	DisplayString.RemoveFromEnd(" ");

	int32 const TempKey = (Key != "None") ? FCString::Atoi(*Key) : -1;
	
	GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize));
}
