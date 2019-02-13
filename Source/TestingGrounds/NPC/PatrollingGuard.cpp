// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingGuard.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ActorComponent.h"

// Sets default values
APatrollingGuard::APatrollingGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a mesh component that will be used when being viewed from a '3rd person' view (when controlling this pawn)
	//Mesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh3P"));
	//Mesh3P = FindComponentByClass<USkeletalMeshComponent>();
	//Mesh3P->SetOnlyOwnerSee(false);
	//Mesh3P->bCastDynamicShadow = true;
	//Mesh3P->CastShadow = true;
	//Mesh3P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	//Mesh3P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	TP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TP_Gun"));
	TP_Gun->SetOnlyOwnerSee(false);			// other players need to see this mesh
	TP_Gun->bCastDynamicShadow = true;
	TP_Gun->CastShadow = true;
	//TP_Gun->SetupAttachment(FindComponentByClass<USkeletalMeshComponent>(), TEXT("GripPoint"));
	TP_Gun->SetupAttachment(FindComponentByClass<USkeletalMeshComponent>());
}

// Called when the game starts or when spawned
void APatrollingGuard::BeginPlay()
{
	Super::BeginPlay();
	
	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	//TP_Gun->AttachToComponent(FindComponentByClass<USkeletalMeshComponent>(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), TEXT("GripPoint"));
}

// Called every frame
void APatrollingGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APatrollingGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

