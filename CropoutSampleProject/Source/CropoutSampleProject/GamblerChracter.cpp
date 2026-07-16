// Fill out your copyright notice in the Description page of Project Settings.

#include "GamblerChracter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGamblerChracter::AGamblerChracter()
{
	// 매 Tick마다 호출되도록 설정
	PrimaryActorTick.bCanEverTick = true;

	// 1. 카메라(컨트롤러)의 회전에 캐릭터가 억지로 따라 돌지 않게 차단합니다.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	// 2. 캐릭터 무브먼트 컴포넌트의 '이동 방향으로 회전(OrientRotationToMovement)' 기능을 켭니다.
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// 3. 캐릭터가 회전하는 속도(부드러움)를 설정합니다. (원하는 대로 조절 가능)
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// SpringArmComp 생성 및 부착
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	// SpringArmComp 설정
	SpringArmComp->TargetArmLength = 600.0f; // 카메라와 캐릭터 사이의 거리
	SpringArmComp->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f)); // 카메라 각도 설정
	SpringArmComp->bUsePawnControlRotation = true; // 캐릭터 회전에 따라 카메라 회전

	// CameraComp 생성 및 부착
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false; // 캐릭터 회전에 따라 카메라 회전
}


// Called when the game starts or when spawned
void AGamblerChracter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGamblerChracter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGamblerChracter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGamblerChracter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGamblerChracter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput); // 좌우 회전 (마우스 X)
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput); // 상하 회전 (마우스 Y)
}

void AGamblerChracter::MoveForward(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		// 카메라가 바라보는 방향을 기준으로 앞/뒤 벡터를 구함
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void AGamblerChracter::MoveRight(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		// 카메라가 바라보는 방향을 기준으로 좌/우 벡터를 구함
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}
}
