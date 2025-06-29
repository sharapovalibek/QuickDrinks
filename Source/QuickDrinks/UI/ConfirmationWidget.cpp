// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfirmationWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

FString UConfirmationWidget::PrintOptions(const bool bMilk, const bool bSugar)
{
	if (!(bMilk || bSugar))
	{
		return TEXT("");
	}

	TArray<FString> Options;
	if (bMilk)
	{
		Options.Add(TEXT("молоком"));
	}
	if (bSugar)
	{
		Options.Add(TEXT("сахаром"));
	}

	return TEXT("с ") + FString::Join(Options, TEXT(" и "));
}

void UConfirmationWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &UConfirmationWidget::HandleBackClicked);
	}
}

void UConfirmationWidget::SetOrderSummary(EDrinkType Drink, const bool bMilk, const bool bSugar)
{
	FString SelectedDrink = StaticEnum<EDrinkType>()->GetDisplayNameTextByValue(static_cast<int64>(Drink)).ToString();
	FString Options = PrintOptions(bMilk, bSugar);
	FString Result = FString::Printf(TEXT("Вы заказали: %s %s"),
		*SelectedDrink,
		*Options
		);

	if (Text_OrderSummary)
	{
		Text_OrderSummary->SetText(FText::FromString(Result));
	}
}

void UConfirmationWidget::HandleBackClicked()
{
	OnBack.Broadcast();
}
