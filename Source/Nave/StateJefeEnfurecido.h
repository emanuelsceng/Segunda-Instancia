#pragma once
#include "InterfaceStateJefe.h"

class NAVE_API StateJefeEnfurecido : public InterfaceStateJefe
{
private:
	float TiempoEnfurecido = 0.0f;
public:
	virtual void EjecutarComportamiento(class AActor* JefeContexto, float DeltaTime) override;
};