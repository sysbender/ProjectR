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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FULobbyMenuIsntNullWhenInstantiatedTest, 
	"ProjectR.LobbyMenu Tests.Unit.000: Isn't null when instantiated",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuClickingReturnGoesToMainMenuTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Unit.001: Clicking the return to main menu button loads the main menu map",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuClickingAMapAndStartRaceChangesWorldTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Unit.002: Clicking a map button and then startRaceButton changes the map",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuIsLoadedInLobbyMapLevelBlueprintTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Integration.003: Is loaded by the level blueprint in the lobby map",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuGameStatePlayerArrayQuantityChangeIsUpdatedTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Integration.004: Reflects changes in the GameState playerArray quantity",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuCollapsesMapSelectorWidgetIfNotAuthorityTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Replication.006: Collapses the maps selector widget if local player isn't authority",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

//Can't use this. Jenkins can't click on a window behind another (happens because the client viewport is created in front of the server)...
//IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuReplicatesSelectedMapToClientsTest, FSimplePIETestBase,
//	"ProjectR.LobbyMenu Tests.Replication.007: Replicates selected map to clients",
//	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuClickingAMapButtonChangesLobbyGameStateSelectedMapTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Integration.007: Clicking a map makes the lobby game state to update its selected map",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FULobbyMenuClickingAMapButtonChangesLobbyMenuSelectedMapTest, FSimplePIETestBase,
	"ProjectR.LobbyMenu Tests.Integration.008: Clicking a map makes the lobby menu update its selected map",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)




#endif //WITH_DEV_AUTOMATION_TESTS