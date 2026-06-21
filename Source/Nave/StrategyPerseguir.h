#pragma once
#include "StrategyMovimiento.h"

class NAVE_API StrategyPerseguir : public StrategyMovimiento
{
private:
	FVector DestinoMemorizado;
	bool bDestinoFijado = false;

public:
	virtual void EjecutarMovimiento(class AActor* Contexto, float DeltaTime) override;
};