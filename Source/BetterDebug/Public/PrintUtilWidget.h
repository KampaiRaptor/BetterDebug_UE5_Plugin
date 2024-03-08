// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "PrintUtils.h"
#include "PrintUtilWidget.generated.h"

/**
 * 
 */

class UPrintUtils;

UCLASS()
class BETTERDEBUG_API UPrintUtilWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	UPrintUtilWidget();
	~UPrintUtilWidget();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YourCategory")
	TArray<bool>& GetBoolArrayFromPrintUtils();

};
