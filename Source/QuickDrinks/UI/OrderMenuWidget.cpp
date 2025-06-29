// Fill out your copyright notice in the Description page of Project Settings.


#include "OrderMenuWidget.h"

#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"

void UOrderMenuWidget::InitOrderMenu()
{
	DrinkComboBox->ClearOptions();

	UEnum* EnumPtr = StaticEnum<EDrinkType>();
	for (int32 i = 0; i < EnumPtr->NumEnums() - 1; i++)
	{
		FString DisplayName = EnumPtr->GetDisplayNameTextByIndex(i).ToString();
		DrinkComboBox->AddOption(DisplayName);
	}

	if (EnumPtr->NumEnums() > 1)
	{
		FString FirstOption = EnumPtr->GetDisplayNameTextByIndex(0).ToString();
		DrinkComboBox->SetSelectedOption(FirstOption);
	}

	if (CheckBox_Milk)
	{
		CheckBox_Milk->SetIsChecked(false);
	}
	if (CheckBox_Sugar)
	{
		CheckBox_Sugar->SetIsChecked(false);
	}
}

void UOrderMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitOrderMenu();

	if (OrderButton)
	{
		OrderButton->OnClicked.AddDynamic(this, &UOrderMenuWidget::HandleOrderClicked);
	}

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &UOrderMenuWidget::HandleBackClicked);
	}
}

void UOrderMenuWidget::ConfirmOrder()
{
	EDrinkType SelectedDrink = GetSelectedDrink();
	bool bMilk = CheckBox_Milk ? CheckBox_Milk->IsChecked() : false;
	bool bSugar = CheckBox_Sugar ? CheckBox_Sugar->IsChecked() : false;
	
	OnOrderConfirmed.Broadcast(SelectedDrink, bMilk, bSugar);
}

EDrinkType UOrderMenuWidget::GetSelectedDrink()
{
	if (DrinkComboBox == nullptr)
	{
		return EDrinkType::Tea;
	}

	const FString SelectedStr = DrinkComboBox->GetSelectedOption();
	const UEnum* EnumPtr = StaticEnum<EDrinkType>();
	for (int32 i = 0; i < EnumPtr->NumEnums() - 1; i++)
	{
		if (SelectedStr == EnumPtr->GetDisplayNameTextByIndex(i).ToString())
		{
			return static_cast<EDrinkType>(i);
		}
	}

	return EDrinkType::Tea;
}

void UOrderMenuWidget::HandleOrderClicked()
{
	ConfirmOrder();
}

void UOrderMenuWidget::HandleBackClicked()
{
	OnBack.Broadcast();
}
