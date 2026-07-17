// Fill out your copyright notice in the Description page of Project Settings.

#include "TestGamblingSpot.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

ATestGamblingSpot::ATestGamblingSpot()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void ATestGamblingSpot::Interact_Implementation(AActor* Interactor)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("C++: 상호작용 성공! 도박장으로 이동합니다."));
	}
	
	UE_LOG(LogTemp, Warning, TEXT("C++: 상호작용 발생. 주체: %s"), Interactor ? *Interactor->GetName() : TEXT("Unknown"));
}
