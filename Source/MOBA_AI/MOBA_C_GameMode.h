// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MOBA_C_GameMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MOBA_AI_API AMOBA_C_GameMode : public AGameMode
{
	GENERATED_BODY()

	TArray<TArray<class AWaypointC*>> Team0NavData;
	TArray<TArray<class AWaypointC*>> Team1NavData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> MinionRespawnPlace;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AWaypointC> WaypointExample;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AMinionWaveStart> MinionWaveStartExample;

public:
	virtual void BeginPlay() override;
	
	//UFUNCTION(BlueprintCallable, Category = "Minion Navigation")
	FVector GetNextWaypoint(int Team, int Lane, int CurrentWaypoint);

	UFUNCTION(BlueprintCallable, Category = "Minion Navigation")
	TArray<class AWaypointC*> GetWaypoints(int Team, int Lane);
};
