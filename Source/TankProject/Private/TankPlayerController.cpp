// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

#include "TankPawn.h"

void ATankPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	InputComponent->BindAxis("MoveForward", this, &ATankPlayerController::OnMoveForward);
	InputComponent->BindAxis("LeftAndRite", this, &ATankPlayerController::OnLeftAndRite);
}

void ATankPlayerController::OnMoveForward(float Value)
{
	if(PlayerTank)
		PlayerTank->MoveForward(Value);
}
void ATankPlayerController::OnLeftAndRite(float Value)
{
	if(PlayerTank)
		PlayerTank->RotateRight(Value);
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = CastChecked<ATankPawn>(GetPawn());
}