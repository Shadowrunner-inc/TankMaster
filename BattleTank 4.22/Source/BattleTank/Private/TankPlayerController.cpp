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
	
	FVector HitLocation; //out parameter
	if(GetSightRayHitLocation(HitLocation)){
	
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString()); // logtest
		GetControlledTank()->AimAt(HitLocation);
	}
}

//Get World location if linetrace through crosshair, True If it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair posistion in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY; //out parameters for the fetch
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);//Grab the size with this function
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation);//Calc out the posistion 
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString()); //log test

	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	
	return true;
}


ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

//"De-Project" the screen position of the crosshair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CamWorldLocation;//temp hold for trashing 
	
//if the deproject works
	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CamWorldLocation, 
		LookDirection);
	return true;
}

// Line-trace along that look direction and see what we hit (up to a max range)
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& Hitlocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	//Line trace succeds
	if(GetWorld()->LineTraceSingleByChannel( HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)){
		
		// set hit location
		Hitlocation= HitResult.Location;
			return true;
		}
	Hitlocation = FVector(0);
	return false;//Line trace failed
}

