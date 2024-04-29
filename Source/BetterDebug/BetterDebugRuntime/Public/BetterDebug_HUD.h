// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BetterDebug_HUD.generated.h"

USTRUCT()
struct FHUDMessage
{
	GENERATED_BODY()

	FString Message;
	FColor Color;
	FVector2D Position;
	float TimeToDisplay;
	float TextScale;
	float TimeRemaining;
};

UCLASS()
class BETTERDEBUGRUNTIME_API ABetterDebug_HUD : public AHUD
{
	GENERATED_BODY()

public:
	ABetterDebug_HUD();
	virtual ~ABetterDebug_HUD() override;
	virtual void DrawHUD() override;
	
	TMap<FString, FHUDMessage> Messages;

	void AddMessage(const FString& Key, FHUDMessage Message);
	void RemoveMessageByKey(const FString& Key);
	
};
