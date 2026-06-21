#pragma once
#include "CoreMinimal.h"

class NAVE_API InterfaceStateJefe
{
public:
	virtual ~InterfaceStateJefe() = default;
	virtual void EjecutarComportamiento(class AActor* JefeContexto, float DeltaTime) = 0;
};