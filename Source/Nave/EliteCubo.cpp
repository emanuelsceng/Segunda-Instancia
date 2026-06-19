#include "EliteCubo.h"
#include "UObject/ConstructorHelpers.h"

AEliteCubo::AEliteCubo()
{
	PrimaryActorTick.bCanEverTick = true; // Activo para el Desarrollador 2

	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;

	// Le asignamos el Cubo nativo de Unreal
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaCubo(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (FormaCubo.Succeeded())
	{
		MallaCuerpo->SetStaticMesh(FormaCubo.Object);
	}

	// Al ser la versión Élite, lo hacemos un 50% más grande para que el jurado note la diferencia
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
}

void AEliteCubo::HabilidadDeElite()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Élite Cubo listo y posicionado."));
}