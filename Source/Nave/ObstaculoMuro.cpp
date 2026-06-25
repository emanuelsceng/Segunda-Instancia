#include "ObstaculoMuro.h"
#include "UObject/ConstructorHelpers.h"

AObstaculoMuro::AObstaculoMuro()
{
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCubo(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MallaCubo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MallaCubo.Object);
	}

	
	SetActorScale3D(FVector(1.0f, 4.0f, 3.0f));
}