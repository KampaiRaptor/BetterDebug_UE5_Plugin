// Copyright 2024, KampaiRaptor, All Rights Reserved.


#include "PrintUtils.h"

// Print String
void UPrintUtils::BetterPrintString(const FString& DebugInfo, const FString& Debug, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	//Display or not
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		const FString DisplayString = DebugInfo + ": " + Debug;

		//Setup key to 0, and change only when Key input is not "None"
		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;

		//Print on screen
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		//Print in Log
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

void UPrintUtils::PrintBool(const FString& DebugInfo, const bool& Value, const FString& Key, const int DebugIndex,
	const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		const FString DisplayString = (Value == true) ? DebugInfo + " = True" : DebugInfo + " = False";
		//Setup key to 0, and change only when Key input is not "None"
		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
		
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

// Print Float
void UPrintUtils::PrintFloat(const FString& DebugInfo, const float& Debug, const FString& Key, const bool bRoundFloat, const int DebugIndex, const FPrintSetting Settings)
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
		
		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
		
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

void UPrintUtils::PrintInt(const FString& DebugInfo, const int& Debug, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		const FString DisplayString = DebugInfo + " = " + FString::FromInt(Debug);
		
		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
		
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

void UPrintUtils::PrintStringArray(const FString& DebugInfo, const TArray<FString>& Array, const FString& Key, const int DebugIndex,const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		FString DisplayString = "";
		for (int32 i = 0; i < Array.Num(); i++)
		{
			DisplayString += DebugInfo + " " + FString::FromInt(i) + ": " + Array[i] + + " \n";
		}
		DisplayString.RemoveFromEnd(" ");

		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
	
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
	}
}

void UPrintUtils::PrintTransform(const FString& DebugInfo, const FTransform& Transform, const bool bLocation, const bool bRotation, const bool bScale, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		//Setup base string
		FString DisplayString = DebugInfo + ": \n";

		//Choose which variables to print
		if (bLocation == true)
		{
			DisplayString += "Location: " + Transform.GetLocation().ToString() + " \n"; 
		}
		if (bRotation == true)
		{
			DisplayString += "Rotation: " + Transform.GetRotation().Euler().ToString() + " \n";
		}
		if (bScale == true)
		{
			DisplayString += "Scale: " + Transform.GetScale3D().ToString();
		}
		DisplayString.RemoveFromEnd(" ");

		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
	
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

void UPrintUtils::PrintVector(const FString& DebugInfo, const FVector& Vector, const bool bX, const bool bY, const bool bZ, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		FString DisplayString = DebugInfo + ":";

		if (bX == true)
		{
			DisplayString += " X: " + FString::SanitizeFloat((FMath::RoundToFloat(Vector.X)));
		}
		if (bY == true)
		{
			DisplayString += " Y: " + FString::SanitizeFloat((FMath::RoundToFloat(Vector.Y)));
		}
		if (bZ == true)
		{
			DisplayString += " Z: " + FString::SanitizeFloat((FMath::RoundToFloat(Vector.Z)));
		}
		DisplayString.RemoveFromEnd(" ");

		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
	
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}

void UPrintUtils::PrintRotator(const FString& DebugInfo, const FRotator& Rotator, const bool bX_Roll, const bool bY_Pitch, const bool bZ_Yaw, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (Settings.bShouldDisplay && UPrintUtils::BoolArray[DebugIndex])
	{
		FString DisplayString = DebugInfo + ":";

		if (bX_Roll == true)
		{
			DisplayString += " X (Roll): " + FString::SanitizeFloat(Rotator.Roll);
		}
		if (bY_Pitch == true)
		{
			DisplayString += " Y (Pitch): " + FString::SanitizeFloat(Rotator.Pitch);
		}
		if (bZ_Yaw == true)
		{
			DisplayString += " Z (Yaw): " + FString::SanitizeFloat(Rotator.Yaw);
		}
		DisplayString.RemoveFromEnd(" ");

		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;
	
		GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
	}
}
