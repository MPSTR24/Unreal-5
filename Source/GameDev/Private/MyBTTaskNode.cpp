// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskNode.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "Tasks/AITask_MoveTo.h"
#include "NavigationSystem.h"


EBTNodeResult::Type UMyBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//this is the function when we start a node

	//get the controller
	AAIController* controller = OwnerComp.GetAIOwner();
	
	//get the pawn.
	APawn* pawn = controller->GetPawn();

	FVector loc = pawn->GetActorLocation();

	FNavLocation navLoc;
	UNavigationSystemV1* navSystem = UNavigationSystemV1::GetCurrent(OwnerComp.GetWorld());
	bool success = navSystem->GetRandomPointInNavigableRadius(loc, Radius, navLoc);
	FVector destination = navLoc.Location;



	// UAITask_MoveTo::AIMoveTo()
	return EBTNodeResult::Succeeded;

}