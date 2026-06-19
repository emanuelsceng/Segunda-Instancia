#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProductoJefeFinal.generated.h"

UCLASS()
class NAVE_API AProductoJefeFinal : public AActor
{
	GENERATED_BODY()

public:
	AProductoJefeFinal();

	// Métodos que el Builder llamará para ensamblarlo
	void SetMalla(UStaticMesh* Malla);
	void SetEscalaGigante();
	void SetVelocidadBase(float Velocidad);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaJefe;

	// Esta variable la usará el Desarrollador 2 para sus estrategias
	float VelocidadMovimiento;
};