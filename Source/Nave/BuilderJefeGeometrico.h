#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceBuilderJefe.h"
#include "ProductoJefeFinal.h"
#include "BuilderJefeGeometrico.generated.h"

UCLASS()
class NAVE_API ABuilderJefeGeometrico : public AActor, public IInterfaceBuilderJefe
{
	GENERATED_BODY()

public:
	ABuilderJefeGeometrico();

	// Implementación del contrato de construcción
	virtual void IniciarConstruccion(FVector Ubicacion) override;
	virtual void ConstruirCuerpoBase() override;
	virtual void ConstruirEscalaGigante() override;
	virtual void ConstruirVelocidadBase() override;
	virtual AProductoJefeFinal* ObtenerJefe() override;

private:
	// Puntero al producto que se está ensamblando
	UPROPERTY()
	AProductoJefeFinal* JefeEnConstruccion;
};