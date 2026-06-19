#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceEnemigoElite.h"
#include "EliteCubo.generated.h"

UCLASS()
class NAVE_API AEliteCubo : public AActor, public IInterfaceEnemigoElite
{
	GENERATED_BODY()

public:
	AEliteCubo();

	// Cumplimos con el contrato de la interfaz Elite
	virtual void HabilidadDeElite() override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaCuerpo;
};