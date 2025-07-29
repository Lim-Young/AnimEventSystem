// Copyright Blazebone Game Studio

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimEventSystemComponent.generated.h"

UENUM(BlueprintType)
enum EAnimEventType : uint8
{
	Trigger,
	Start,
	End,
	Cancel
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ANIMEVENTSYSTEM_API UAnimEventSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAnimEventSystemComponent();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnReceiveAnimEvent, FName, EventName, EAnimEventType, EventType,
	                                              float, TotalDuration = 0.0f, float, CurrentTime = 0.0f);

	UPROPERTY(BlueprintAssignable, Category = "Anim Event System")
	FOnReceiveAnimEvent OnReceiveAnimEvent;

	void SendAnimEvent(const FName EventName, const EAnimEventType EventType, const float TotalDuration = 0.0f,
	                   const float CurrentTime = 0.0f) const
	{
		OnReceiveAnimEvent.Broadcast(EventName, EventType, TotalDuration, CurrentTime);
	}
};
