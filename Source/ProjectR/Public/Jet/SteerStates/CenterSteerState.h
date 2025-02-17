// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Jet/SteerStates/SteerState.h"
#include "CenterSteerState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTR_API UCenterSteerState : public USteerState
{
	GENERATED_BODY()

public:
	virtual void activate(USteeringComponent* aSteeringComponent) override;
	virtual void changesMadeTo(AJet* aJet, FVector& aLinearAcceleration, FVector& anAngularAcceleration, float aSteeringMaximumForce) override;
};
