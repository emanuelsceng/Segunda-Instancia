#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceAbstractFactory.h"
#include "FactoryFamiliaCubos.generated.h"

UCLASS()
class NAVE_API AFactoryFamiliaCubos : public AActor, public IInterfaceAbstractFactory
{
	GENERATED_BODY()

public:
	AFactoryFamiliaCubos();

	// Implementación del Factory Method interno
	virtual class AActor* CrearSoldado(FVector Ubicacion) override;
	virtual class AActor* CrearElite(FVector Ubicacion) override;
};