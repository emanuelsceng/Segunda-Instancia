// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceAbstractFactory.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceAbstractFactory : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NAVE_API IInterfaceAbstractFactory
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// El contrato base de creación. Devuelve AActor* para facilitar el manejo en Unreal.
	virtual class AActor* CrearSoldado(FVector Ubicacion) = 0;
	virtual class AActor* CrearElite(FVector Ubicacion) = 0;
};
