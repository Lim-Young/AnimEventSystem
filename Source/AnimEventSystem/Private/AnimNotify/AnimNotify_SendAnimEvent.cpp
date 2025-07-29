// Copyright Blazebone Game Studio


#include "AnimNotify/AnimNotify_SendAnimEvent.h"

#include "AnimEventSystemComponent.h"

void UAnimNotify_SendAnimEvent::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                       const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

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

	AnimEventSystemComponent->SendAnimEvent(EventName, EAnimEventType::Trigger, Animation->GetPlayLength(),
	                                        EventReference.GetCurrentAnimationTime());
}

FString UAnimNotify_SendAnimEvent::GetNotifyName_Implementation() const
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
