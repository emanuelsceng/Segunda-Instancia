#include "EliteCubo.h"
#include "UObject/ConstructorHelpers.h"
#include "StrategyPatrulla.h"
#include "StrategyPerseguir.h"
#include "InterfaceSuscriptor.h"
#include "Materials/MaterialInstanceDynamic.h" // Para los colores

AEliteCubo::AEliteCubo() {
	PrimaryActorTick.bCanEverTick = true;
	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaCubo(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (FormaCubo.Succeeded()) { MallaCuerpo->SetStaticMesh(FormaCubo.Object); }

	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
}

void AEliteCubo::BeginPlay() {
	Super::BeginPlay();

	// COLOR: Rojo (Élite)
	if (MallaCuerpo && MallaCuerpo->GetMaterial(0)) {
		UMaterialInstanceDynamic* MaterialDinamico = UMaterialInstanceDynamic::Create(MallaCuerpo->GetMaterial(0), this);
		if (MaterialDinamico) {
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor::Red);
			MallaCuerpo->SetMaterial(0, MaterialDinamico);
		}
	}

	CambiarEstrategia(new StrategyPatrulla());
	GetWorld()->GetTimerManager().SetTimer(TimerCambioEstrategia, this, &AEliteCubo::ActivarPersecucion, 5.0f, false);
}

void AEliteCubo::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (EstrategiaActual != nullptr) { EstrategiaActual->EjecutarMovimiento(this, DeltaTime); }
}

void AEliteCubo::ActivarPersecucion() { CambiarEstrategia(new StrategyPerseguir()); }

void AEliteCubo::CambiarEstrategia(StrategyMovimiento* NuevaEstrategia) {
	if (EstrategiaActual != nullptr) { delete EstrategiaActual; }
	EstrategiaActual = NuevaEstrategia;
}

void AEliteCubo::Suscribir(InterfaceSuscriptor* Suscriptor) { GestorOleadas = Suscriptor; }
void AEliteCubo::Desuscribir(InterfaceSuscriptor* Suscriptor) { if (GestorOleadas == Suscriptor) { GestorOleadas = nullptr; } }
void AEliteCubo::NotificarMuerte() { if (GestorOleadas != nullptr) { GestorOleadas->Actualizar(this); } }

void AEliteCubo::Destroyed() {
	NotificarMuerte();
	Super::Destroyed();
}

void AEliteCubo::HabilidadDeElite() {}