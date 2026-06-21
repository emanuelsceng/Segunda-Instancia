#include "StrategyPerseguir.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

void StrategyPerseguir::EjecutarMovimiento(AActor* Contexto, float DeltaTime)
{
	if (!Contexto) return;

	// 1. En el milisegundo que se activa, guarda la ubicación exacta del jugador
	if (!bDestinoFijado)
	{
		AActor* Jugador = UGameplayStatics::GetPlayerPawn(Contexto->GetWorld(), 0);
		if (Jugador)
		{
			DestinoMemorizado = Jugador->GetActorLocation();
			bDestinoFijado = true;
		}
	}

	// 2. Viaja hacia ese punto
	if (bDestinoFijado)
	{
		// Calculamos la distancia (solo 2D para que no se atasque contra el piso)
		float DistanciaAlDestino = FVector::Dist2D(DestinoMemorizado, Contexto->GetActorLocation());

		if (DistanciaAlDestino < 100.0f) // Si llegó al punto exacto...
		{
			Contexto->Destroy(); // ¡Se destruye!
		}
		else // Si no ha llegado, sigue volando
		{
			FVector Direccion = DestinoMemorizado - Contexto->GetActorLocation();
			Direccion.Normalize();
			FVector NuevaPosicion = Contexto->GetActorLocation() + (Direccion * 300.0f * DeltaTime);
			Contexto->SetActorLocation(NuevaPosicion);
		}
	}
}