#include "FactoryFamiliaCubos.h"
#include "SoldadoCubo.h"
#include "EliteCubo.h"

AFactoryFamiliaCubos::AFactoryFamiliaCubos()
{
	PrimaryActorTick.bCanEverTick = false; // Las fábricas no necesitan Tick
}

AActor* AFactoryFamiliaCubos::CrearSoldado(FVector Ubicacion)
{
	// Spawneamos el producto concreto de esta familia
	ASoldadoCubo* NuevoSoldado = GetWorld()->SpawnActor<ASoldadoCubo>(ASoldadoCubo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	return NuevoSoldado;
}

AActor* AFactoryFamiliaCubos::CrearElite(FVector Ubicacion)
{
	AEliteCubo* NuevoElite = GetWorld()->SpawnActor<AEliteCubo>(AEliteCubo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	return NuevoElite;
}