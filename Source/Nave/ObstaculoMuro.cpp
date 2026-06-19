#include "ObstaculoMuro.h"
#include "UObject/ConstructorHelpers.h"

AObstaculoMuro::AObstaculoMuro()
{
	// Le asignamos el cubo y lo escalamos para que parezca una pared
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCubo(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MallaCubo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MallaCubo.Object);
	}

	// Escala de Muro (Ancho y Alto)
	SetActorScale3D(FVector(1.0f, 4.0f, 3.0f));
}