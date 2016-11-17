// Fill out your copyright notice in the Description page of Project Settings.

#include "MOBA_AI.h"
#include "MOBA_C_GameMode.h"
#include "WaypointC.h"
#include "MinionWaveStart.h"

void AMOBA_C_GameMode::BeginPlay()
{
	// 3 лайна
	Team0NavData.SetNum(3);
	Team1NavData.SetNum(3);

	TArray<AActor*> Waypoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), WaypointExample, Waypoints);

	UE_LOG(LogTemp, Warning, TEXT(" Amount of waypoints: %d"), Waypoints.Num());

	for (auto& waypoint : Waypoints)
	{
		AWaypointC* tmp = Cast<AWaypointC>(waypoint);
		//if (tmp->WaypointNumber + 1> Team0NavData[tmp->Lane].Num())
		//{
		//	Team0NavData[tmp->Lane].SetNum(tmp->WaypointNumber);
		//}
		Team0NavData[tmp->Lane].Insert(tmp, tmp->WaypointNumber);
	}

	for (int i = 0; i < 3; i++)
	{
		Team1NavData[i].SetNum(Team0NavData[i].Num());
	}

	for (int i = 0; i < Team0NavData.Num(); i++)
	{
		for (int j = Team0NavData[i].Num() - 1, k = 0; j >= 0; j--, k++)
		{
			Team1NavData[i][k] = Team0NavData[i][j];
		}
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), MinionWaveStartExample, MinionRespawnPlace);

	UE_LOG(LogTemp, Warning, TEXT("Amount of minion start points: %d"), MinionRespawnPlace.Num());

	UE_LOG(LogTemp, Warning, TEXT("C++ BeginPlay Worked!"));

	// https://answers.unrealengine.com/questions/148921/blueprint-event-begin-play-called-before-c-parents.html
	Super::BeginPlay();
}

FVector AMOBA_C_GameMode::GetNextWaypoint(int Team, int Lane, int CurrentWaypoint)
{
	if (Team == 0)
	{
		if (CurrentWaypoint + 1 > Team0NavData[Lane].Num())
		{
			return Team0NavData[Lane][CurrentWaypoint]->GetActorLocation();
		}
		return Team0NavData[Lane][CurrentWaypoint + 1]->GetActorLocation();
	}
	else if (Team == 1)
	{
		if (CurrentWaypoint + 1 > Team1NavData[Lane].Num())
		{
			return Team1NavData[Lane][CurrentWaypoint]->GetActorLocation();
		}
		return Team1NavData[Lane][CurrentWaypoint + 1]->GetActorLocation();
	}
	return FVector::ZeroVector;
}

TArray<AWaypointC*> AMOBA_C_GameMode::GetWaypoints(int Team, int Lane)
{
	if (Team == 0)
		return Team0NavData[Lane];
	else
		return Team1NavData[Lane];
}