// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GamblerChracter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CROPOUTSAMPLEPROJECT_API AGamblerChracter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGamblerChracter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 탑 다운 카메라를 위한 스프링 암 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	// 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 이동 함수 선언
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	// 상호작용 함수
	void PerformInteraction();
};
