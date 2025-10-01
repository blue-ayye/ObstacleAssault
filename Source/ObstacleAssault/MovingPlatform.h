// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
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

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	float GetDistanceMoved() const;

	UPROPERTY(EditAnywhere)
	FVector StartPoint = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere)
	FVector MovementVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere)
	float MoveDistance = 500.f;

	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity = FRotator(0, 0, 10.f);
};
