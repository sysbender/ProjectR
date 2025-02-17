// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/RaceStages/RaceStage.h"
#include "RacePreparationStage.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTR_API ARacePreparationStage : public ARaceStage
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:

	ARaceStage* nextStage() override;

	void start() override;
};
