#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecoratorMoverPersonaje.h"
#include "DecoratorBase.generated.h"

UCLASS(Abstract) // Abstracta porque es solo la base estructural
class NAVE_API ADecoratorBase : public AActor, public IDecoratorMoverPersonaje
{
	GENERATED_BODY()

public:
	ADecoratorBase();

	// El puntero que guarda al objeto que estamos decorando
	IDecoratorMoverPersonaje* PersonajeEnvuelto;

	// Función que pasa la llamada al objeto envuelto
	virtual float GetVelocidadActual() const override;
};