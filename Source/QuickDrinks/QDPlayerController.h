// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/MainMenuWidget.h"
#include "QDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class QUICKDRINKS_API AQDPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;
};
