// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	InitialPos = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Get current location
	FVector MyCurrentLocation = GetActorLocation();
	
	//Calculate distance
	float DistanceOverInit = FVector::Dist(InitialPos, MyCurrentLocation);
	DistanceTravelled = DistanceOverInit;

	if (DistanceOverInit <= RangeMovement)
	{
		//Add change in location and set it to actor
		MyCurrentLocation += SpeedPlatform * DeltaTime;
		SetActorLocation(MyCurrentLocation);
	}
}

