// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PrintUtils.generated.h"

/**
 * 
 */
UCLASS()
class BETTERDEBUG_API UPrintUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category="Debug")
	static void BetterPrintString(const FString DebugInfo, const FString Debug, const FLinearColor Color = FLinearColor::Red, const int Key = -1, const float DisplayTime = 2.0f,const bool bShouldDisplay = true);
	

};
