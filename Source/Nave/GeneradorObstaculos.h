#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstaculoBase.h"
#include "GeneradorObstaculos.generated.h"

UCLASS(Abstract)
class NAVE_API AGeneradorObstaculos : public AActor
{
	GENERATED_BODY()

public:
	AGeneradorObstaculos();

	// Factory Method
	virtual AObstaculoBase* FabricarObstaculo(FVector Ubicacion) PURE_VIRTUAL(AGeneradorObstaculos::FabricarObstaculo, return nullptr;);
};