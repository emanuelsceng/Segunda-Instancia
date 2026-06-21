#pragma once
#include "InterfaceStateJefe.h"

class NAVE_API StateJefeMuerto : public InterfaceStateJefe
{
public:
	virtual void EjecutarComportamiento(class AActor* JefeContexto, float DeltaTime) override;
};