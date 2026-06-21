#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceContextoJefe.h" 
#include "InterfaceStateJefe.h"    
#include "ProductoJefeFinal.generated.h"

UCLASS()
class NAVE_API AProductoJefeFinal : public AActor, public InterfaceContextoJefe
{
	GENERATED_BODY()

public:
	AProductoJefeFinal();

	void SetMalla(UStaticMesh* Malla);
	void SetEscalaGigante();
	void SetVelocidadBase(float Velocidad);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// --- PATRÓN STATE ---
	InterfaceStateJefe* EstadoActual;
	virtual void CambiarEstado(class InterfaceStateJefe* NuevoEstado) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaJefe;

	float VelocidadMovimiento;
};