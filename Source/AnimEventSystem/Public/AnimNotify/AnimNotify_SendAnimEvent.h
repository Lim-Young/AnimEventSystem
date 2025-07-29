// Copyright Blazebone Game Studio

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_SendAnimEvent.generated.h"

/**
 * Send Anim Event To Owning Actor
 */
UCLASS(DisplayName = "Send Anim Event")
class ANIMEVENTSYSTEM_API UAnimNotify_SendAnimEvent : public UAnimNotify
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Anim Event System")
	FName EventName;

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	                    const FAnimNotifyEventReference& EventReference) override;
	virtual FString GetNotifyName_Implementation() const override;
};
