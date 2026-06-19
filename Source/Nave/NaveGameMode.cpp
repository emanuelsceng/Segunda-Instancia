// Copyright Epic Games, Inc. All Rights Reserved.

#include "NaveGameMode.h"
#include "NaveCharacter.h"
#include "FacadeMenuPrincipal.h"
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
void ANaveGameMode::BeginPlay()
{
	Super::BeginPlay();

	// El GameMode actúa como Cliente del Façade
	AFacadeMenuPrincipal* MiFachada = GetWorld()->SpawnActor<AFacadeMenuPrincipal>(AFacadeMenuPrincipal::StaticClass());

	if (MiFachada)
	{
		// Disparamos toda la orquestación
		MiFachada->IniciarJuego();
	}
}