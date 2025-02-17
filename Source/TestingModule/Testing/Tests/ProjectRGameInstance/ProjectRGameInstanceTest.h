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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceIsSetAsProjectGameInstanceTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.000: Is set as the project's game instance",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadMainMenuCreatesMainMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.001: loadMainMenu creates the main menu and adds it to viewport",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadMainMenuCreatesOnlyOneMainMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.002: loadMainMenu creates only one main menu",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadSingleplayerMenuCreatesSingleplayerMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.003: loadSingleplayerMenu creates the singleplayer menu and adds it to viewport",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadSingleplayerMenuCreatesOnlyOneSingleplayerMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.004: loadSingleplayerMenu creates only one singleplayer menu",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadMainMenuShowsMouseCursorTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.005: loadMainMenu makes the controller to show the mouse cursor",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadSingleplayerMenuShowsMouseCursorTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.006: loadSingleplayerMenu makes the controller to show the mouse cursor",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceNecessaryPlayersReturnsAsExpectedTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.007: necessaryPlayers returns what expectedPlayers sets",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceNecessaryPlayersOneAsDefaultTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.008: necessaryPlayers returns as default",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadSplitscreenMenuCreatesSplitscreenMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.009: loadSplitscreenMenu creates the splitscreen menu and adds it to viewport",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadSplitscreenMenuCreatesOnlyOneSplitscreenMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.010: loadSplitscreenMenu creates only one splitscreen menu",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadSplitscreenMenuShowsMouseCursorTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.011: loadSplitscreenMenu makes the controller to show the mouse cursor",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadMainMenuSetsExpectedPlayersToOneTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.012: loadMainMenu sets the expected players to 1",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceHasASessionManagerConfiguredTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.013: Has a session manager created and configured",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadLANMultiplayerMenuCreatesLANMultiplayerMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.014: loadLANMultiplayerMenu creates the lanMultiplayer menu and adds it to viewport",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadLANMultiplayerMenuCreatesOneLANMultiplayerMenuTest, 
	"ProjectR.ProjectRGameInstance Tests.Unit.015: loadLANMultiplayerMenu creates only one lan multiplayer menu",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLANMultiplayerMenuShowsMouseCursorTest, 
	"ProjectR.ProjectRGameInstance Tests.Integration.016: loadLANMultiplayerMenu makes the controller to show the mouse cursor",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadLobbyMenuCreatesLobbyMenuTest, FSimplePIETestBase,
	"ProjectR.ProjectRGameInstance Tests.Integration.017: loadLobbyMenu creates the lobby menu and adds it to viewport",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadLobbyMenuCreatesOneLobbyMenuTest, FSimplePIETestBase,
	"ProjectR.ProjectRGameInstance Tests.Integration.018: loadLobbyMenu creates only one lobby menu",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadLobbyMenuShowsMouseCursorTest, FSimplePIETestBase,
	"ProjectR.ProjectRGameInstance Tests.Integration.019: loadLobbyMenu makes the controller show the mouse cursor",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUProjectRGameInstanceLoadMainMenuDestroysPlayersButFirstTest, FSimplePIETestBase,
	"ProjectR.ProjectRGameInstance Tests.Integration.020: loadMainMenu destroys all players but the first one",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)




#endif //WITH_DEV_AUTOMATION_TESTS