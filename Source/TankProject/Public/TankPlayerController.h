// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPawn.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	virtual void SetupInputComponent() override;

	void OnMoveForward(float Value);
	void OnLeftAndRite(float Value);

	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	ATankPawn* PlayerTank;
	
};