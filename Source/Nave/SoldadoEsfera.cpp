#include "SoldadoEsfera.h"
#include "UObject/ConstructorHelpers.h"
#include "StrategyPatrulla.h"
#include "StrategyPerseguir.h"
#include "InterfaceSuscriptor.h"
#include "Materials/MaterialInstanceDynamic.h" // Para los colores

ASoldadoEsfera::ASoldadoEsfera() {
	PrimaryActorTick.bCanEverTick = true;
	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaEsfera(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (FormaEsfera.Succeeded()) { MallaCuerpo->SetStaticMesh(FormaEsfera.Object); }
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Game/M_ColorEnemigo.M_ColorEnemigo"));
	if (MaterialBase.Succeeded()) { MallaCuerpo->SetMaterial(0, MaterialBase.Object); }
}

void ASoldadoEsfera::BeginPlay() {
	Super::BeginPlay();

	CambiarEstrategia(new StrategyPatrulla());
	GetWorld()->GetTimerManager().SetTimer(TimerCambioEstrategia, this, &ASoldadoEsfera::ActivarPersecucion, 5.0f, false);
	TareaDeSoldado();
}

void ASoldadoEsfera::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (EstrategiaActual != nullptr) { EstrategiaActual->EjecutarMovimiento(this, DeltaTime); }
}

void ASoldadoEsfera::ActivarPersecucion() { CambiarEstrategia(new StrategyPerseguir()); }

void ASoldadoEsfera::CambiarEstrategia(StrategyMovimiento* NuevaEstrategia) {
	if (EstrategiaActual != nullptr) { delete EstrategiaActual; }
	EstrategiaActual = NuevaEstrategia;
}

void ASoldadoEsfera::Suscribir(InterfaceSuscriptor* Suscriptor) { GestorOleadas = Suscriptor; }
void ASoldadoEsfera::Desuscribir(InterfaceSuscriptor* Suscriptor) { if (GestorOleadas == Suscriptor) { GestorOleadas = nullptr; } }
void ASoldadoEsfera::NotificarMuerte() { if (GestorOleadas != nullptr) { GestorOleadas->Actualizar(this); } }

void ASoldadoEsfera::Destroyed() {
	NotificarMuerte();
	Super::Destroyed();
}

void ASoldadoEsfera::TareaDeSoldado()
{
	// Esfera ligera
	SetActorScale3D(FVector(0.6f, 0.6f, 0.6f));

	// Color de soldado (Cian)
	if (MallaCuerpo && MallaCuerpo->GetMaterial(0)) {
		UMaterialInstanceDynamic* MaterialDinamico = UMaterialInstanceDynamic::Create(MallaCuerpo->GetMaterial(0), this);
		if (MaterialDinamico) {
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor::Blue);
			MallaCuerpo->SetMaterial(0, MaterialDinamico);
		}
	}
}