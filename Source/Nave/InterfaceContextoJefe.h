#pragma once
#include "CoreMinimal.h"

class NAVE_API InterfaceContextoJefe
{
public:
	virtual ~InterfaceContextoJefe() = default;
	virtual void CambiarEstado(class InterfaceStateJefe* NuevoEstado) = 0;
};