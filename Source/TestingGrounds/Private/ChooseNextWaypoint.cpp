// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "Components/ActorComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetPatrolPoints(OwnerComp.GetAIOwner());
	
	auto Index = SetNextWaypoint(OwnerComp.GetBlackboardComponent());

	CycleWaypoints(Index, OwnerComp.GetBlackboardComponent());

	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints(AAIController* AIController)
{
	if (!AIController) { return; }
	PatrolPoints = AIController->GetPawn()->FindComponentByClass<UPatrolRoute>()->GetPatrolPoints();
}

int32 UChooseNextWaypoint::SetNextWaypoint(UBlackboardComponent* BlackboardComponent)
{
	if (!BlackboardComponent) { return 0; }
	auto Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	if (PatrolPoints.Num() == 0) { return 0; }
	UE_LOG(LogTemp, Warning, TEXT("SetNextWaypoint!"))
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	return Index;
}

void UChooseNextWaypoint::CycleWaypoints(int32 Index, UBlackboardComponent* BlackboardComponent)
{
	if (!BlackboardComponent) { return; }
	if (PatrolPoints.Num() == 0) { return; }
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
}
