#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceEnemigoSoldado.h"
#include "SoldadoCubo.generated.h"

UCLASS()
class NAVE_API ASoldadoCubo : public AActor, public IInterfaceEnemigoSoldado
{
	GENERATED_BODY()

public:
	ASoldadoCubo();
	virtual void TareaDeSoldado() override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaCuerpo;
};