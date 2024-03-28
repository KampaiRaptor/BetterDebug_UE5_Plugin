// Copyright 2024, KampaiRaptor, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
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

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WidgetDebugUtils")
	TArray<bool>& GetBoolArrayFromPrintUtils() const;

	UFUNCTION(BlueprintCallable, Category= "WidgetDebugUtils")
	bool SetBoolInArray(bool Value, int32 Index);

	UFUNCTION(BlueprintCallable, Category= "WidgetDebugUtils")
	void SetTextScaleMultiplayer(float NewValue);
	

};
