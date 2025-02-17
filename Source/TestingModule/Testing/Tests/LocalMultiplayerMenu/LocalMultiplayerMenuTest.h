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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FULocalMultiplayerMenuIsntNullWhenInstantiatedTest, 
	"ProjectR.LocalMultiplayerMenu Tests.Unit.000: Isn't null when instantiated",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULocalMultiplayerMenuClickingGoBackButtonRemovesFromViewportTest, FSimplePIETestBase,
	"ProjectR.LocalMultiplayerMenu Tests.Integration.001: Clicking the go back button removes the menu from viewport",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULocalMultiplayerMenuClickingGoBackButtonBringsMainMenuTest, FSimplePIETestBase,
	"ProjectR.LocalMultiplayerMenu Tests.Integration.002: Clicking the go back button brings the mainMenu",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULocalMultiplayerMenuClickingPlayButtonSetsPlayerQuantityTest, FSimplePIETestBase,
	"ProjectR.LocalMultiplayerMenu Tests.Integration.003: Clicking the play button sets the expected local players in a game",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULocalMultiplayerMenuClickingMapAndPlayButtonChangesMapTest, FSimplePIETestBase,
	"ProjectR.LocalMultiplayerMenu Tests.Integration.004: Clicking a map button and then play changes the map",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)









#endif //WITH_DEV_AUTOMATION_TESTS