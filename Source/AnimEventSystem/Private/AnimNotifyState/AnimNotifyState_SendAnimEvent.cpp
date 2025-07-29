// Copyright Blazebone Game Studio


#include "AnimNotifyState/AnimNotifyState_SendAnimEvent.h"

void UAnimNotifyState_SendAnimEvent::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                                 float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (EventName.IsNone())
	{
		return;
	}

	if (!IsValid(MeshComp))
	{
		return;
	}

	if (!IsValid(MeshComp->GetOwner()))
	{
		return;
	}

	const UAnimEventSystemComponent* AnimEventSystemComponent = Cast<UAnimEventSystemComponent>(
		MeshComp->GetOwner()->GetComponentByClass(UAnimEventSystemComponent::StaticClass()));
	if (!IsValid(AnimEventSystemComponent))
	{
		return;
	}

	AnimEventSystemComponent->SendAnimEvent(EventName, EAnimEventType::Start, TotalDuration,
	                                        EventReference.GetCurrentAnimationTime());
}

void UAnimNotifyState_SendAnimEvent::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                               const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (EventName.IsNone())
	{
		return;
	}

	if (!IsValid(MeshComp))
	{
		return;
	}

	if (!IsValid(MeshComp->GetOwner()))
	{
		return;
	}

	const UAnimEventSystemComponent* AnimEventSystemComponent = Cast<UAnimEventSystemComponent>(
		MeshComp->GetOwner()->GetComponentByClass(UAnimEventSystemComponent::StaticClass()));
	if (!IsValid(AnimEventSystemComponent))
	{
		return;
	}

	AnimEventSystemComponent->SendAnimEvent(EventName, EAnimEventType::End, Animation->GetPlayLength(),
	                                        EventReference.GetCurrentAnimationTime());
}

FString UAnimNotifyState_SendAnimEvent::GetNotifyName_Implementation() const
{
	FString DebugString = "SendAnimEvent: ";
	if (EventName.IsNone())
	{
		DebugString += "None";
	}
	else
	{
		DebugString += EventName.ToString();
	}
	return DebugString;
}
