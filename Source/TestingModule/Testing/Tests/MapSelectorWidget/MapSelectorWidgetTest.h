// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


/**
 * Each one of this tests should test something of the project class that this test class references to.
 * Each project class should have a test class for it. It's something kind of necessary for TDD.
 * 
 * It's nice if the prettyname follows a pattern like: Game.ClassToTest.Unit.TestName
 * TestName should express what you expect from a test given a scenario.
 * Pay attention to the automation flags because they're needed to run the tests without UI errors.
 */

#include "Misc/AutomationTest.h"
#include "../../TestBaseClasses/SimplePIETestBase.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUMapSelectorWidgetIsntNullWhenInstantiatedTest, 
	"ProjectR.MapSelectorWidget Tests.Unit.000: Isn't null when instantiated",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUMapSelectorWidgetCreatesAmountOfButtonsAsMapsFoundTest, FSimplePIETestBase,
	"ProjectR.MapSelectorWidget Tests.Unit.001: Creates as much string holder buttons as maps found",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)








#endif //WITH_DEV_AUTOMATION_TESTS