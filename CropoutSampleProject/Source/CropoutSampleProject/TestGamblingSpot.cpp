// Fill out your copyright notice in the Description page of Project Settings.

#include "TestGamblingSpot.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "CasinoGameInstance.h"
#include "Kismet/GameplayStatics.h"

ATestGamblingSpot::ATestGamblingSpot()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	// 기본값 세팅
	SpotGambleType = EGambleType::Tree;
	TargetLevelName = TEXT("LV_Gamble_Tree");
}

void ATestGamblingSpot::Interact_Implementation(AActor* Interactor)
{
	// 1. 게임 인스턴스 가져오기 및 데이터 세팅
	UCasinoGameInstance* GameInst = Cast<UCasinoGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (GameInst)
	{
		GameInst->CurrentGambleType = SpotGambleType;
		GameInst->GameState = ECasinoGameState::Gambling;
		
		UE_LOG(LogTemp, Warning, TEXT("C++: [%s] 도박장 진입 시도. 현재 골드: %d"), *TargetLevelName.ToString(), GameInst->PlayerGold);
		
		if (GEngine)
		{
			FString Msg = FString::Printf(TEXT("도박장 진입! 골드: %dG"), GameInst->PlayerGold);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Msg);
		}
	}

	// 2. 레벨 이동
	if (!TargetLevelName.IsNone())
	{
		UGameplayStatics::OpenLevel(this, TargetLevelName);
	}
}
