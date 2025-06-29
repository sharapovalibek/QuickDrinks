// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "ConfirmationWidget.h"
#include "OrderMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (OpenOrderMenuButton)
	{
		OpenOrderMenuButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandleOpenOrderClicked);
	}

	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandleExitClicked);
	}

	if (OrderMenuWidget)
	{
		OrderMenuWidget->OnOrderConfirmed.AddDynamic(this, &UMainMenuWidget::HandleOrderConfirmed);
		OrderMenuWidget->OnBack.AddDynamic(this, &UMainMenuWidget::OpenMainMenu);
	}

	if (ConfirmationWidget)
	{
		ConfirmationWidget->OnBack.AddDynamic(this, &UMainMenuWidget::OpenMainMenu);
	}
}

void UMainMenuWidget::HandleOpenOrderClicked()
{
	OpenOrderMenu();
}

void UMainMenuWidget::HandleExitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}

void UMainMenuWidget::HandleOrderConfirmed(EDrinkType Drink, bool bMilk, bool bSugar)
{
	if (ConfirmationWidget)
	{
		ConfirmationWidget->SetOrderSummary(Drink, bMilk, bSugar);
		OpenConfirmationMenu();
	}
}

void UMainMenuWidget::OpenMainMenu()
{
	if (MenuSwitcher)
	{
		MenuSwitcher->SetActiveWidgetIndex(0);
	}
}

void UMainMenuWidget::OpenOrderMenu()
{
	if (MenuSwitcher)
	{
		OrderMenuWidget->InitOrderMenu();
		MenuSwitcher->SetActiveWidgetIndex(1);
	}
}

void UMainMenuWidget::OpenConfirmationMenu()
{
	if (MenuSwitcher)
	{
		MenuSwitcher->SetActiveWidgetIndex(2);
	}
}
