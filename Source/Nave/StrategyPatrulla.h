#pragma once
#include "StrategyMovimiento.h"

class NAVE_API StrategyPatrulla : public StrategyMovimiento
{
public:
	virtual void EjecutarMovimiento(class AActor* Contexto, float DeltaTime) override;
};