#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceSuscriptor.h"
#include "ObserverGestorOleadas.generated.h"

UCLASS()
class NAVE_API AObserverGestorOleadas : public AActor, public InterfaceSuscriptor
{
	GENERATED_BODY()
public:
	AObserverGestorOleadas();
	virtual void Actualizar(class AActor* EnemigoQueMurio) override;
	void GenerarNuevaOleada();

protected:
	virtual void BeginPlay() override;

private:
	int32 EnemigosRestantes;
	int32 NumeroOleadaActual;
};