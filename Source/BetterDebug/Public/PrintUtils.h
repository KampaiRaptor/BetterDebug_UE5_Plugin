// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PrintUtils.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPrintSetting
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	FLinearColor Color = FLinearColor::Red;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	float DisplayTime = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	bool bShouldDisplay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	float TextSize = 1.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	int DebugIndex;
};

UCLASS()
class BETTERDEBUG_API UPrintUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category="Debug")
	static void BetterPrintString(const FString DebugInfo, const FString Debug, const FString Key = "None", const FPrintSetting Settings = FPrintSetting());

	UFUNCTION(BlueprintCallable, Category="Debug")
	static void PrintFloat(const FString DebugInfo, const float Debug, const FString Key = "None", const bool bRoundFloat = false, const FPrintSetting Settings = FPrintSetting());

	UFUNCTION(BlueprintCallable, Category="Debug")
	static void PrintStringArray(const FString DebugInfo, const TArray<FString> Array, const FString Key = "None", const FPrintSetting Settings = FPrintSetting());

	
public:
	static inline TArray<bool> BoolArray{true, false}; 
};
