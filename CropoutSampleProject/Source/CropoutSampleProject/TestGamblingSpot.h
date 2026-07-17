// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableInterface.h"
#include "CasinoTypes.h"
#include "TestGamblingSpot.generated.h"

class UStaticMeshComponent;

UCLASS()
class CROPOUTSAMPLEPROJECT_API ATestGamblingSpot : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	ATestGamblingSpot();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// 에디터에서 설정할 도박 종류
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamble")
	EGambleType SpotGambleType;

	// 상호작용 시 이동할 레벨 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamble")
	FName TargetLevelName;

	virtual void Interact_Implementation(AActor* Interactor) override;
};

