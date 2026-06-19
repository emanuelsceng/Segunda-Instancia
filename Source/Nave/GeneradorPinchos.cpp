#include "GeneradorPinchos.h"
#include "ObstaculoPincho.h"

AObstaculoBase* AGeneradorPinchos::FabricarObstaculo(FVector Ubicacion)
{
	// Instanciamos el producto concreto (ObstaculoPincho) en el mundo
	AObstaculoPincho* NuevoPincho = GetWorld()->SpawnActor<AObstaculoPincho>(AObstaculoPincho::StaticClass(), Ubicacion, FRotator::ZeroRotator);

	if (NuevoPincho)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Generador Pinchos: Nuevo pincho fabricado en el nivel."));
	}

	return NuevoPincho;
}