// Fill out your copyright notice in the Description page of Project Settings.


#if WITH_DEV_AUTOMATION_TESTS

#include "SessionManagerTestCommands.h"
#include "../../Utilities/PIESessionUtilities.h"
#include "../../Utilities/ObjectContainerActor.h"
#include "../../Mocks/SessionManagerMOCK.h"
#include "Session/SessionManager.h"
#include "OnlineSessionSettings.h"

//Test preparation commands:

bool FUSessionManagerCreateSession::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManager>();
			USessionManager* testManager = Cast<USessionManager, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->createLANSession();
				return true;
			}
		}
	}
	return false;
}













//Test check commands:



bool FUSessionManagerCreateAndCheckSessionCreation::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManager>();
			USessionManager* testManager = Cast<USessionManager, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				test->TestTrue("createLANSession should start the asynchronous creation of a LAN session", testManager->createLANSession());

				testManager->destroyCurrentSession();
				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FUSessionManagerCheckTravelToLobby::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		
		UE_LOG(LogTemp, Log, TEXT("current PIE world: %s."), *sessionUtilities.currentPIEWorld()->GetMapName());
		bool isInAnotherWorld = !sessionUtilities.currentPIEWorld()->GetMapName().Contains("voidWorld");

		if (isInAnotherWorld)
		{
			test->TestTrue(test->conditionMessage(), isInAnotherWorld);

			AObjectContainerActor* objectContainer = sessionUtilities.spawnInPIEAnInstanceOf<AObjectContainerActor>();
			objectContainer->storeObjectOfType<USessionManager>();
			USessionManager* testManager = Cast<USessionManager, UObject>(objectContainer->retrieveStoredObject());
			testManager->destroyCurrentSession();
			
			sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
			return true;
		}

		return test->manageTickCountTowardsLimit();
	}
	return false;
}


bool FUSessionManagerCheckSessionDestructionStarting::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		
		UE_LOG(LogTemp, Log, TEXT("current PIE world: %s."), *sessionUtilities.currentPIEWorld()->GetMapName());
		bool isInAnotherWorld = !sessionUtilities.currentPIEWorld()->GetMapName().Contains("voidWorld");

		if (isInAnotherWorld)
		{
			AObjectContainerActor* objectContainer = sessionUtilities.spawnInPIEAnInstanceOf<AObjectContainerActor>();

			objectContainer->storeObjectOfType<USessionManager>();
			USessionManager* testManager = Cast<USessionManager, UObject>(objectContainer->retrieveStoredObject());
			
			test->TestTrue(test->conditionMessage(), testManager->destroyCurrentSession());
			sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
			return true;

		}
		return test->manageTickCountTowardsLimit();
	}
	return false;
}


bool FUSessionManagerCheckSessionSearching::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManager>();
			USessionManager* testManager = Cast<USessionManager, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				test->TestTrue("searchLANSessions should start the asynchronous search of LAN sessions", testManager->searchLANSessions());
				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerSearchResults::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				FOnlineSession falseSession = FOnlineSession();
				FOnlineSessionSearchResult falseSessionResult = FOnlineSessionSearchResult();
				falseSessionResult.Session = falseSession;
				TArray<FOnlineSessionSearchResult> falseResults = TArray<FOnlineSessionSearchResult>();
				falseResults.Add(falseSessionResult);

				TSharedPtr<FOnlineSessionSearch> dummySearchResults = MakeShared<FOnlineSessionSearch>();

				dummySearchResults->SearchResults = falseResults;
				
				bool startsWithoutSearchResults = testManager->sessionSearchResults().Num() == 0;
				
				testManager->setArbitrarySessionSearchResults(dummySearchResults);

				bool returnsSearchResults = testManager->sessionSearchResults().Num() > 0;

				test->TestTrue(TEXT("sessionSearchResults returns the search Results session ID's"), startsWithoutSearchResults && returnsSearchResults);

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerDoesntStartSessionJoin::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				FOnlineSession falseSession = FOnlineSession(FOnlineSessionSettings());
				falseSession.OwningUserId = testContainer->GetGameInstance()->GetPrimaryPlayerUniqueId();
				FOnlineSessionSearchResult falseSessionResult = FOnlineSessionSearchResult();
				falseSessionResult.Session = falseSession;
				TArray<FOnlineSessionSearchResult> falseResults = TArray<FOnlineSessionSearchResult>();
				falseResults.Add(falseSessionResult);

				TSharedPtr<FOnlineSessionSearch> dummySearchResults = MakeShared<FOnlineSessionSearch>();
				
				testManager->setArbitrarySessionSearchResults(dummySearchResults);

				test->TestFalse(TEXT("joinASession isn't started when fed with arbitrary data"), testManager->joinASession(GameSessionName, falseSessionResult));

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerBoundToFOnCreateSessionCompleteDelegate::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("session manager should be bound to FOnCreateSessionCompleteDelegate"), testManager->isBoundToFOnCreateSessionCompleteDelegate());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerBoundToFOnStartSessionCompleteDelegate::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("session manager should be bound to FOnStartSessionCompleteDelegate"), testManager->isBoundToFOnStartSessionCompleteDelegate());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerBoundToFOnFindSessionsCompleteDelegate::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("session manager should be bound to FOnFindSessionsCompleteDelegate"), testManager->isBoundToFOnFindSessionsCompleteDelegate());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerBoundToFOnJoinSessionCompleteDelegate::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("session manager should be bound to FOnJoinSessionCompleteDelegate"), testManager->isBoundToFOnJoinSessionCompleteDelegate());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerFOnCreateSessionCompleteDelegateHandleSet::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("FOnCreateSessionCompleteDelegate handle should be set"), testManager->FOnCreateSessionCompleteDelegateHandleIsSet());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerFOnStartSessionCompleteDelegateHandleSet::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("FOnStartSessionCompleteDelegate handle should be set"), testManager->FOnStartSessionCompleteDelegateHandleIsSet());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerFOnFindSessionsCompleteDelegateHandleSet::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("FOnFindSessionsCompleteDelegate handle should be set"), testManager->FOnFindSessionsCompleteDelegateHandleIsSet());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckSessionManagerFOnJoinSessionCompleteDelegateHandleSet::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();

		AObjectContainerActor* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<AObjectContainerActor>();

		if(testContainer)
		{
			testContainer->storeObjectOfType<USessionManagerMOCK>();
			USessionManagerMOCK* testManager = Cast<USessionManagerMOCK, UObject>(testContainer->retrieveStoredObject());
			if(testManager)
			{
				testManager->configureSubsystemAndInterface();

				test->TestTrue(TEXT("FOnJoinSessionCompleteDelegate handle should be set"), testManager->FOnJoinSessionCompleteDelegateHandleIsSet());

				
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}






#endif //WITH_DEV_AUTOMATION_TESTS
