#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceBuilderJefe.h"
#include "DirectorArquitectoJefe.generated.h"

UCLASS()
class NAVE_API ADirectorArquitectoJefe : public AActor
{
	GENERATED_BODY()

public:
	ADirectorArquitectoJefe();

	// El director recibe cualquier Constructor que respete la interfaz
	void ConstruirJefe(AActor* Constructor, FVector Ubicacion);
};