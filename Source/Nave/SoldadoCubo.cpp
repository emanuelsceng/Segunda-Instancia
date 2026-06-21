#include "SoldadoCubo.h"
#include "UObject/ConstructorHelpers.h"
#include "StrategyPatrulla.h"
#include "StrategyPerseguir.h"
#include "InterfaceSuscriptor.h"
#include "Materials/MaterialInstanceDynamic.h" // Para los colores

ASoldadoCubo::ASoldadoCubo() {
	PrimaryActorTick.bCanEverTick = true;
	MallaCuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCuerpo"));
	RootComponent = MallaCuerpo;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FormaCubo(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (FormaCubo.Succeeded()) { MallaCuerpo->SetStaticMesh(FormaCubo.Object); }
}

void ASoldadoCubo::BeginPlay() {
	Super::BeginPlay();

	// COLOR: Azul (Soldado Común)
	if (MallaCuerpo && MallaCuerpo->GetMaterial(0)) {
		UMaterialInstanceDynamic* MaterialDinamico = UMaterialInstanceDynamic::Create(MallaCuerpo->GetMaterial(0), this);
		if (MaterialDinamico) {
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor::Blue);
			MallaCuerpo->SetMaterial(0, MaterialDinamico);
		}
	}

	CambiarEstrategia(new StrategyPatrulla());
	GetWorld()->GetTimerManager().SetTimer(TimerCambioEstrategia, this, &ASoldadoCubo::ActivarPersecucion, 5.0f, false);
}

void ASoldadoCubo::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (EstrategiaActual != nullptr) { EstrategiaActual->EjecutarMovimiento(this, DeltaTime); }
}

void ASoldadoCubo::ActivarPersecucion() { CambiarEstrategia(new StrategyPerseguir()); }

void ASoldadoCubo::CambiarEstrategia(StrategyMovimiento* NuevaEstrategia) {
	if (EstrategiaActual != nullptr) { delete EstrategiaActual; }
	EstrategiaActual = NuevaEstrategia;
}

void ASoldadoCubo::Suscribir(InterfaceSuscriptor* Suscriptor) { GestorOleadas = Suscriptor; }
void ASoldadoCubo::Desuscribir(InterfaceSuscriptor* Suscriptor) { if (GestorOleadas == Suscriptor) { GestorOleadas = nullptr; } }
void ASoldadoCubo::NotificarMuerte() { if (GestorOleadas != nullptr) { GestorOleadas->Actualizar(this); } }

void ASoldadoCubo::Destroyed() {
	NotificarMuerte();
	Super::Destroyed();
}

void ASoldadoCubo::TareaDeSoldado() {}