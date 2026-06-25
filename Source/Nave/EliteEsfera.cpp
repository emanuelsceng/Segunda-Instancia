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
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Game/M_ColorEnemigo.M_ColorEnemigo"));
	if (MaterialBase.Succeeded()) { MallaCuerpo->SetMaterial(0, MaterialBase.Object); }
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
}

void AEliteEsfera::BeginPlay() {
	Super::BeginPlay();

	CambiarEstrategia(new StrategyPatrulla());
	GetWorld()->GetTimerManager().SetTimer(TimerCambioEstrategia, this, &AEliteEsfera::ActivarPersecucion, 5.0f, false);
	HabilidadDeElite();
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

void AEliteEsfera::HabilidadDeElite()
{
	// Esfera gigante destructora
	SetActorScale3D(FVector(2.5f, 2.5f, 2.5f));

	// Color de Élite (Naranja)
	if (MallaCuerpo && MallaCuerpo->GetMaterial(0)) {
		UMaterialInstanceDynamic* MaterialDinamico = UMaterialInstanceDynamic::Create(MallaCuerpo->GetMaterial(0), this);
		if (MaterialDinamico) {
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor::Yellow); // Naranja
			MallaCuerpo->SetMaterial(0, MaterialDinamico);
		}
	}
}