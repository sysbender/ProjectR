// Fill out your copyright notice in the Description page of Project Settings.


#include "SteerStateManagerMOCK.h"

USteerState* ASteerStateManagerMOCK::currentState()
{
	return steerState;
}

void ASteerStateManagerMOCK::setOwningJet(AJet* owner)
{
	owningJet = owner;
}
