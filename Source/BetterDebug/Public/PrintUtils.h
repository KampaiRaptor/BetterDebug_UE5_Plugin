// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PrintUtils.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EDebugTypes : uint8
{
	Type1 UMETA(DisplayName = "Category 1"),
	Type2 UMETA(DisplayName = "Category 2"),
	Type3 UMETA(DisplayName = "Category 3"),
	Type4 UMETA(DisplayName = "Category 4"),
	Type5 UMETA(DisplayName = "Category 5"),
};

USTRUCT(BlueprintType)
struct FPrintSetting
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	FLinearColor Color = FLinearColor::Red;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	float DisplayTime = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	bool bShouldDisplay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	float TextSize = 1.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrintSetting")
	EDebugTypes DebugType;
};

UCLASS()
class BETTERDEBUG_API UPrintUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category="Debug")
	static void BetterPrintString(const FString DebugInfo, const FString Debug, const FString Key = "None", const FPrintSetting& Settings = FPrintSetting());
};
