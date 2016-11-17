// Fill out your copyright notice in the Description page of Project Settings.

#include "MOBA_AI.h"
#include "WaypointC.h"


// Sets default values
AWaypointC::AWaypointC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(Root);

	WaypointNumber = 0;
	Lane = 0;
}

// Called when the game starts or when spawned
void AWaypointC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypointC::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

