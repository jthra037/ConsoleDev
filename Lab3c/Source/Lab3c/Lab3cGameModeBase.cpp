// Fill out your copyright notice in the Description page of Project Settings.

#include "Lab3cGameModeBase.h"
#include "UE4LabPlayerController.h"
#include "UObject/ConstructorHelpers.h"

ALab3cGameModeBase::ALab3cGameModeBase(const FObjectInitializer & ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = AUE4LabPlayerController::StaticClass();

	static ConstructorHelpers::FObjectFinder<UClass>
		PlayerPawnBPClass(TEXT("Class'/Game/Character/HeroCharacter_BP.HeroCharacter_BP_C'"));
	if (PlayerPawnBPClass.Object != nullptr)
	{
		GLog->Log("Set DefaultPawn to HeroCharacter_BP");
		DefaultPawnClass = PlayerPawnBPClass.Object;
	}
	else
	{
		GLog->Log("Cannot find HeroCharacter_BP");
	}
}


