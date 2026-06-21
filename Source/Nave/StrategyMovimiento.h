#pragma once
#include "CoreMinimal.h"

class NAVE_API StrategyMovimiento
{
public:
	virtual ~StrategyMovimiento() = default;
	virtual void EjecutarMovimiento(class AActor* Contexto, float DeltaTime) = 0;
};