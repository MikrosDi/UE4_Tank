// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATankPawn::ATankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RootComponent = BoxComponent;

	TankBody = CreateDefaultSubobject<USkeletalMeshComponent>("TankBody");
	TankBody->SetupAttachment(RootComponent);

	TankTurret = CreateDefaultSubobject<UStaticMeshComponent>("TankTurret");
	TankTurret->SetupAttachment(TankBody);

	ArmComponent = CreateDefaultSubobject<USpringArmComponent>("ArmComponent");
	ArmComponent->SetupAttachment(RootComponent);

	CameraComponent =CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(ArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
	
}

void ATankPawn::MoveForward(float Scale)
{
	MoveSpeed = Scale;
}

void ATankPawn::RotateRight(float AxisValue)
{
	TargetRightAxisValue = AxisValue;
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Location = GetActorLocation();
	SetActorLocation(Location + GetActorForwardVector() * MoveSpeed * MovementSpeed * DeltaTime, false);
	
	CurrentRightAxisValue = FMath::Lerp(CurrentRightAxisValue, TargetRightAxisValue, InterpolationKey);
	//UE_LOG(TankLog, Warning, TEXT("CurrentRightAxisValue = %f TargetRightAxisValue = %f"), CurrentRightAxisValue, TargetRightAxisValue);
	float yawRotation = RotationSpeed * CurrentRightAxisValue * DeltaTime;
	FRotator currentRotation = GetActorRotation();
	yawRotation = currentRotation.Yaw + yawRotation;
	FRotator newRotation = FRotator(0, yawRotation, 0);
	SetActorRotation(newRotation);
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


