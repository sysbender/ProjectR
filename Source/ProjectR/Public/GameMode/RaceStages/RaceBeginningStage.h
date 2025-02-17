// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/RaceStages/RaceStage.h"
#include "RaceBeginningStage.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTR_API ARaceBeginningStage : public ARaceStage
{
	GENERATED_BODY()

protected:
	FTimerHandle countdownTimer;
	void loadAnnouncerOnControllers();
	
public:
	virtual void start() override;

	UFUNCTION()
		void countdownToStart(int countdown=3);

	virtual ARaceStage* nextStage() override;
	
};
