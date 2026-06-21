#include "StateJefeEnfurecido.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "StateJefeMuerto.h"
#include "InterfaceContextoJefe.h"

void StateJefeEnfurecido::EjecutarComportamiento(AActor* JefeContexto, float DeltaTime)
{
	TiempoEnfurecido += DeltaTime;

	// A los 10 segundos de furia, muere
	if (TiempoEnfurecido >= 10.0f)
	{
		// CORRECCIÓN: Usamos dynamic_cast
		InterfaceContextoJefe* Jefe = dynamic_cast<InterfaceContextoJefe*>(JefeContexto);
		if (Jefe) { Jefe->CambiarEstado(new StateJefeMuerto()); return; }
	}

	// Persigue al doble de velocidad (300)
	AActor* Jugador = UGameplayStatics::GetPlayerPawn(JefeContexto->GetWorld(), 0);
	if (Jugador)
	{
		FVector Direccion = Jugador->GetActorLocation() - JefeContexto->GetActorLocation();
		Direccion.Normalize();
		FVector NuevaPosicion = JefeContexto->GetActorLocation() + (Direccion * 600.0f * DeltaTime);
		JefeContexto->SetActorLocation(NuevaPosicion);
	}
}