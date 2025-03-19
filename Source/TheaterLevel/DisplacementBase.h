// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DisplacementBase.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEATERLEVEL_API UDisplacementBase : public USceneComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Displacement")
	FVector Displacement{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Displacement")
	float Time{};

	float curTime{};
	FVector startPos{};
	bool isDisplacing{};
	float direction{-1.0f};

	UFUNCTION(BlueprintCallable, Category = "Displacement")
	void TickDisplacement(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Displacement")
	void Trigger();

	// Sets default values for this component's properties
	UDisplacementBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
