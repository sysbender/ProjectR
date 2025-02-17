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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUStringButtonScrollBoxIsntNullWhenInstantiatedTest, 
	"ProjectR.StringButtonScrollBox Tests.Unit.000: Isn't null when instantiated",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUStringButtonScrollBoxPopulatesScrollBoxWithStringHolderButtonsTest, FSimplePIETestBase,
	"ProjectR.StringButtonScrollBox Tests.Integration.001: populateBox fills the scroll box with string holder buttons",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUStringButtonScrollClickingChildButtonUpdatesSelectedStringTest, FSimplePIETestBase,
	"ProjectR.StringButtonScrollBox Tests.Integration.002: Clicking a child button updates the selected string text",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)


IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FUStringButtonScrollPopulatingBoxWithDifferentArraysLeavesOnlyTheLastTest, FSimplePIETestBase,
	"ProjectR.StringButtonScrollBox Tests.Integration.003: populateBox makes the scroll box keep the last array passed",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)









#endif //WITH_DEV_AUTOMATION_TESTS