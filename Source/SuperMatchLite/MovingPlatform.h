// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SUPERMATCHLITE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Params on Editor
	UPROPERTY(EditAnywhere, Category="Movement Params")
	FVector SpeedPlatform = FVector(0, 100, 0);

	UPROPERTY(EditAnywhere, Category = "Movement Params")
	float RangeMovement = 850;

	//Internal Variables
	FVector mInitialPos;
	FString mNameObj;

	//Methods
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
};