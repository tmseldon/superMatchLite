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
	mInitialPos = GetActorLocation();
	mNameObj = GetName();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	//Get current location
	FVector MyCurrentLocation = GetActorLocation();

	//Add change in location and set it to actor
	MyCurrentLocation += SpeedPlatform * DeltaTime;
	SetActorLocation(MyCurrentLocation);

	//Calculate distance
	float DistanceTravelled = FVector::Dist(mInitialPos, MyCurrentLocation);

	//Object on limit by range value
	if (DistanceTravelled > RangeMovement)
	{
		//Overshoot info
		float OverShootValue = RangeMovement - DistanceTravelled;
		UE_LOG(LogTemp, Display, TEXT("La diferencia es de %f y el objeto es %s"), OverShootValue, *mNameObj)

		//Setting new starting point by sum previous initial location + vector speed normalized * rangeMovement
		mInitialPos = mInitialPos + SpeedPlatform.GetSafeNormal() * RangeMovement;
		SetActorLocation(mInitialPos);
		SpeedPlatform = -1 * SpeedPlatform;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("rotantdo acá"))
}