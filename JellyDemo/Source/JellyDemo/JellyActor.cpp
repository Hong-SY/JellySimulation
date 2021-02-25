// Fill out your copyright notice in the Description page of Project Settings.

#include "JellyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AJellyActor::AJellyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// 루트 컴포넌트는 물리에 반응하는 구체가 됩니다. (원래 루트 컴포넌트는 Scene으로 기본설정되어있어서 물리반응이없음)
	//https://docs.unrealengine.com/ko/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/Components/1/index.html
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	
	JellySkin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JellySkin"));
	JellySkin->SetupAttachment(RootComponent);
	JellySkin->bEditableWhenInherited = true;

	setJellySkin("0001", JellySkin);
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

void setJellySkin(FString type, UStaticMeshComponent* JellySkin)
{
	// 구체가 어딨는지 확인할 수 있도록 메시 컴포넌트 생성 및 위치 조정
	// 나중에 JellyActorComponent 만들어서 거기에서 설정하도록 하기.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		UStaticMesh* SphereVisual = SphereVisualAsset.Object;
		JellySkin->SetStaticMesh(SphereVisual);
		JellySkin->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		JellySkin->SetWorldScale3D(FVector(0.8f));
	}
}
