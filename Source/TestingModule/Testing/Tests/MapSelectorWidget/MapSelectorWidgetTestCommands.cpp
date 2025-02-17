// Fill out your copyright notice in the Description page of Project Settings.


#if WITH_DEV_AUTOMATION_TESTS

#include "MapSelectorWidgetTestCommands.h"
#include "UI/MapSelectorWidget.h"
#include "UI/StringHolderButton.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "../../Utilities/BlueprintWidgetContainerPawn.h"
#include "../../Utilities/PIESessionUtilities.h"

//Test preparation commands:



//Test check commands:


bool FCheckMapSelectorCreatesButtonsAsMapsFound::Update()
{
	if(GEditor->IsPlayingSessionInEditor())
	{
		PIESessionUtilities sessionUtilities = PIESessionUtilities();
		ABlueprintWidgetContainerPawn* testContainer = sessionUtilities.retrieveFromPIEAnInstanceOf<ABlueprintWidgetContainerPawn>();
		
		if(testContainer)
		{
			UMapSelectorWidget* testSelector = Cast<UMapSelectorWidget, UUserWidget>(testContainer->retrieveWidget());

			if(!testSelector->IsInViewport())
			{
				testSelector->AddToViewport();
				FInputModeUIOnly inputModeData;
				inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
				inputModeData.SetWidgetToFocus(testSelector->TakeWidget());
				APlayerController* controller = sessionUtilities.currentPIEWorld()->GetFirstPlayerController();
				controller->SetInputMode(inputModeData);
				controller->bShowMouseCursor = true;
			}
			TArray<UUserWidget*> buttonsMade = TArray<UUserWidget*>();
			UWidgetBlueprintLibrary::GetAllWidgetsOfClass(sessionUtilities.currentPIEWorld(),buttonsMade, UStringHolderButton::StaticClass(), false);
			
			TArray<FString> mapsFound = TArray<FString>();
			mapsFound = testSelector->mapsCollected();
			
			bool numbersCoincident = buttonsMade.Num() == mapsFound.Num();
			if(numbersCoincident)
			{
				test->TestTrue(test->conditionMessage(), numbersCoincident);
				sessionUtilities.currentPIEWorld()->bDebugFrameStepExecution = true;
				return true;
			}
			return test->manageTickCountTowardsLimit();
		}
	}
	return false;
}




#endif //WITH_DEV_AUTOMATION_TESTS
