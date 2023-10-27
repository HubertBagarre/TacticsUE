// Fill out your copyright notice in the Description page of Project Settings.


#include "BattlePlayer.h"

#include "EnhancedInputComponent.h"

// Sets default values
ABattlePlayer::ABattlePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattlePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattlePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattlePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

