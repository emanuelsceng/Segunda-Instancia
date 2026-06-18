// Copyright Epic Games, Inc. All Rights Reserved.

#include "NaveGameMode.h"
#include "NaveCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANaveGameMode::ANaveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
