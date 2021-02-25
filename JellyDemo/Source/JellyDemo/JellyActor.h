// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "JellyActor.generated.h"
//#include "JellyActorComponent.h"

// Jelly status structure
USTRUCT(Atomic, BlueprintType)
struct FJellyStatus
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Aggression = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Activity = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Reproductivity = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Endurability = 50;
};


UCLASS()
class JELLYDEMO_API AJellyActor : public AActor
{
	GENERATED_BODY()

public:
	// Custom Component to attach Jelly
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* JellySkin;

private:
	UPROPERTY(EditAnywhere)
	FJellyStatus Status;

public:	
	// Sets default values for this actor's properties
	AJellyActor();
	AJellyActor(FString type);

	// Getter and setter for status
	int getAgrresion(AJellyActor Jelly);
	void setAggresion(AJellyActor Jelly);
	void setAggresion(int i);

	int getActivity(AJellyActor Jelly);
	void setActivity(AJellyActor Jelly);
	void setActivity(int i);

	int getReproductivity(AJellyActor Jelly);
	void setReproductivity(AJellyActor Jelly);
	void setReproductivity(int i);

	int getEndurability(AJellyActor Jelly);
	void setEndurability(AJellyActor Jelly);
	void setEndurability(int i);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Survive(AJellyActor Jelly); //, ATerrain terrain)
};


void setJellySkin(FString type, UStaticMeshComponent* JellySkin);