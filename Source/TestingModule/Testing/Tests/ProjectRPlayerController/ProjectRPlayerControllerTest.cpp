// Fill out your copyright notice in the Description page of Project Settings.


#if WITH_DEV_AUTOMATION_TESTS

#include "ProjectRPlayerControllerTest.h"
#include "PrRPlayerControllerTestCommands.h"
#include "PlayerController/ProjectRPlayerController.h"
#include "Tests/AutomationEditorCommon.h"
#include "../../Commands/CommonPIECommands.h"
#include "../../Commands/NetworkCommands.h"





bool FAProjectRPlayerControllerIsntNullWhenInstantiatedTest::RunTest(const FString& Parameters)
{
	AProjectRPlayerController* testPlayerController = NewObject<AProjectRPlayerController>();
	TestNotNull(TEXT("The player controller shouldn't be null after instantiating it."), testPlayerController);

	return true;
}


bool FAProjectRPlayerControllerLoadPauseMenuAddsItToViewportTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerController");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerBringsPauseMenu(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerLoadPauseMenuCreatesOnlyOneInstanceTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerController");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerCreatesUniquePauseMenuInstance(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerLoadPauseMenuShowsMouseCursorTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerController");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerShowsMouseCursor(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerPauseGameActionKeyLoadsPauseMenuTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerControllerMOCK");
	establishTestMessageTo(FString("PauseGameAction key should make the controller load the pause menu."));
	establishTickLimitTo(3);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));
	
	
	

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerPressPauseGameActionBringsPauseMenu(nullptr, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerPauseGameActionKeyRemovesPauseMenuIfInViewportTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerControllerMOCK");
	establishTestMessageTo(FString("PauseGameAction key makes the controller remove the pause menu present in viewport and hide the mouse cursor."));
	establishTickLimitTo(3);
	
	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));
	
	
	

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerPressPauseGameActionRemovesPauseMenuInViewport(nullptr, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerLoadPauseMenuPausesTheGameTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerControllerMOCK");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerLoadPauseMenuPausesTheGame(nullptr, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerLoadPauseMenuUnPausesTheGameIfInViewportTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld-PlayerControllerMOCK");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPlayerControllerLoadPauseMenuUnPausesTheGameIfInViewport(nullptr, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerFullyTicksWhenGamePausedTest::RunTest(const FString& Parameters)
{
	AProjectRPlayerController* testController = NewObject<AProjectRPlayerController>();

	TestTrue(TEXT("The controller should be set to fully tick when game is paused"), testController->ShouldPerformFullTickWhenPaused());
	return true;
}


bool FAProjectRPlayerControllerLoadRaceUILoadsthePlayerStateUITest::RunTest(const FString& Parameters)
{
	establishInitialMapDirectoryTo(FString("/Game/Tests/TestMaps/VoidWorld-ControllerPlayerState"));
	establishTestMessageTo(FString("The ProjectRController should load the stored RacePlayerState UI when calling loadRaceUI."));
	establishTickLimitTo(3);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(retrieveInitialMapDirectory()));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));
	
	
	

	
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnLocalPlayerInPIE);

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPRPlayerControllerLoadsPlayerStateUI(nullptr, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerLoadRaceUIMakesRacePlayerUISynchronizeVariablesTest::RunTest(const FString& Parameters)
{
	establishInitialMapDirectoryTo(FString("/Game/Tests/TestMaps/VoidWorld-ControllerPlayerState"));
	establishTestMessageTo(FString("The ProjectRPlayerController should synchronize the loaded RacePlayerUI values to the ones in its RacePlayerState."));
	establishTickLimitTo(3);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(retrieveInitialMapDirectory()));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));
	
	
	

	ADD_LATENT_AUTOMATION_COMMAND(FSpawnLocalPlayerInPIE);

	ADD_LATENT_AUTOMATION_COMMAND(FCheckPRPlayerControllerLoadsPlayerRaceUISynchronized(nullptr, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerServerRemoveAnnouncerUIRemovesClientLoadedAnnouncerUITest::RunTest(const FString& Parameters)
{
	establishInitialMapDirectoryTo(FString("/Game/Tests/TestMaps/VoidWorld-RaceGameModeMOCK"));
	establishTestMessageTo(FString("The ProjectRPlayerController should remove the client's AnnouncerUI when calling removeAnnouncerUI."));
	establishTickLimitTo(10);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(retrieveInitialMapDirectory()));
	int32 numberOfPlayers = 2;
	EPlayNetMode networkMode = EPlayNetMode::PIE_ListenServer;

	ADD_LATENT_AUTOMATION_COMMAND(FStartNetworkedPIESession(numberOfPlayers, networkMode));
	
	
	

	ADD_LATENT_AUTOMATION_COMMAND(FServerLoadAnnouncers(numberOfPlayers, this));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckServerRemoveAnnouncerUIRemovesFromClient(numberOfPlayers, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FAProjectRPlayerControllerServerLoadResultsUILoadsClientRaceResultsUITest::RunTest(const FString& Parameters)
{
	establishInitialMapDirectoryTo(FString("/Game/Tests/TestMaps/VoidWorld-RaceGameModeMOCK"));
	establishTestMessageTo(FString("The ProjectRPlayerController server should load the RaceResultsUI in the client when calling loadResultsUI."));
	establishTickLimitTo(10);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(retrieveInitialMapDirectory()));
	int32 numberOfPlayers = 2;
	EPlayNetMode networkMode = EPlayNetMode::PIE_ListenServer;

	ADD_LATENT_AUTOMATION_COMMAND(FStartNetworkedPIESession(numberOfPlayers, networkMode));
	
	
	

	ADD_LATENT_AUTOMATION_COMMAND(FServerLoadResults(numberOfPlayers, this));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckClientLoadsResults(numberOfPlayers, this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}










#endif //WITH_DEV_AUTOMATION_TESTS