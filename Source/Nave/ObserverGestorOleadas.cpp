#include "ObserverGestorOleadas.h"
#include "Engine/Engine.h"
#include "FactoryFamiliaCubos.h" 
#include "FactoryFamiliaEsferas.h" 
#include "SoldadoCubo.h"
#include "EliteCubo.h"
#include "SoldadoEsfera.h"
#include "EliteEsfera.h"

AObserverGestorOleadas::AObserverGestorOleadas()
{
	PrimaryActorTick.bCanEverTick = false;
	EnemigosRestantes = 0;
	NumeroOleadaActual = 0;
}

void AObserverGestorOleadas::BeginPlay()
{
	Super::BeginPlay();
	GenerarNuevaOleada();
}

void AObserverGestorOleadas::Actualizar(AActor* EnemigoQueMurio)
{
	EnemigosRestantes--; // Resta el enemigo que desapareció

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Enemigo destruido. Faltan: %d"), EnemigosRestantes));

	// Si ya no quedan enemigos, lanza la siguiente oleada
	if (EnemigosRestantes <= 0)
	{
		GenerarNuevaOleada();
	}
}

void AObserverGestorOleadas::GenerarNuevaOleada()
{
	NumeroOleadaActual++;

	if (NumeroOleadaActual == 1) // OLEADA 1: Familia Cubos
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("¡OLEADA 1: CUBOS!"));

		AFactoryFamiliaCubos* FabricaCubos = GetWorld()->SpawnActor<AFactoryFamiliaCubos>(AFactoryFamiliaCubos::StaticClass());
		if (FabricaCubos)
		{
			// Spawneamos en Z=250 para evitar choques con el piso
			AActor* ActorSoldado = FabricaCubos->CrearSoldado(FVector(800.0f, -300.0f, 250.0f));
			if (ASoldadoCubo* Cubo = Cast<ASoldadoCubo>(ActorSoldado)) { Cubo->Suscribir(this); EnemigosRestantes++; }

			AActor* ActorElite = FabricaCubos->CrearElite(FVector(800.0f, 300.0f, 250.0f));
			if (AEliteCubo* Elite = Cast<AEliteCubo>(ActorElite)) { Elite->Suscribir(this); EnemigosRestantes++; }
		}
	}
	else if (NumeroOleadaActual == 2) // OLEADA 2: Familia Esferas
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("¡OLEADA 2: ESFERAS!"));

		AFactoryFamiliaEsferas* FabricaEsferas = GetWorld()->SpawnActor<AFactoryFamiliaEsferas>(AFactoryFamiliaEsferas::StaticClass());
		if (FabricaEsferas)
		{
			AActor* ActorSoldado = FabricaEsferas->CrearSoldado(FVector(800.0f, -300.0f, 300.0f));
			if (ASoldadoEsfera* Esfera = Cast<ASoldadoEsfera>(ActorSoldado)) { Esfera->Suscribir(this); EnemigosRestantes++; }

			AActor* ActorElite = FabricaEsferas->CrearElite(FVector(800.0f, 300.0f, 300.0f));
			if (AEliteEsfera* Elite = Cast<AEliteEsfera>(ActorElite)) { Elite->Suscribir(this); EnemigosRestantes++; }
		}
	}
	else
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Purple, TEXT("¡TODAS LAS OLEADAS SUPERADAS!"));
	}
}