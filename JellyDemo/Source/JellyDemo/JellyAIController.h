// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "JellyAIController.generated.h"

/**
 * Jelly AI controller
 */
UCLASS()
class JELLYDEMO_API AJellyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AJellyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	void RandomMove();
	class UNavigationSystemV1* JellyNavi;

protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle RepeatTimerHandle;
	float RepeatInterval;
};
