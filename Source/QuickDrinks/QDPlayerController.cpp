// Fill out your copyright notice in the Description page of Project Settings.


#include "QDPlayerController.h"

#include "Blueprint/UserWidget.h"

void AQDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController() && MainMenuWidgetClass)
	{
		UMainMenuWidget* WidgetInstance = CreateWidget<UMainMenuWidget>(this, MainMenuWidgetClass);
		if (WidgetInstance)
		{
			WidgetInstance->AddToViewport();
			FInputModeGameAndUI InputMode;
			InputMode.SetWidgetToFocus(WidgetInstance->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			SetInputMode(InputMode);
			bShowMouseCursor = true;
		}
	}
}
