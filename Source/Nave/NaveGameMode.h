// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveGameMode.generated.h"

UCLASS(minimalapi)
class ANaveGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANaveGameMode();
protected:
	virtual void BeginPlay() override;
};



