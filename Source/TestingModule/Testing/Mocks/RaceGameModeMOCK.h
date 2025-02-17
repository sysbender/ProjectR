// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/RaceGameMode.h"
#include "RaceGameModeMOCK.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGMODULE_API ARaceGameModeMOCK : public ARaceGameMode
{
	GENERATED_BODY()
public:
	void StartPlay() override;

	void changeStageTo(ARaceStage* anotherStage);

	ARaceStage* currentStage();

	void addToRunningJets(AJet* aJet);

	void createLapManagerMOCK();
};
