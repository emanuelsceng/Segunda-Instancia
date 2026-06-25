#include "FactoryFamiliaEsferas.h"
#include "SoldadoEsfera.h"
#include "EliteEsfera.h"

AFactoryFamiliaEsferas::AFactoryFamiliaEsferas()
{
	PrimaryActorTick.bCanEverTick = false; 
}

AActor* AFactoryFamiliaEsferas::CrearSoldado(FVector Ubicacion)
{
	// Spawneamos el producto concreto de esta familia (Soldado Esfera)
	ASoldadoEsfera* NuevoSoldado = GetWorld()->SpawnActor<ASoldadoEsfera>(ASoldadoEsfera::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	return NuevoSoldado;
}

AActor* AFactoryFamiliaEsferas::CrearElite(FVector Ubicacion)
{
	// Spawneamos el producto concreto de esta familia (Élite Esfera)
	AEliteEsfera* NuevoElite = GetWorld()->SpawnActor<AEliteEsfera>(AEliteEsfera::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	return NuevoElite;
}