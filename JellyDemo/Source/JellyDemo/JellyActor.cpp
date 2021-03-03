// Fill out your copyright notice in the Description page of Project Settings.

#include "JellyActor.h"
#include "JellyMovementComponent.h"
#include "JellyAIController.h"

#include "Engine/Classes/Particles/ParticleSystemComponent.h"
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

	JellyParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
	JellyParticleSystem->SetupAttachment(RootComponent);
	JellyParticleSystem->bAutoActivate = false;
	JellyParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/Particles/P_Fire.P_Fire"));
	if (ParticleAsset.Succeeded())
	{
		JellyParticleSystem->SetTemplate(ParticleAsset.Object);
	}

	// �����Ʈ ������Ʈ �ν��Ͻ��� �����ϰ�, ��Ʈ�� ������Ʈ�϶� �̸��ϴ�

	JellyMovementComponent = CreateDefaultSubobject<UJellyMovementComponent>(TEXT("JellyMovementComponent"));


	JellyMovementComponent->MaxSpeed = 5.0f;
	JellyMovementComponent->UpdatedComponent = RootComponent;

	// Controller

	AIControllerClass = AJellyAIController::StaticClass();

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

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
	//AJellyAIController* controller = Cast<AJellyAIController>(GetController());
	//controller->RandomMove();
}

UPawnMovementComponent* AJellyActor::GetMovementComponent() const
{
	return JellyMovementComponent;
}

// Skin changer
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

// Getter
int AJellyActor::getAggression() { return this->Property.Aggression; }
int AJellyActor::getActivity() { return this->Property.Activity; }
int AJellyActor::getReproductivity() { return this->Property.Reproductivity; }
int AJellyActor::getEndurability() { return this->Property.Endurability; }
int AJellyActor::getMaxHealthPoint() { return this->Status.MaxHealthPoint; }
int AJellyActor::getCurrentHealthPoint() { return this->Status.CurrentHealthPoint; }
FJellyProperty AJellyActor::getAllProperty() { return this->Property; }
FJellyStatus AJellyActor::getStatus() { return this->Status; }

// Setter
void AJellyActor::setAggression(int i) { this->Property.Aggression = i; }
void AJellyActor::setActivity(int i) { this->Property.Activity = i; }
void AJellyActor::setReproductivity(int i) { this->Property.Reproductivity = i; }
void AJellyActor::setEndurability(int i) { this->Property.Endurability = i; }
void AJellyActor::setMaxHealthPoint(int i) { this->Status.MaxHealthPoint = i; }
void AJellyActor::setCurrentHealthPoint(int i) { this->Status.CurrentHealthPoint = i; }
void AJellyActor::settAllProperty(AJellyActor* Jelly) { this->Property = Jelly->Property; }
void AJellyActor::setStatus(AJellyActor* Jelly) { this->Status = Jelly->Status; }

