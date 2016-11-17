// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerStart.h"
#include "MinionWaveStart.generated.h"

/**
 * 
 */
UCLASS()
class MOBA_AI_API AMinionWaveStart : public APlayerStart
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Team;
	
};
