#include "EliteEsfera.h"
#include "UObject/ConstructorHelpers.h"

AEliteEsfera::AEliteEsfera()
{
	PrimaryActorTick.bCanEverTick = true;

	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;

	// Le asignamos la Esfera nativa de Unreal
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaEsfera(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (FormaEsfera.Succeeded())
	{
		MallaCuerpo->SetStaticMesh(FormaEsfera.Object);
	}

	// Al ser el Élite de las esferas, también aumentamos su escala
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
}

void AEliteEsfera::HabilidadDeElite()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Élite Esfera listo y posicionado."));
}