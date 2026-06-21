#include "StateJefePersiguiendo.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "StateJefeEnfurecido.h"
#include "InterfaceContextoJefe.h"

void StateJefePersiguiendo::EjecutarComportamiento(AActor* JefeContexto, float DeltaTime)
{
	TiempoPersiguiendo += DeltaTime;

	// A los 8 segundos, se enfurece
	if (TiempoPersiguiendo >= 8.0f)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("¡EL JEFE ESTÁ ENFURECIDO!"));

		// CORRECCIÓN: Usamos dynamic_cast
		InterfaceContextoJefe* Jefe = dynamic_cast<InterfaceContextoJefe*>(JefeContexto);
		if (Jefe) { Jefe->CambiarEstado(new StateJefeEnfurecido()); return; }
	}

	// Persigue a velocidad normal (150)
	AActor* Jugador = UGameplayStatics::GetPlayerPawn(JefeContexto->GetWorld(), 0);
	if (Jugador)
	{
		FVector Direccion = Jugador->GetActorLocation() - JefeContexto->GetActorLocation();
		Direccion.Normalize();
		FVector NuevaPosicion = JefeContexto->GetActorLocation() + (Direccion * 150.0f * DeltaTime);
		JefeContexto->SetActorLocation(NuevaPosicion);
	}
}