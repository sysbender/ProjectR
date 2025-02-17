// Fill out your copyright notice in the Description page of Project Settings.






#if WITH_DEV_AUTOMATION_TESTS

#include "TrackManagerTestCommands.h"
#include "Kismet/GameplayStatics.h"
#include "Track/TrackManager.h"
#include "../../Mocks/TrackManagerMOCK.h"
#include "Track/TrackGenerator.h"
#include "Jet/Jet.h"

#include "Tests/AutomationEditorCommon.h"
#include "../../Utilities/PIESessionUtilities.h"

//Test preparation commands:



bool FSpawningARotatedTrackGeneratorAndJetCloseToIt::Update()
{
	if (!GEditor->IsPlayingSessionInEditor())
	{
		return false;
	}

	PIESessionUtilities sessionUtilities = PIESessionUtilities();


	UWorld* testWorld = sessionUtilities.defaultPIEWorld();

	ATrackGenerator* testGenerator = sessionUtilities.spawnInPIEAnInstanceOf<ATrackGenerator>();

	FRotator arbitraryRotator = FRotator(0, 0, 135);
	testGenerator->SetActorRotation(arbitraryRotator);

	FVector generatorDirection = testGenerator->GetActorUpVector();
	float magnetBoxDistanceToFloor = 400;
	FVector jetLoctation = generatorDirection * magnetBoxDistanceToFloor;

	sessionUtilities.spawnInPIEAnInstanceOf<AJet>(jetLoctation);

	return true;
}







//Test check commands:

bool FCheckATrackManagerTrackGenerators::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		UWorld* testWorld = sessionUtilities.defaultPIEWorld();
		ATrackManagerMOCK* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ATrackManagerMOCK>();
		if (testManager)
		{
			bool spawnedTrackGeneratorInTrackManager = testManager->trackGenerators().Contains(Cast<ATrackGenerator, AActor>(UGameplayStatics::GetActorOfClass(testWorld, ATrackGenerator::StaticClass())));

			UE_LOG(LogTemp, Log, TEXT("Track manager %s the track generator listed."), *FString(spawnedTrackGeneratorInTrackManager ? "has" : "doesn't have"));
			test->increaseTickCount();
			if (test->tickCountExceedsLimit())
			{
				test->TestTrue(test->conditionMessage(), spawnedTrackGeneratorInTrackManager);
				testWorld->bDebugFrameStepExecution = true;
				return true;
			}
		}
	}
	return false;
}


bool FCheckATrackManagerStoresJetsWhenOverlap::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		UWorld* testWorld = sessionUtilities.defaultPIEWorld();
		ATrackManager* testManager = sessionUtilities.retrieveFromPIEAnInstanceOf<ATrackManager>();
		if (testManager)
		{
			bool hasJetsStored = testManager->hasJetsStored();
			UE_LOG(LogTemp, Log, TEXT("track manager has jets stored: %s"), *FString(hasJetsStored ? "true" : "false"));

			if (hasJetsStored)
			{
				test->TestTrue(test->conditionMessage(), hasJetsStored);
				testWorld->bDebugFrameStepExecution = true;
				return true;
			}
			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}


bool FCheckATrackManagerAttractsJets::Update()
{
	if (GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		UWorld* testWorld = sessionUtilities.defaultPIEWorld();
		ATrackGenerator* testGenerator = sessionUtilities.retrieveFromPIEAnInstanceOf<ATrackGenerator>();
		AJet* testJet = sessionUtilities.retrieveFromPIEAnInstanceOf<AJet>();
		if (testGenerator && testJet)
		{
			float currentDistance = (testJet->GetActorLocation() - testGenerator->GetActorLocation()).Size();
			bool isPulling = currentDistance < aPreviousDistance;
			bool isVelocityFullyAlongNormal = FMath::IsNearlyEqual(testJet->GetVelocity().ProjectOnTo(testGenerator->GetActorUpVector()).Size(), testJet->GetVelocity().Size(), 0.1f);
			bool velocityNearZero = FMath::IsNearlyZero(testJet->GetVelocity().Size(), 0.1f);

			UE_LOG(LogTemp, Log, TEXT("previous distance between track generator and jet: %f"), aPreviousDistance);
			UE_LOG(LogTemp, Log, TEXT("current distance between track generator and jet: %f"), currentDistance);
			UE_LOG(LogTemp, Log, TEXT("Jet location: %s"), *testJet->GetActorLocation().ToString());
			UE_LOG(LogTemp, Log, TEXT("Track generator location: %s"), *testGenerator->GetActorLocation().ToString());
			UE_LOG(LogTemp, Log, TEXT("Jet velocity: %s"), *testJet->GetVelocity().ToString());
			UE_LOG(LogTemp, Log, TEXT("Jet velocity projection on normal vector: %s"), *testJet->GetVelocity().ProjectOnTo(testGenerator->GetActorUpVector()).ToString());
			UE_LOG(LogTemp, Log, TEXT("Track generator normal vector: %s"), *testGenerator->GetActorUpVector().ToString());
			UE_LOG(LogTemp, Log, TEXT("is pulling: %s"), *FString(isPulling ? "true" : "false"));
			UE_LOG(LogTemp, Log, TEXT("is velocity fully along normal: %s"), *FString(isVelocityFullyAlongNormal ? "true" : "false"));
			UE_LOG(LogTemp, Log, TEXT("is velocity near zero: %s"), *FString(velocityNearZero ? "true" : "false"));

			if (!velocityNearZero && isVelocityFullyAlongNormal && isPulling)
			{
				test->TestTrue(test->conditionMessage(), !velocityNearZero && isVelocityFullyAlongNormal && isPulling);
				testWorld->bDebugFrameStepExecution = true;
				return true;
			}
			aPreviousDistance = currentDistance;

			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}



#endif //WITH_DEV_AUTOMATION_TESTS
