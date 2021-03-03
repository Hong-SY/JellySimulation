// Fill out your copyright notice in the Description page of Project Settings.


#include "JellyMovementComponent.h"
#include "JellyAIController.h"
#include "JellyActor.h"
#include "NavigationSystem.h"

void UJellyMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ��� ���� ���� ��ȿ����, �̵� �������� Ȯ���մϴ�.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }
    // Get AIContorller from JellyActor
    AJellyActor* CurrentJelly = Cast<AJellyActor>(GetPawnOwner());

    if (CurrentJelly->GetVelocity() != FVector::ZeroVector) {
        return;
    }
    else {
        AJellyAIController* controller = Cast<AJellyAIController>(CurrentJelly->GetController());

        controller->RandomMove();

        UE_LOG(LogTemp, Log, TEXT("Movement Component"));
    }
    
};