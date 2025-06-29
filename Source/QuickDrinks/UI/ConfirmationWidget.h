// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuickDrinks/DrinkType.h"
#include "ConfirmationWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConfirmationBack);

/**
 * 
 */
UCLASS()
class QUICKDRINKS_API UConfirmationWidget : public UUserWidget
{
	GENERATED_BODY()

	static FString PrintOptions(bool bMilk, bool bSugar);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnConfirmationBack OnBack;

	void SetOrderSummary(EDrinkType Drink, bool bMilk, bool bSugar);

protected:
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void HandleBackClicked();

public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* Text_OrderSummary;

	UPROPERTY(meta=(BindWidget))
	class UButton* BackButton;
};
