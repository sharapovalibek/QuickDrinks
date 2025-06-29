// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuickDrinks/DrinkType.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUICKDRINKS_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void HandleOpenOrderClicked();

	UFUNCTION()
	void HandleExitClicked();

	UFUNCTION()
	void HandleOrderConfirmed(EDrinkType Drink, bool bMilk, bool bSugar);

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void OpenOrderMenu();

	UFUNCTION()
	void OpenConfirmationMenu();

public:
	UPROPERTY(meta=(BindWidget))
	class UButton* OpenOrderMenuButton;

	UPROPERTY(meta=(BindWidget))
	class UButton* ExitButton;

	UPROPERTY(meta=(BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta=(BindWidget))
	class UOrderMenuWidget* OrderMenuWidget;

	UPROPERTY(meta=(BindWidget))
	class UConfirmationWidget* ConfirmationWidget;
};
