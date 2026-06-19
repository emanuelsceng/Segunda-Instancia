#include "ProductoJefeFinal.h"

AProductoJefeFinal::AProductoJefeFinal()
{
	// Activamos el Tick para que el Desarrollador 2 pueda darle movimiento
	PrimaryActorTick.bCanEverTick = true;

	MallaJefe = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaJefe"));
	RootComponent = MallaJefe;
	VelocidadMovimiento = 0.0f;
}

void AProductoJefeFinal::BeginPlay()
{
	Super::BeginPlay();
}

void AProductoJefeFinal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// El Desarrollador 2 programará aquí adentro el patrón State
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
	// Lo hacemos enorme para que sea innegable que es un Jefe
	SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
}

void AProductoJefeFinal::SetVelocidadBase(float Velocidad)
{
	VelocidadMovimiento = Velocidad;
}