#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CasinoTypes.h"
#include "CasinoGameInstance.generated.h"

UCLASS()
class CROPOUTSAMPLEPROJECT_API UCasinoGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCasinoGameInstance();

	virtual void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Casino|Data")
	int32 PlayerGold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Casino|Data")
	EGambleType CurrentGambleType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Casino|Data")
	float CurrentMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Casino|Data")
	bool bLastResultSuccess;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Casino|Data")
	ECasinoGameState GameState;
};
