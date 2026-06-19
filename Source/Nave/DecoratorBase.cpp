#include "DecoratorBase.h"

ADecoratorBase::ADecoratorBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PersonajeEnvuelto = nullptr;
}

float ADecoratorBase::GetVelocidadActual() const
{
	// Si hay un personaje envuelto, le preguntamos su velocidad original
	if (PersonajeEnvuelto != nullptr)
	{
		return PersonajeEnvuelto->GetVelocidadActual();
	}

	// Retorno de seguridad
	return 0.0f;
}