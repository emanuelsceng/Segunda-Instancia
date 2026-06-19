#include "ObstaculoBase.h"

AObstaculoBase::AObstaculoBase()
{
	PrimaryActorTick.bCanEverTick = false; // Son obstáculos estáticos, no necesitan Tick

	MallaObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaObstaculo"));
	RootComponent = MallaObstaculo;
}