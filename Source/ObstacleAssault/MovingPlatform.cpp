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

	SetActorLocation(StartPoint);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	float DistanceMoved = GetDistanceMoved();
	if (DistanceMoved >= MoveDistance) {
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Warning, TEXT("%s overshot by %f"), *GetName(), OverShoot);

		FVector MoveDirection = MovementVelocity.GetSafeNormal();
		StartPoint += MoveDirection * MoveDistance;
		SetActorLocation(StartPoint);
		MovementVelocity = -MovementVelocity;
	}
	else
	{
		FVector NewLocation = GetActorLocation() + (MovementVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Add(0.f, 10.0f * DeltaTime, 0.f);
	SetActorRotation(CurrentRotation);
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartPoint, GetActorLocation());
}