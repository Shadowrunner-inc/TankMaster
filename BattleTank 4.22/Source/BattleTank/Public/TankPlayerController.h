// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere) float CrosshairXLocation = 0.5f, CrosshairYLocation = 0.33333f;
	UPROPERTY(EditAnywhere) float LineTraceRange = 1000000;//10 kilometers

	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	///Start the tank moving the barrel 
	///so that a shot would hit where 
	///the crosshair intersects the world.
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector Lookdirection, FVector& Hitlocation) const;
};
