// Copyright 2024, KampaiRaptor, All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FBetterDebugModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
