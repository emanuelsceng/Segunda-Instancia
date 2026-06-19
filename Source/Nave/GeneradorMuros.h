#pragma once

#include "CoreMinimal.h"
#include "GeneradorObstaculos.h"
#include "GeneradorMuros.generated.h"

UCLASS()
class NAVE_API AGeneradorMuros : public AGeneradorObstaculos
{
	GENERATED_BODY()

public:
	virtual AObstaculoBase* FabricarObstaculo(FVector Ubicacion) override;
};