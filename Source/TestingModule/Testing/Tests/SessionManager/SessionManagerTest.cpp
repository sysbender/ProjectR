// Fill out your copyright notice in the Description page of Project Settings.


#if WITH_DEV_AUTOMATION_TESTS


#include "SessionManagerTest.h"
#include "Session/SessionManager.h"
//#include "../../Mocks/SessionManagerMOCK.h"
#include "Tests/AutomationEditorCommon.h"
#include "../../Commands/CommonPIECommands.h"
#include "SessionManagerTestCommands.h"
#include "../../Utilities/ObjectContainerActor.h"


bool FUSessionManagerIsntNullWhenInstantiatedTest::RunTest(const FString& Parameters)
{
	USessionManager* testManager = NewObject<USessionManager>();

	TestNotNull("Shouldn't be null when instantiated.", testManager);

	return true;
}


bool FUSessionManagerCreateLANSessionStartsTheCreationOfSessionTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FUSessionManagerCreateAndCheckSessionCreation(this));
	//to the command above add destroy session after checking. If not, further tests that want to create a session will fail...
	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerCreateLANSessionTravelsToLobbyWhenStartedTest::RunTest(const FString& Parameters)
{
	establishInitialMapDirectoryTo(FString("/Game/Development/Maps/lobby"));
	establishTestMessageTo(FString("The session manager should travel to the lobby when the session starts."));
	establishTickLimitTo(3);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(retrieveInitialMapDirectory()));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	
	

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FUSessionManagerCreateSession);

	ADD_LATENT_AUTOMATION_COMMAND(FUSessionManagerCheckTravelToLobby(this));
	//to the command above add destroy session after checking. If not, further tests that want to create a session will fail...
	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerDestroyCurrentSessionStartsSessionDestructionTest::RunTest(const FString& Parameters)
{
	establishInitialMapDirectoryTo(FString("/Game/Development/Maps/lobby"));
	establishTestMessageTo(FString("The session manager should start session destruction when calling destroyCurrentSession."));
	establishTickLimitTo(3);

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(retrieveInitialMapDirectory()));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	
	

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FUSessionManagerCreateSession);

	ADD_LATENT_AUTOMATION_COMMAND(FUSessionManagerCheckSessionDestructionStarting(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerSearchLANSessionsStartsTheSearchOfSessionsTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FUSessionManagerCheckSessionSearching(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerSessionSearchResultsReturnsIDsFromSearchResultsTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerSearchResults(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerJoinSessionDoesntStartWithArbitraryDataTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerDoesntStartSessionJoin(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerIsBoundToFOnCreateSessionCompleteDelegateTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerBoundToFOnCreateSessionCompleteDelegate(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerIsBoundToFOnStartSessionCompleteDelegateTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerBoundToFOnStartSessionCompleteDelegate(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerIsBoundToFOnFindSessionsCompleteDelegateTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerBoundToFOnFindSessionsCompleteDelegate(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerIsBoundToFOnJoinSessionCompleteDelegateTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerBoundToFOnJoinSessionCompleteDelegate(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerFOnCreateSessionCompleteDelegateHandleIsSetTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerFOnCreateSessionCompleteDelegateHandleSet(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerFOnStartSessionCompleteDelegateHandleIsSetTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerFOnStartSessionCompleteDelegateHandleSet(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerFOnFindSessionsCompleteDelegateHandleIsSetTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerFOnFindSessionsCompleteDelegateHandleSet(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}


bool FUSessionManagerFOnJoinSessionCompleteDelegateHandleIsSetTest::RunTest(const FString& Parameters)
{
	FString testWorldName = FString("/Game/Tests/TestMaps/VoidWorld");

	ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(testWorldName));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(true));

	UClass* containerClass = AObjectContainerActor::StaticClass();
	ADD_LATENT_AUTOMATION_COMMAND(FSpawnInPIEAnActorOfClass(containerClass, FTransform()));

	ADD_LATENT_AUTOMATION_COMMAND(FCheckSessionManagerFOnJoinSessionCompleteDelegateHandleSet(this));

	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand);
	return true;
}







#endif //WITH_DEV_AUTOMATION_TESTS