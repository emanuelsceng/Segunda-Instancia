// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Nave : ModuleRules
{
	public Nave(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Nuestro permiso para usar C++ puro (dynamic_cast) en el Patrón State
        bUseRTTI = true;

        // ARREGLO: Agregamos "EnhancedInput" al final de la lista de dependencias
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
