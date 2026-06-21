#include "ProductoJefeFinal.h"
#include "StateJefeInactivo.h" 
#include "Materials/MaterialInstanceDynamic.h" // Para los colores

AProductoJefeFinal::AProductoJefeFinal()
{
	PrimaryActorTick.bCanEverTick = true;

	MallaJefe = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaJefe"));
	RootComponent = MallaJefe;
	VelocidadMovimiento = 0.0f;

	EstadoActual = nullptr;
}

void AProductoJefeFinal::BeginPlay()
{
	Super::BeginPlay();

	// COLOR: Morado (Jefe Final)
	if (MallaJefe && MallaJefe->GetMaterial(0)) {
		UMaterialInstanceDynamic* MaterialDinamico = UMaterialInstanceDynamic::Create(MallaJefe->GetMaterial(0), this);
		if (MaterialDinamico) {
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.5f, 0.0f, 0.8f));
			MallaJefe->SetMaterial(0, MaterialDinamico);
		}
	}

	CambiarEstado(new StateJefeInactivo());
}

void AProductoJefeFinal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EstadoActual != nullptr)
	{
		EstadoActual->EjecutarComportamiento(this, DeltaTime);
	}
}

void AProductoJefeFinal::CambiarEstado(InterfaceStateJefe* NuevoEstado)
{
	if (EstadoActual != nullptr)
	{
		delete EstadoActual;
	}
	EstadoActual = NuevoEstado;
}

void AProductoJefeFinal::SetMalla(UStaticMesh* Malla)
{
	if (Malla)
	{
		MallaJefe->SetStaticMesh(Malla);
	}
}

void AProductoJefeFinal::SetEscalaGigante()
{
	SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
}

void AProductoJefeFinal::SetVelocidadBase(float Velocidad)
{
	VelocidadMovimiento = Velocidad;
}