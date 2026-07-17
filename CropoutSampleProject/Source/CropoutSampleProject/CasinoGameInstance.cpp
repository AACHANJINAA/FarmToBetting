#include "CasinoGameInstance.h"

UCasinoGameInstance::UCasinoGameInstance()
{
	// 기획서에 명시된 초기 자본금 1000G 세팅
	PlayerGold = 1000;
	CurrentGambleType = EGambleType::None;
	CurrentMultiplier = 1.0f;
	bLastResultSuccess = false;
	GameState = ECasinoGameState::Village;
}

void UCasinoGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("CasinoGameInstance 초기화 완료. 초기 골드: %d"), PlayerGold);
}
