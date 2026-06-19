#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DecoratorMoverPersonaje.generated.h"

// Esta clase es solo para el sistema de reflexión de Unreal, no la toques.
UINTERFACE(MinimalAPI)
class UDecoratorMoverPersonaje : public UInterface
{
	GENERATED_BODY()
};

// Esta es la interfaz real que vamos a usar en C++
class NAVE_API IDecoratorMoverPersonaje
{
	GENERATED_BODY()

public:
	// Función pura que el Character y el Decorator van a compartir
	virtual float GetVelocidadActual() const = 0;
};