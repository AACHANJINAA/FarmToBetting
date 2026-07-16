#pragma once
#include"CoreMinimal.h"
#include"Animation/AnimInstance.h"
#include"GamblerAnimInstance.generated.h"

UCLASS()
class CROPOUTSAMPLEPROJECT_API UGamblerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds)override;
	virtual void NativeInitializeAnimation()override;
protected:
	// 블루프린트에서 이 스피드 값을 가져다 쓸 수 있게 BlueprintReadOnly를 붙입니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	float CurrentSpeed;
	class AGamblerChracter* OwnerCharacter;
};