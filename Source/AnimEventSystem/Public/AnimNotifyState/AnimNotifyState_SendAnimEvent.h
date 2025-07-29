// Copyright Blazebone Game Studio

#pragma once

#include "CoreMinimal.h"
#include "AnimEventSystemComponent.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_SendAnimEvent.generated.h"

/**
 * Send Anim Event To Owning Actor
 */
UCLASS(DisplayName = "Send Anim Event")
class ANIMEVENTSYSTEM_API UAnimNotifyState_SendAnimEvent : public UAnimNotifyState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Anim Event System")
	FName EventName;

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration,
		const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
		const FAnimNotifyEventReference& EventReference) override;
	virtual FString GetNotifyName_Implementation() const override;
};
