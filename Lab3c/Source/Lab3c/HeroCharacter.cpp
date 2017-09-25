// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AHeroCharacter::AHeroCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AHeroCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AHeroCharacter::MoveRight);

}

void AHeroCharacter::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		// Get current rotation
		const FRotator Rotation = Controller->GetControlRotation();

		//Creates the direction vector and applies the movement
		const FVector Direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AHeroCharacter::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		// Get current rotation
		const FRotator Rotation = Controller->GetControlRotation();

		//Creates the direction vector and applies the movement
		const FVector Direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}