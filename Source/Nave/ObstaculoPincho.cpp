#include "ObstaculoPincho.h"
#include "UObject/ConstructorHelpers.h"

AObstaculoPincho::AObstaculoPincho()
{
	// Le asignamos el cono
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCono(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MallaCono.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MallaCono.Object);
	}

	
	SetActorScale3D(FVector(1.5f, 1.5f, 2.0f));
}