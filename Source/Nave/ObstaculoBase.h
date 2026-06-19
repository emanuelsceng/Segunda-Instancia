#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstaculoBase.generated.h"

UCLASS()
class NAVE_API AObstaculoBase : public AActor
{
	GENERATED_BODY()

public:
	AObstaculoBase();

protected:
	// El componente visual base para todos los obstáculos
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaObstaculo;
};