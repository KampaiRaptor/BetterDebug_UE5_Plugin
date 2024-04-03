// Copyright 2024, KampaiRaptor, All Rights Reserved.

using UnrealBuildTool;

public class BetterDebug : ModuleRules
{
	public BetterDebug(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
		);
                
        
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
		);
            
        
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
				// ... add other public dependencies that you statically link with here ...
			}
		);
            
        
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG"
			}
		);

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Blutility" // Editor-only module
					// Add other editor-only dependencies here
				}
			);
		}
        
        
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
		
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Blutility" // Editor-only module
					// Add other editor-only dependencies here
				}
			);
		}

		// Define WITH_EDITOR_WIDGET based on whether the target platform is Android
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicDefinitions.Add("WITH_EDITOR_WIDGET=0");
		}
		else
		{
			PublicDefinitions.Add("WITH_EDITOR_WIDGET=1");
		}
	}
}