// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "JellyMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class JELLYDEMO_API UJellyMovementComponent : public UFloatingPawnMovement
{
	GENERATED_BODY()

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
