#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeMenuPrincipal.generated.h"

UCLASS()
class NAVE_API AFacadeMenuPrincipal : public AActor
{
	GENERATED_BODY()

public:
	AFacadeMenuPrincipal();

	// El método central que oculta toda la complejidad de los subsistemas
	UFUNCTION(BlueprintCallable, Category = "Orquestador")
	void IniciarJuego();

protected:
	virtual void BeginPlay() override;
};