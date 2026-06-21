#include "StateJefeMuerto.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"

void StateJefeMuerto::EjecutarComportamiento(AActor* JefeContexto, float DeltaTime)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("¡VICTORIA! Has destruido al Jefe."));

	if (JefeContexto)
	{
		JefeContexto->Destroy();
	}
}