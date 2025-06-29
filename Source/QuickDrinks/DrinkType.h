#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "DrinkType.generated.h"

UENUM(BlueprintType)
enum class EDrinkType : uint8
{
	Tea		UMETA(DisplayName = "Чай"),
	Coffee	UMETA(DisplayName = "Кофе"),
	Juice	UMETA(DisplayName = "Сок"),
	Water	UMETA(DisplayName = "Вода"),
	Alcohol	UMETA(DisplayName = "Алкоголь"),
	Beer	UMETA(DisplayName = "Пиво"),
	Max		UMETA(Hidden)
};