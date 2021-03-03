// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h" 
#include "GameFramework/Character.h"
#include "JellyActor.generated.h" 
//#include "JellyActorComponent.h" 

// Jelly property structure : will not change after spawn.
USTRUCT(Atomic, BlueprintType)
struct FJellyProperty
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


// Jelly staus structure
USTRUCT(Atomic, BlueprintType)
struct FJellyStatus
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxHealthPoint = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentHealthPoint = 100;
};


UCLASS()
class JELLYDEMO_API AJellyActor : public APawn
{
	GENERATED_BODY()

	// Custom Component to attach Jelly
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* JellySkin;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FJellyProperty Property;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FJellyStatus Status;
	

public:	
	// Sets default values for this actor's properties
	AJellyActor();

	// Generate from basic type
	AJellyActor(FString type);

	// Generate from parents.
	AJellyActor(FString type, FJellyProperty property);

	class UJellyMovementComponent* JellyMovementComponent;

	class UParticleSystemComponent* JellyParticleSystem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UPawnMovementComponent* GetMovementComponent() const override;
	
	// Spend the resource of the terrain, it has to be used with event dispatcher in terrain actor.
	void Survive(AJellyActor Jelly); //, ATerrain terrain)


	// Getter and setter for status
	UFUNCTION(BlueprintPure)
		int getAggression();

	UFUNCTION(BlueprintCallable)
		void setAggression(int i);

	UFUNCTION(BlueprintPure)
		int getActivity();

	UFUNCTION(BlueprintCallable)
		void setActivity(int i);

	UFUNCTION(BlueprintPure)
		int getReproductivity();

	UFUNCTION(BlueprintCallable)
		void setReproductivity(int i);

	UFUNCTION(BlueprintPure)
		int getEndurability();

	UFUNCTION(BlueprintCallable)
		void setEndurability(int i);

	UFUNCTION(BlueprintPure)
		FJellyProperty getAllProperty();

	UFUNCTION(BlueprintCallable)
		void settAllProperty(AJellyActor* Jelly);

	UFUNCTION(BlueprintPure)
		int getMaxHealthPoint();

	UFUNCTION(BlueprintCallable)
		void setMaxHealthPoint(int i);

	UFUNCTION(BlueprintPure)
		int getCurrentHealthPoint();

	UFUNCTION(BlueprintCallable)
		void setCurrentHealthPoint(int i);

	UFUNCTION(BlueprintPure)
		FJellyStatus getStatus();

	UFUNCTION(BlueprintCallable)
		void setStatus(AJellyActor* Jelly);
};

void setJellySkin(FString type, UStaticMeshComponent* JellySkin);