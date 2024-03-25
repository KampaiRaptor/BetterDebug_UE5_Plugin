// Fill out your copyright notice in the Description page of Project Settings.


#include "BetterDebugTimerActor.h"

// Sets default values
ABetterDebugTimerActor::ABetterDebugTimerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrintUtils = NewObject<UPrintUtils>(); // Create an instance of PrintUtils


}

// Called when the game starts or when spawned
void ABetterDebugTimerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

//This is actually really stupid... Probably delete everything

void ABetterDebugTimerActor::StartTimer(float TimerInterval, const FString& DebugInfo, const FString& Debug,
	const FString& Key, int DebugIndex, bool bIsConstant, const FPrintSetting& Settings)
{

	
	PrintUtils->BetterPrintString(DebugInfo, Debug, Key, DebugIndex, false, Settings);

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, 
	 [this, TimerInterval, DebugInfo, Debug, Key, DebugIndex, bIsConstant, Settings]() {
		 this->StartTimer(TimerInterval, DebugInfo, Debug, Key, DebugIndex, bIsConstant, Settings);
	 }, 0.1, false);
}

// Called every frame
void ABetterDebugTimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

