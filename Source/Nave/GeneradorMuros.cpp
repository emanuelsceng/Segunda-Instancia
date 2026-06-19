#include "GeneradorMuros.h"
#include "ObstaculoMuro.h"

AObstaculoBase* AGeneradorMuros::FabricarObstaculo(FVector Ubicacion)
{
	// Instanciamos el producto concreto (ObstaculoMuro) en el mundo
	AObstaculoMuro* NuevoMuro = GetWorld()->SpawnActor<AObstaculoMuro>(AObstaculoMuro::StaticClass(), Ubicacion, FRotator::ZeroRotator);

	if (NuevoMuro)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Generador Muros: Nuevo muro fabricado en el nivel."));
	}

	return NuevoMuro;
}