#pragma once

#include "CoreMinimal.h"
#include "DecoratorBase.h"
#include "DecoratorMejoraVelocidad.generated.h"

UCLASS()
class NAVE_API ADecoratorMejoraVelocidad : public ADecoratorBase
{
	GENERATED_BODY()

public:
	virtual float GetVelocidadActual() const override;

protected:
	// Evento nativo de Unreal que se dispara cuando algo toca a este Actor
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};