#include "DecoratorMejoraVelocidad.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Engine.h" // Para imprimir mensajes en pantalla

float ADecoratorMejoraVelocidad::GetVelocidadActual() const
{
	return Super::GetVelocidadActual() * 1.5f;
}

void ADecoratorMejoraVelocidad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	// 1. Verificamos que el actor que nos tocó no seamos nosotros mismos
	if (OtherActor && OtherActor != this)
	{
		// 2. Intentamos ver si el actor que nos tocó implementa nuestra Interfaz (es decir, si es la NaveCharacter)
		IDecoratorMoverPersonaje* PersonajeInterfaz = Cast<IDecoratorMoverPersonaje>(OtherActor);
		ACharacter* PersonajeFisico = Cast<ACharacter>(OtherActor);

		if (PersonajeInterfaz != nullptr && PersonajeFisico != nullptr)
		{
			// --- AQUÍ OCURRE LA MAGIA DEL PATRÓN DECORATOR ---
			// 3. Envolvemos al personaje en nuestro Decorator
			PersonajeEnvuelto = PersonajeInterfaz;

			// 4. Le pedimos al patrón que calcule la nueva velocidad matemática
			float NuevaVelocidad = GetVelocidadActual();

			// 5. Le aplicamos esa nueva velocidad al motor de Unreal para que sea visible
			PersonajeFisico->GetCharacterMovement()->MaxWalkSpeed = NuevaVelocidad;

			// (Opcional) Mensaje en pantalla para la defensa del proyecto
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Power-Up Agarrado! Nueva velocidad: %f"), NuevaVelocidad));
			}

			// 6. Destruimos el power-up geométrico del mapa
			Destroy();
		}
	}
}