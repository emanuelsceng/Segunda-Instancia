#include "EliteEsfera.h"
#include "UObject/ConstructorHelpers.h"
#include "StrategyPatrulla.h"
#include "StrategyPerseguir.h"
#include "InterfaceSuscriptor.h"
#include "Materials/MaterialInstanceDynamic.h" // Para los colores

AEliteEsfera::AEliteEsfera() {
	PrimaryActorTick.bCanEverTick = true;
	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaEsfera(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (FormaEsfera.Succeeded()) { MallaCuerpo->SetStaticMesh(FormaEsfera.Object); }

	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
}

void AEliteEsfera::BeginPlay() {
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
	GetWorld()->GetTimerManager().SetTimer(TimerCambioEstrategia, this, &AEliteEsfera::ActivarPersecucion, 5.0f, false);
}

void AEliteEsfera::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (EstrategiaActual != nullptr) { EstrategiaActual->EjecutarMovimiento(this, DeltaTime); }
}

void AEliteEsfera::ActivarPersecucion() { CambiarEstrategia(new StrategyPerseguir()); }

void AEliteEsfera::CambiarEstrategia(StrategyMovimiento* NuevaEstrategia) {
	if (EstrategiaActual != nullptr) { delete EstrategiaActual; }
	EstrategiaActual = NuevaEstrategia;
}

void AEliteEsfera::Suscribir(InterfaceSuscriptor* Suscriptor) { GestorOleadas = Suscriptor; }
void AEliteEsfera::Desuscribir(InterfaceSuscriptor* Suscriptor) { if (GestorOleadas == Suscriptor) { GestorOleadas = nullptr; } }
void AEliteEsfera::NotificarMuerte() { if (GestorOleadas != nullptr) { GestorOleadas->Actualizar(this); } }

void AEliteEsfera::Destroyed() {
	NotificarMuerte();
	Super::Destroyed();
}

void AEliteEsfera::HabilidadDeElite() {}