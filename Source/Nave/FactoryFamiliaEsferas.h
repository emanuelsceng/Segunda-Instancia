#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceAbstractFactory.h"
#include "FactoryFamiliaEsferas.generated.h"

UCLASS()
class NAVE_API AFactoryFamiliaEsferas : public AActor, public IInterfaceAbstractFactory
{
	GENERATED_BODY()

public:
	AFactoryFamiliaEsferas();

	// Implementación del Factory Method interno para la familia de Esferas
	virtual class AActor* CrearSoldado(FVector Ubicacion) override;
	virtual class AActor* CrearElite(FVector Ubicacion) override;
};