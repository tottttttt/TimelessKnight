// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_GetPatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class STIMELESSKNIGHT_API UBTT_GetPatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTT_GetPatrolPoint();

public:
	virtual EBTNodeResult::Type	ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	float Radius;

	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector Key;

};
