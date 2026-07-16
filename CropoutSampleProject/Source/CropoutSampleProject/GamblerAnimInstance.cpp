#include"GamblerAnimInstance.h"
#include"GamblerChracter.h"

void UGamblerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwnerCharacter = Cast<AGamblerChracter>(TryGetPawnOwner());
}

void UGamblerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (OwnerCharacter)
	{
		// Z축(점프/낙하) 속도는 무시하고 땅 위를 걷는 XY 속도만 구합니다.
		FVector Velocity = OwnerCharacter->GetVelocity();
		Velocity.Z = 0.0f;
		CurrentSpeed = Velocity.Size();
	}
}