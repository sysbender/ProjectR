// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BlueprintWidgetContainerPawn.generated.h"

UCLASS()
class TESTINGMODULE_API ABlueprintWidgetContainerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABlueprintWidgetContainerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category= "Widget")
		TSubclassOf<UUserWidget> widgetClass;

	UPROPERTY()
		UUserWidget* widget;

public:	
	UUserWidget* retrieveWidget();

};
