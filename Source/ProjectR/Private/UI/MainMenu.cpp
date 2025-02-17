// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenu.h"
#include "Components/Button.h"
#include "GameInstance/ProjectRGameInstance.h"


bool UMainMenu::Initialize()
{
	bool initializeResult = Super::Initialize();
	if (quitButton)
	{
		quitButton->OnClicked.AddDynamic(this, &UMainMenu::quit);
		quitButton->OnPressed.AddDynamic(this, &UMainMenu::quit);
		quitButton->IsFocusable = true;
		quitButton->SetClickMethod(EButtonClickMethod::MouseDown);
	}
	if (singleplayerButton)
	{
		singleplayerButton->OnClicked.AddDynamic(this, &UMainMenu::bringSingleplayerMenu);
		singleplayerButton->OnPressed.AddDynamic(this, &UMainMenu::bringSingleplayerMenu);
		singleplayerButton->IsFocusable = true;
		singleplayerButton->SetClickMethod(EButtonClickMethod::MouseDown);
	}
	if (localMultiplayerButton)
	{
		localMultiplayerButton->OnClicked.AddDynamic(this, &UMainMenu::bringLocalMultiplayerMenu);
		localMultiplayerButton->OnPressed.AddDynamic(this, &UMainMenu::bringLocalMultiplayerMenu);
		localMultiplayerButton->IsFocusable = true;
		localMultiplayerButton->SetClickMethod(EButtonClickMethod::MouseDown);
	}

	if (lanMultiplayerButton)
	{
		lanMultiplayerButton->OnClicked.AddDynamic(this, &UMainMenu::bringLanMultiplayerMenu);
		lanMultiplayerButton->OnPressed.AddDynamic(this, &UMainMenu::bringLanMultiplayerMenu);
		lanMultiplayerButton->IsFocusable = true;
		lanMultiplayerButton->SetClickMethod(EButtonClickMethod::MouseDown);
	}
	bIsFocusable = true;
	return initializeResult;
}

FVector2D UMainMenu::quitButtonAbsoluteCenterPosition()
{
	return buttonAbsoluteCenterPosition(quitButton);
}

FVector2D UMainMenu::singleplayerButtonAbsoluteCenterPosition()
{
	return buttonAbsoluteCenterPosition(singleplayerButton);
}

FVector2D UMainMenu::localMultiplayerButtonAbsoluteCenterPosition()
{
	return buttonAbsoluteCenterPosition(localMultiplayerButton);
}

FVector2D UMainMenu::lanMultiplayerButtonAbsoluteCenterPosition()
{
	return buttonAbsoluteCenterPosition(lanMultiplayerButton);
}


void UMainMenu::quit()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

void UMainMenu::bringSingleplayerMenu()
{
	RemoveFromParent();
	UProjectRGameInstance* gameInstance = Cast<UProjectRGameInstance, UGameInstance>(GetWorld()->GetGameInstance());
	
	gameInstance->loadSingleplayerMenu();
}

void UMainMenu::bringLocalMultiplayerMenu()
{
	RemoveFromParent();
	UProjectRGameInstance* gameInstance = Cast<UProjectRGameInstance, UGameInstance>(GetWorld()->GetGameInstance());
	
	gameInstance->loadLocalMultiplayerMenu();
}

void UMainMenu::bringLanMultiplayerMenu()
{
	RemoveFromParent();
	UProjectRGameInstance* gameInstance = Cast<UProjectRGameInstance, UGameInstance>(GetWorld()->GetGameInstance());
	
	gameInstance->loadLANMUltiplayerMenu();
}
