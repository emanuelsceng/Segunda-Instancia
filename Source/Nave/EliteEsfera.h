#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceEnemigoElite.h"
#include "EliteEsfera.generated.h"

UCLASS()
class NAVE_API AEliteEsfera : public AActor, public IInterfaceEnemigoElite
{
	GENERATED_BODY()

public:
	AEliteEsfera();

	// Cumplimos con el contrato de la interfaz Elite
	virtual void HabilidadDeElite() override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaCuerpo;
};