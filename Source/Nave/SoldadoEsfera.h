#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceEnemigoSoldado.h"
#include "SoldadoEsfera.generated.h"

UCLASS()
class NAVE_API ASoldadoEsfera : public AActor, public IInterfaceEnemigoSoldado
{
	GENERATED_BODY()

public:
	ASoldadoEsfera();

	// Cumplimos con el contrato de la interfaz Soldado
	virtual void TareaDeSoldado() override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaCuerpo;
};