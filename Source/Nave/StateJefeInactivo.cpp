#include "StateJefeInactivo.h"
#include "GameFramework/Actor.h"
#include "StateJefePersiguiendo.h"
#include "InterfaceContextoJefe.h"

void StateJefeInactivo::EjecutarComportamiento(AActor* JefeContexto, float DeltaTime)
{
	TiempoEspera += DeltaTime;

	// Espera 3 segundos quieto
	if (TiempoEspera >= 12.0f)
	{
		// CORRECCIÓN: Usamos dynamic_cast de C++ puro en lugar de Cast de Unreal
		InterfaceContextoJefe* Jefe = dynamic_cast<InterfaceContextoJefe*>(JefeContexto);
		if (Jefe)
		{
			Jefe->CambiarEstado(new StateJefePersiguiendo());
		}
	}
}