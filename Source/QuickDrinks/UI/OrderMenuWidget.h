// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuickDrinks/DrinkType.h"
#include "OrderMenuWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnOrderConfirmed, EDrinkType, Drink, bool, bMilk, bool, bSugar);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOrderBack);
/**
 * 
 */
UCLASS()
class QUICKDRINKS_API UOrderMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnOrderConfirmed OnOrderConfirmed;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnOrderBack OnBack;

	UFUNCTION()
	void InitOrderMenu();

protected:
	virtual void NativeConstruct() override;

	void ConfirmOrder();

	EDrinkType GetSelectedDrink();

	UFUNCTION()
	void HandleOrderClicked();

	UFUNCTION()
	void HandleBackClicked();

public:
	UPROPERTY(meta=(BindWidget))
	class UComboBoxString* DrinkComboBox;

	UPROPERTY(meta=(BindWidget))
	class UCheckBox* CheckBox_Sugar;

	UPROPERTY(meta=(BindWidget))
	class UCheckBox* CheckBox_Milk;

	UPROPERTY(meta=(BindWidget))
	class UButton* OrderButton;

	UPROPERTY(meta=(BindWidget))
	class UButton* BackButton;
};
