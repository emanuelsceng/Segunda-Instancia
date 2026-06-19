#include "SoldadoEsfera.h"
#include "UObject/ConstructorHelpers.h"

ASoldadoEsfera::ASoldadoEsfera()
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
}

void ASoldadoEsfera::TareaDeSoldado()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Soldado Esfera listo."));
}