// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	//find the tank the player controlls
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) { UE_LOG(LogTemp, Error, TEXT("No Player Tank!")); }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing: %s"), *(ControlledTank->GetName()));
	}
}

//Tick
void ATankPlayerController::Tick(float DeltaTime) {
	//Super
	Super::Tick( DeltaTime );
	
	//Aim Towards Crosshair
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	//Get World location if linetrace through crosshair
	//If it hits the landscape
		//Tell controlled tank to aim at the point.
}


ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}



