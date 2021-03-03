// Fill out your copyright notice in the Description page of Project Settings.


#include "JellyAIController.h"
#include "JellyActor.h"
#include "AITypes.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


void AJellyAIController::BeginPlay()
{
	Super::BeginPlay();
}

AJellyAIController::AJellyAIController()
{
	RepeatTimerHandle = FTimerHandle();
	//RepeatInterval = 6.0f;
	JellyNavi = UNavigationSystemV1::GetNavigationSystem(GetWorld());
}

void AJellyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// ���� �ð����� �Լ��� �����ϰ���
	//GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &AJellyAIController::RandomMove, RepeatInterval, true);
}

void AJellyAIController::OnUnPossess()
{
	Super::OnUnPossess();
	//GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
}

void AJellyAIController::RandomMove()
{
	AJellyActor* CurrentJelly = Cast<AJellyActor>(GetPawn());

	if (CurrentJelly) {
		//float radius = 0.01f * CurrentJelly->getActivity();
		float radius = 300.0f;

		FNavLocation NextLocation;

		FVector JellyLocation = CurrentJelly->GetActorLocation();

		JellyNavi->GetRandomReachablePointInRadius(JellyLocation, radius, NextLocation);

		FAIMoveRequest destination = FAIMoveRequest(NextLocation.Location);

		this->MoveTo(destination);
	}
}