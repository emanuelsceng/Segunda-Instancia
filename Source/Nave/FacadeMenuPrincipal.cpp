#include "FacadeMenuPrincipal.h"

// Incluimos los subsistemas
#include "GeneradorMuros.h"
#include "GeneradorPinchos.h"
#include "DirectorArquitectoJefe.h"
#include "BuilderJefeGeometrico.h"
// AÑADIDO: Incluimos tu Gestor de Oleadas
#include "ObserverGestorOleadas.h" 

AFacadeMenuPrincipal::AFacadeMenuPrincipal()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AFacadeMenuPrincipal::BeginPlay()
{
	Super::BeginPlay();
}

void AFacadeMenuPrincipal::IniciarJuego()
{
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Cyan, TEXT("Facade: Orquestando la creación de todo el nivel..."));

	// 1. SUBSISTEMA FACTORY METHOD (Poblando el mapa con obstáculos)
	AGeneradorMuros* GenMuros = GetWorld()->SpawnActor<AGeneradorMuros>(AGeneradorMuros::StaticClass());
	if (GenMuros)
	{
		GenMuros->FabricarObstaculo(FVector(300.f, 500.f, 50.f));
		GenMuros->FabricarObstaculo(FVector(300.f, -500.f, 50.f));
	}

	AGeneradorPinchos* GenPinchos = GetWorld()->SpawnActor<AGeneradorPinchos>(AGeneradorPinchos::StaticClass());
	if (GenPinchos)
	{
		GenPinchos->FabricarObstaculo(FVector(900.f, 0.f, 50.f));
	}

	// 2. SUBSISTEMA OBSERVER (Le cedemos el control de los enemigos a tu Gestor)
	// Eliminamos la llamada directa a las fábricas y spawneamos tu Observer
	AObserverGestorOleadas* GestorOleadas = GetWorld()->SpawnActor<AObserverGestorOleadas>(AObserverGestorOleadas::StaticClass());

	// 3. SUBSISTEMA BUILDER (Ensamblando al Jefe Gigante)
	ADirectorArquitectoJefe* DirectorBoss = GetWorld()->SpawnActor<ADirectorArquitectoJefe>(ADirectorArquitectoJefe::StaticClass());
	ABuilderJefeGeometrico* ConstructorBoss = GetWorld()->SpawnActor<ABuilderJefeGeometrico>(ABuilderJefeGeometrico::StaticClass());

	if (DirectorBoss && ConstructorBoss)
	{
		// El Director dicta los pasos y lo coloca al fondo del mapa
		DirectorBoss->ConstruirJefe(ConstructorBoss, FVector(2000.f, 0.f, 200.f));
	}
}