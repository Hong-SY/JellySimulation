// Fill out your copyright notice in the Description page of Project Settings.


#include "JellyActor.h"

// Sets default values
AJellyActor::AJellyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJellyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJellyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

