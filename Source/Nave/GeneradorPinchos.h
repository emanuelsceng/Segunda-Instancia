#pragma once

#include "CoreMinimal.h"
#include "GeneradorObstaculos.h"
#include "GeneradorPinchos.generated.h"

UCLASS()
class NAVE_API AGeneradorPinchos : public AGeneradorObstaculos
{
	GENERATED_BODY()

public:
	virtual AObstaculoBase* FabricarObstaculo(FVector Ubicacion) override;
};