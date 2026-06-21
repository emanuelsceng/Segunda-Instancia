#include "StrategyPatrulla.h"
#include "GameFramework/Actor.h"

void StrategyPatrulla::EjecutarMovimiento(AActor* Contexto, float DeltaTime)
{
	if (!Contexto) return;

	// Patrulla simple de izquierda a derecha
	FVector PosicionActual = Contexto->GetActorLocation();
	PosicionActual.Y += FMath::Sin(Contexto->GetWorld()->GetTimeSeconds() * 3.0f) * 15.0f;
	Contexto->SetActorLocation(PosicionActual);
}