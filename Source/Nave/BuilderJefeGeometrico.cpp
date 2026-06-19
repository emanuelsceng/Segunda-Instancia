#include "BuilderJefeGeometrico.h"

ABuilderJefeGeometrico::ABuilderJefeGeometrico()
{
	PrimaryActorTick.bCanEverTick = false;
	JefeEnConstruccion = nullptr;
}

void ABuilderJefeGeometrico::IniciarConstruccion(FVector Ubicacion)
{
	// Spawneamos el actor vacío en el mundo para empezar a rellenarlo
	JefeEnConstruccion = GetWorld()->SpawnActor<AProductoJefeFinal>(AProductoJefeFinal::StaticClass(), Ubicacion, FRotator::ZeroRotator);
}

void ABuilderJefeGeometrico::ConstruirCuerpoBase()
{
	if (JefeEnConstruccion)
	{
		// Usamos StaticLoadObject para asignarle la malla desde el Builder
		UStaticMesh* CuboMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
		JefeEnConstruccion->SetMalla(CuboMesh);
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple, TEXT("Builder: Cuerpo base ensamblado."));
	}
}

void ABuilderJefeGeometrico::ConstruirEscalaGigante()
{
	if (JefeEnConstruccion)
	{
		JefeEnConstruccion->SetEscalaGigante();
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple, TEXT("Builder: Escala gigante aplicada."));
	}
}

void ABuilderJefeGeometrico::ConstruirVelocidadBase()
{
	if (JefeEnConstruccion)
	{
		JefeEnConstruccion->SetVelocidadBase(300.0f); // Velocidad inicial
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple, TEXT("Builder: Velocidad base configurada."));
	}
}

AProductoJefeFinal* ABuilderJefeGeometrico::ObtenerJefe()
{
	AProductoJefeFinal* ProductoFinal = JefeEnConstruccion;

	// Limpiamos el puntero para la próxima construcción
	JefeEnConstruccion = nullptr;

	return ProductoFinal;
}