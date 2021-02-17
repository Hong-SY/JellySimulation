// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JellyStatus.h"
#include "JellyActor.generated.h"

UCLASS()
class JELLYDEMO_API AJellyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJellyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	FJellyStatus status;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
