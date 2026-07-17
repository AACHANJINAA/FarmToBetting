// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableInterface.h"
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

	virtual void Interact_Implementation(AActor* Interactor) override;
};
