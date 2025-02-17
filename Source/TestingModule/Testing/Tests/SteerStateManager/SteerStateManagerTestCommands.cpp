// Fill out your copyright notice in the Description page of Project Settings.


#if WITH_DEV_AUTOMATION_TESTS

#include "SteerStateManagerTestCommands.h"
//#include "Jet/SteerStates/CenterSteerState.h"

#include "Jet/Jet.h"
#include "../../Mocks/SteerStateManagerMOCK.h"
#include "../../Utilities/PIESessionUtilities.h"
//#include "../../Utilities/NetworkedPIESessionUtilities.h"

//Test preparation commands:


bool FLeftSteerASteerStateManagerMOCK::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();
		
		if (testManager && testJet)
		{
			testManager->setOwningJet(testJet);
			testManager->steerLeft();
			return true;
		}
	}
	return false;
}


bool FRightSteerASteerStateManagerMOCK::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();

		if (testManager && testJet)
		{
			testManager->setOwningJet(testJet);
			testManager->steerRight();
			return true;
		}
	}
	return false;
}


bool FCenterASteerStateManagerMOCK::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();

		if (testManager && testJet)
		{
			testManager->setOwningJet(testJet);
			testManager->center();
			return true;
		}
	}
	return false;
}


//bool FClientSteerLeftSteerStateManager::Update()
//{
//	if (GEditor->IsPlayingSessionInEditor())
//	{		
//		FWorldContext serverContext = NetworkedPIESessionUtilities::retrieveServerWorldContext(clientQuantity);
//		UWorld* serverWorld = serverContext.World();
//
//		if(serverWorld)
//		{
//			FWorldContext clientContext = NetworkedPIESessionUtilities::retrieveClientWorldContext();
//			UWorld* clientWorld = clientContext.World();
//
//			if(clientWorld)
//			{
//				ASteerStateManager* testClientManager = Cast<ASteerStateManager, AActor>(UGameplayStatics::GetActorOfClass(clientWorld, ASteerStateManager::StaticClass()));
//				if (testClientManager)
//				{
//					UE_LOG(LogTemp, Log, TEXT("steering left steer state manager..."));
//					testClientManager->steerLeft();
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//
//
//bool FClientSteerRightSteerStateManager::Update()
//{
//	if (GEditor->IsPlayingSessionInEditor())
//	{		
//		FWorldContext serverContext = NetworkedPIESessionUtilities::retrieveServerWorldContext(clientQuantity);
//		UWorld* serverWorld = serverContext.World();
//
//		if(serverWorld)
//		{
//			FWorldContext clientContext = NetworkedPIESessionUtilities::retrieveClientWorldContext();
//			UWorld* clientWorld = clientContext.World();
//
//			if(clientWorld)
//			{
//				ASteerStateManager* testClientManager = Cast<ASteerStateManager, AActor>(UGameplayStatics::GetActorOfClass(clientWorld, ASteerStateManager::StaticClass()));
//				if (testClientManager)
//				{
//					UE_LOG(LogTemp, Log, TEXT("steering right steer state manager..."));
//					testClientManager->steerRight();
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//
//
//bool FClientCenterSteerStateManager::Update()
//{
//	if (GEditor->IsPlayingSessionInEditor())
//	{		
//		FWorldContext serverContext = NetworkedPIESessionUtilities::retrieveServerWorldContext(clientQuantity);
//		UWorld* serverWorld = serverContext.World();
//
//		if(serverWorld)
//		{
//			FWorldContext clientContext = NetworkedPIESessionUtilities::retrieveClientWorldContext();
//			UWorld* clientWorld = clientContext.World();
//
//			if(clientWorld)
//			{
//				ASteerStateManager* testClientManager = Cast<ASteerStateManager, AActor>(UGameplayStatics::GetActorOfClass(clientWorld, ASteerStateManager::StaticClass()));
//
//				if (testClientManager)
//				{
//					UE_LOG(LogTemp, Log, TEXT("centering steer state manager..."));
//					testClientManager->center();
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}













//Test check commands:


bool FCheckSteerStateManagerCurrentState::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		if (testManager)
		{
			UE_LOG(LogTemp, Log, TEXT("current state: %s"), *testManager->currentState()->GetName());
			bool statesMatch = testManager->currentState()->GetClass() == expectedState;
			if (statesMatch)
			{
				test->TestTrue(test->conditionMessage(), statesMatch);
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}


bool FCheckSteerStateManagerCurrentStateAgainstPreviousOnSteerLeft::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();

		if (testManager && testJet)
		{
			testManager->setOwningJet(testJet);
			testManager->steerLeft();
			UE_LOG(LogTemp, Log, TEXT("previous state: %s"), *(previousState ? previousState->GetName() : FString("nullptr")));
			USteerState* currentState = testManager->currentState();
			UE_LOG(LogTemp, Log, TEXT("current state: %s"), *currentState->GetName());

			bool statesMatch = currentState == previousState;
			if (statesMatch)
			{
				test->TestTrue(test->conditionMessage(), statesMatch);
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
			previousState = currentState;
			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}


bool FCheckSteerStateManagerCurrentStateAgainstPreviousOnSteerRight::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();

		if (testManager && testJet)
		{
			testManager->setOwningJet(testJet);
			testManager->steerRight();
			UE_LOG(LogTemp, Log, TEXT("previous state: %s"), *(previousState ? previousState->GetName() : FString("nullptr")));
			USteerState* currentState = testManager->currentState();
			UE_LOG(LogTemp, Log, TEXT("current state: %s"), *currentState->GetName());

			bool statesMatch = currentState == previousState;
			if (statesMatch)
			{
				test->TestTrue(test->conditionMessage(), statesMatch);
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
			previousState = currentState;
			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}


bool FCheckSteerStateManagerCurrentStateAgainstPreviousOnCenter::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ASteerStateManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ASteerStateManagerMOCK>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();

		if (testManager && testJet)
		{
			testManager->setOwningJet(testJet);
			testManager->center();
			UE_LOG(LogTemp, Log, TEXT("previous state: %s"), *(previousState ? previousState->GetName() : FString("nullptr")));
			USteerState* currentState = testManager->currentState();
			UE_LOG(LogTemp, Log, TEXT("current state: %s"), *currentState->GetName());

			bool statesMatch = currentState == previousState;
			if (statesMatch)
			{
				test->TestTrue(test->conditionMessage(), statesMatch);
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
			previousState = currentState;
			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}


//bool FCheckSteerStateManagerServerAndClientExpectedState::Update()
//{
//	if(GEditor->IsPlayingSessionInEditor())
//	{
//		FWorldContext serverContext = NetworkedPIESessionUtilities::retrieveServerWorldContext(clientQuantity);
//		UWorld* serverWorld = serverContext.World();
//
//		if(serverWorld)
//		{
//			FWorldContext clientContext = NetworkedPIESessionUtilities::retrieveClientWorldContext();
//			UWorld* clientWorld = clientContext.World();
//
//			if(clientWorld)
//			{
//				UE_LOG(LogTemp, Log, TEXT("retrieving steer state manager for checking..."));
//				ASteerStateManagerMOCK* testServerManager = Cast<ASteerStateManagerMOCK, AActor>(UGameplayStatics::GetActorOfClass(serverWorld, ASteerStateManagerMOCK::StaticClass()));
//				ASteerStateManagerMOCK* testClientManager = Cast<ASteerStateManagerMOCK, AActor>(UGameplayStatics::GetActorOfClass(clientWorld, ASteerStateManagerMOCK::StaticClass()));
//				bool statesMatch = false;
//				if(testClientManager)
//				{
//					bool clientStateIsTheExpected = testClientManager->currentState()->GetClass() == expectedStateClass;
//					bool serverStateIsTheExpected = testServerManager->currentState()->GetClass() == expectedStateClass;
//					statesMatch = serverStateIsTheExpected && clientStateIsTheExpected;
//				}
//
//				if(statesMatch)
//				{
//					test->TestTrue(test->conditionMessage(), statesMatch);
//					for(auto context : GEditor->GetWorldContexts())
//					{
//						context.World()->bDebugFrameStepExecution = true;
//					}
//					return true;
//				}
//				return test->manageTickCountTowardsLimit();
//			}
//		}
//	}
//	return false;
//}






#endif //WITH_DEV_AUTOMATION_TESTS
