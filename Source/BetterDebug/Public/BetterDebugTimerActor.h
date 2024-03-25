// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrintUtils.h"
#include "BetterDebugTimerActor.generated.h"

UCLASS()
class BETTERDEBUG_API ABetterDebugTimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABetterDebugTimerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPrintUtils* PrintUtils;
	void StartTimer(float TimerInterval, const FString& DebugInfo, const FString& Debug, const FString& Key, int DebugIndex, bool bIsConstant, const FPrintSetting& Settings);

};
