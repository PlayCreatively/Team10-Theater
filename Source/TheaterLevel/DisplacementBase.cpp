// Fill out your copyright notice in the Description page of Project Settings.


#include "DisplacementBase.h"

static float EaseInOut(float t)
{
	return .5f + cos(PI * t + PI) * .5f;
}

void UDisplacementBase::TickDisplacement(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Red, FString::Printf(TEXT("IsDisplacing: %d"), isDisplacing));
	if (isDisplacing)
	{
		curTime += DeltaTime * direction;
		float t = curTime / Time;
		if (direction == 1 && t >= 1.0f)
		{
			t = 1.0f;
			curTime = Time;
			isDisplacing = false;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "target reached!");
		}
		else if (direction == -1 && t <= 0.0f)
		{
			t = 0.0f;
			curTime = 0.0f;
			isDisplacing = false;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "target reached!");
		}
		float ease = EaseInOut(t);
		FVector newPos = startPos + Displacement * ease;
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, FString::Printf(TEXT("Displacement: %s"), *(Displacement * ease).ToString()));
		SetRelativeLocation(newPos);
	}
}

void UDisplacementBase::Trigger()
{
	direction *= -1.0f;
	isDisplacing = true;
}

// Sets default values for this component's properties
UDisplacementBase::UDisplacementBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UDisplacementBase::BeginPlay()
{
	Super::BeginPlay();
	startPos = GetRelativeLocation();
	// ...
	
}


// Called every frame
void UDisplacementBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

