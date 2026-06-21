#pragma once
#include "InterfaceStateJefe.h"

class NAVE_API StateJefePersiguiendo : public InterfaceStateJefe
{
private:
	float TiempoPersiguiendo = 0.0f;
public:
	virtual void EjecutarComportamiento(class AActor* JefeContexto, float DeltaTime) override;
};