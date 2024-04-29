// Fill out your copyright notice in the Description page of Project Settings.


#include "BetterDebug_HUD.h"
#include "PrintUtils.h"

ABetterDebug_HUD::ABetterDebug_HUD()
{
	UPrintUtils::WorldContext = GetWorld();
}
ABetterDebug_HUD::~ABetterDebug_HUD()
{
	UPrintUtils::WorldContext = nullptr;
}

void ABetterDebug_HUD::DrawHUD()
{
	Super::DrawHUD();
	
	float DeltaTime = GetWorld()->GetDeltaSeconds();

	for (auto It = Messages.CreateIterator(); It; ++It)
	{
		FHUDMessage& Message = It.Value();
		Message.TimeRemaining -= DeltaTime;

		if (Message.TimeRemaining <= 0)
		{
			It.RemoveCurrent();
		}
		else
		{
			DrawText(Message.Message, Message.Color, Message.Position.X, Message.Position.Y, GEngine->GetSmallFont(), Message.TextScale, true);
		}
	}
}

void ABetterDebug_HUD::AddMessage(const FString& Key, FHUDMessage Message)
{
	Message.TimeRemaining = Message.TimeToDisplay;
	Messages.Add(Key, Message);
}

void ABetterDebug_HUD::RemoveMessageByKey(const FString& Key)
{
	Messages.Remove(Key);
}
