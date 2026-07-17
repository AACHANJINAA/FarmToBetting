#pragma once

#include "CoreMinimal.h"
#include "CasinoTypes.generated.h"

UENUM(BlueprintType)
enum class EGambleType : uint8
{
	None UMETA(DisplayName = "None"),
	Tree UMETA(DisplayName = "Golden Tree"),
	Race UMETA(DisplayName = "Resident Race"),
	Stock UMETA(DisplayName = "Stock Market")
};

UENUM(BlueprintType)
enum class ECasinoGameState : uint8
{
	Village UMETA(DisplayName = "Village"),
	Gambling UMETA(DisplayName = "Gambling"),
	Result UMETA(DisplayName = "Result"),
	GameOver UMETA(DisplayName = "Game Over")
};
