// Copyright 2024, KampaiRaptor, All Rights Reserved.

#include "PrintUtils.h"
#include "BetterDebug_HUD.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"


// Print String
void UPrintUtils::BetterPrintString(const FString& DebugInfo, const FString& Debug, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	//Display or not
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
	{
		const FString DisplayString = DebugInfo + ": " + Debug;

		//Check if HUD is setup, print to it if yes
		if (WorldContext)
		{
			FString const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? FString::FromInt(static_cast<int32>(GetTypeHash(Key))): FString::FromInt(FDateTime::Now().GetTicks());
			
			if (const APlayerController* PlayerController = WorldContext->GetFirstPlayerController())
			{
				ABetterDebug_HUD* HUD = Cast<ABetterDebug_HUD>(PlayerController->GetHUD());
				if (HUD != nullptr)
				{
					FHUDMessage HUDMessage;
					HUDMessage.Message = DisplayString;
					HUDMessage.Color = Settings.Color.ToFColor(true);
					HUDMessage.Position = PositionOnHUD;
					HUDMessage.TimeToDisplay = Settings.DisplayTime;
					HUDMessage.TextScale = Settings.TextSize * Settings.TextSize*TextScaleMultiplayer; 
					HUDMessage.TimeRemaining = Settings.DisplayTime;
			
					HUD->AddMessage(TempKey, HUDMessage);
				}
			}
		}
		//Or print on regular screen
		else
		{
			int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;

			if (Settings.bViewport && bGlobalViewport)
			{
				GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
			}
		}
		
		//Print to LOG
		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}

void UPrintUtils::PrintBool(const FString& DebugInfo, const bool& Value, const FString& Key, const int DebugIndex,
	const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
	{
		const FString DisplayString = (Value == true) ? DebugInfo + " = True" : DebugInfo + " = False";
		//Setup key to 0, and change only when Key input is not "None"
		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}

		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}

// Print Float
void UPrintUtils::PrintFloat(const FString& DebugInfo, const float& Debug, const FString& Key, const bool bRoundFloat, const int DebugIndex, const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
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

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}

		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}

void UPrintUtils::PrintInt(const FString& DebugInfo, const int& Debug, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
	{
		const FString DisplayString = DebugInfo + " = " + FString::FromInt(Debug);
		
		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}

		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}

void UPrintUtils::PrintStringArray(const FString& DebugInfo, const TArray<FString>& Array, const FString& Key, const int DebugIndex,const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
	{
		FString DisplayString = "";
		for (int32 i = 0; i < Array.Num(); i++)
		{
			DisplayString += DebugInfo + " " + FString::FromInt(i) + ": " + Array[i] + + " \n";
		}
		DisplayString.RemoveFromEnd(" ");

		int32 const TempKey = !Key.Equals(TEXT("None"), ESearchCase::IgnoreCase) ? static_cast<int32>(GetTypeHash(Key)) : -1;

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}

		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}}
}

void UPrintUtils::PrintTransform(const FString& DebugInfo, const FTransform& Transform, const bool bLocation, const bool bRotation, const bool bScale, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
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

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}

		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}

void UPrintUtils::PrintVector(const FString& DebugInfo, const FVector& Vector, const bool bX, const bool bY, const bool bZ, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
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

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}
		
		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}

void UPrintUtils::PrintRotator(const FString& DebugInfo, const FRotator& Rotator, const bool bX_Roll, const bool bY_Pitch, const bool bZ_Yaw, const FString& Key, const int DebugIndex, const FPrintSetting Settings)
{
	if (UPrintUtils::BoolArray[FMath::Clamp(DebugIndex, 0, 4)]) //Lock to 4 categories for now
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

		if (Settings.bViewport && bGlobalViewport)
		{
			GEngine->AddOnScreenDebugMessage(TempKey, Settings.DisplayTime, Settings.Color.ToFColor(true), DisplayString, true, FVector2d(Settings.TextSize*TextScaleMultiplayer));
		}

		if (Settings.bLOG && bGlobalLOG)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *DisplayString);
		}
	}
}
