// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max downward movement, and +1 is max upward movement.
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegressPerSecond = 5; //standard default
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegressElevation = 40; //standard default
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegressElevation = 0; //standard default
};
