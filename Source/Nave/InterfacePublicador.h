#pragma once
#include "CoreMinimal.h"

class NAVE_API InterfacePublicador
{
public:
	virtual ~InterfacePublicador() = default;
	virtual void Suscribir(class InterfaceSuscriptor* Suscriptor) = 0;
	virtual void Desuscribir(class InterfaceSuscriptor* Suscriptor) = 0;
	virtual void NotificarMuerte() = 0;
};