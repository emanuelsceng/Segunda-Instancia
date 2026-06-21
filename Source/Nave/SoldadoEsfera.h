#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceEnemigoSoldado.h"
#include "StrategyMovimiento.h"
#include "InterfacePublicador.h"
#include "SoldadoEsfera.generated.h"

UCLASS()
class NAVE_API ASoldadoEsfera : public AActor, public IInterfaceEnemigoSoldado, public InterfacePublicador
{
	GENERATED_BODY()
public:
	ASoldadoEsfera();
	virtual void TareaDeSoldado() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* MallaCuerpo;

public:
	// --- PATRÓN STRATEGY ---
	StrategyMovimiento* EstrategiaActual;
	void CambiarEstrategia(StrategyMovimiento* NuevaEstrategia);

	FTimerHandle TimerCambioEstrategia;
	void ActivarPersecucion();

	// --- PATRÓN OBSERVER ---
	InterfaceSuscriptor* GestorOleadas;
	virtual void Suscribir(InterfaceSuscriptor* Suscriptor) override;
	virtual void Desuscribir(InterfaceSuscriptor* Suscriptor) override;
	virtual void NotificarMuerte() override;
};