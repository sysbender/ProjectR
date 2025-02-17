// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * This file contains the latent commands necessary for the tests.
 */

#include "Misc/AutomationTest.h"
#include "../../TestBaseClasses/SimplePIETestBase.h"


#if WITH_DEV_AUTOMATION_TESTS


 //Test preparation commands:

DEFINE_LATENT_AUTOMATION_COMMAND(FSpawningAJetAndActivateMixedMotorState);



 //Test check commands:

DEFINE_LATENT_AUTOMATION_COMMAND_TWO_PARAMETER(FCheckMixedStateActivation, float, previousSpeed, FSimplePIETestBase*, test);


#endif //WITH_DEV_AUTOMATION_TESTS
