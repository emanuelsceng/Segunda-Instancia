#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceBuilderJefe.generated.h"

UINTERFACE(MinimalAPI)
class UInterfaceBuilderJefe : public UInterface
{
	GENERATED_BODY()
};

class NAVE_API IInterfaceBuilderJefe
{
	GENERATED_BODY()

public:
	// Los pasos puros del ensamblaje del Jefe
	virtual void IniciarConstruccion(FVector Ubicacion) = 0;
	virtual void ConstruirCuerpoBase() = 0;
	virtual void ConstruirEscalaGigante() = 0;
	virtual void ConstruirVelocidadBase() = 0;

	// Método para obtener el producto terminado
	virtual class AProductoJefeFinal* ObtenerJefe() = 0;
};