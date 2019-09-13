// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	
	//Clamp the speed between 1 an -1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1); //Reassign the speed;

	//Calc the target goal for our new elevation.
	auto ElevationChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	//Clamp given a max elevation speed, and the frame time
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinDegressElevation, MaxDegressElevation);

	//Move the Barrel to the right amount this frame
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
