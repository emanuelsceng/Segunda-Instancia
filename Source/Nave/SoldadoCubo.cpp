#include "SoldadoCubo.h"
#include "UObject/ConstructorHelpers.h"

ASoldadoCubo::ASoldadoCubo()
{
	PrimaryActorTick.bCanEverTick = true; // Activo para que el Dev 2 pueda usarlo luego

	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;

	// Le asignamos el Cubo nativo de Unreal
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaCubo(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (FormaCubo.Succeeded())
	{
		MallaCuerpo->SetStaticMesh(FormaCubo.Object);
	}
}

void ASoldadoCubo::TareaDeSoldado()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Soldado Cubo listo."));
}