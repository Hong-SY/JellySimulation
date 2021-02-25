// Fill out your copyright notice in the Description page of Project Settings.

#include "JellyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AJellyActor::AJellyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// ��Ʈ ������Ʈ�� ������ �����ϴ� ��ü�� �˴ϴ�. (���� ��Ʈ ������Ʈ�� Scene���� �⺻�����Ǿ��־ ���������̾���)
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
	// ��ü�� ������� Ȯ���� �� �ֵ��� �޽� ������Ʈ ���� �� ��ġ ����
	// ���߿� JellyActorComponent ���� �ű⿡�� �����ϵ��� �ϱ�.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		UStaticMesh* SphereVisual = SphereVisualAsset.Object;
		JellySkin->SetStaticMesh(SphereVisual);
		JellySkin->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		JellySkin->SetWorldScale3D(FVector(0.8f));
	}
}
