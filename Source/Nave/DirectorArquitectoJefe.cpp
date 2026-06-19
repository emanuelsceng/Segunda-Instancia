#include "DirectorArquitectoJefe.h"

ADirectorArquitectoJefe::ADirectorArquitectoJefe()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ADirectorArquitectoJefe::ConstruirJefe(AActor* Constructor, FVector Ubicacion)
{
	// Casteamos el actor a la interfaz de construcción
	IInterfaceBuilderJefe* Builder = Cast<IInterfaceBuilderJefe>(Constructor);

	if (Builder)
	{
		// El Director dicta el ORDEN estricto del ensamblaje
		Builder->IniciarConstruccion(Ubicacion);
		Builder->ConstruirCuerpoBase();
		Builder->ConstruirEscalaGigante();
		Builder->ConstruirVelocidadBase();

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Director: ¡Jefe Final completado y desplegado!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Director Error: El objeto no es un Builder válido."));
	}
}