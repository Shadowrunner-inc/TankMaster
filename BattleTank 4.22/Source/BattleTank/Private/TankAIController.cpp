// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("AIController Tank is not possesing a tank!")); }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing: %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("AITank: %s Did not find the player's tank"), *(ControlledTank->GetName())); }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(PlayerTank->GetName()));
	}
}


ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime) {
	//Super
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		//TODO Move towards player
		
		//Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}
