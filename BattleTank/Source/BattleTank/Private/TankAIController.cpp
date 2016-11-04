// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(PlayerTank->GetName()));
	}


}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn->GetPawn());
}

ATank* ATankAIController::GetControlledTank() const
{

	APawn* TankPawn = GetPawn();
	return Cast<ATank>(GetPawn());
}

