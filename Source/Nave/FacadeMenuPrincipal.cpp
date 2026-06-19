#include "FacadeMenuPrincipal.h"

// Incluimos los 3 subsistemas que la fachada va a orquestar
#include "FactoryFamiliaCubos.h"
#include "GeneradorMuros.h"
#include "GeneradorPinchos.h"
#include "DirectorArquitectoJefe.h"
#include "BuilderJefeGeometrico.h"

AFacadeMenuPrincipal::AFacadeMenuPrincipal()
{
	PrimaryActorTick.bCanEverTick = false; // La fachada no necesita Tick
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

	// 2. SUBSISTEMA ABSTRACT FACTORY (Poblando la primera oleada de enemigos)
	AFactoryFamiliaCubos* FabCubos = GetWorld()->SpawnActor<AFactoryFamiliaCubos>(AFactoryFamiliaCubos::StaticClass());
	if (FabCubos)
	{
		FabCubos->CrearSoldado(FVector(1000.f, 200.f, 50.f));
		FabCubos->CrearElite(FVector(1000.f, -200.f, 50.f));
	}

	// 3. SUBSISTEMA BUILDER (Ensamblando al Jefe Gigante)
	ADirectorArquitectoJefe* DirectorBoss = GetWorld()->SpawnActor<ADirectorArquitectoJefe>(ADirectorArquitectoJefe::StaticClass());
	ABuilderJefeGeometrico* ConstructorBoss = GetWorld()->SpawnActor<ABuilderJefeGeometrico>(ABuilderJefeGeometrico::StaticClass());

	if (DirectorBoss && ConstructorBoss)
	{
		// El Director dicta los pasos y lo coloca al fondo del mapa
		DirectorBoss->ConstruirJefe(ConstructorBoss, FVector(2000.f, 0.f, 200.f));
	}
}