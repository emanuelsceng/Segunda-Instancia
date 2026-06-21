#pragma once
#include "CoreMinimal.h"

class NAVE_API InterfaceSuscriptor
{
public:
	virtual ~InterfaceSuscriptor() = default;
	virtual void Actualizar(class AActor* EnemigoQueMurio) = 0;
};