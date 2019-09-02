// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
#include "TankAimingComponet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponet : public UActorComponent
{
	GENERATED_BODY()

private:	
	
	UStaticMeshComponent* Barrel = nullptr;
	void MoveTowardsBarrel(FVector AimDirection);


public:	
	// Sets default values for this component's properties
	UTankAimingComponet();
	
	void AimAt(FVector HitLocation, float LaunchSpeed);

	//TODO: Add set Turret Reffernce

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
		
};
