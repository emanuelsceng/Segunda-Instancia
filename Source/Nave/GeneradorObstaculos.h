#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstaculoBase.h"
#include "GeneradorObstaculos.generated.h"

UCLASS()
class NAVE_API AGeneradorObstaculos : public AActor
{
	GENERATED_BODY()

public:
	AGeneradorObstaculos();

	// El Factory Method purista de libro. La macro PURE_VIRTUAL equivale a "= 0" en C++ estándar
	// pero le permite a Unreal Engine no crashear con su sistema de reflexión de Actores.
	virtual AObstaculoBase* FabricarObstaculo(FVector Ubicacion) PURE_VIRTUAL(AGeneradorObstaculos::FabricarObstaculo, return nullptr;);
};