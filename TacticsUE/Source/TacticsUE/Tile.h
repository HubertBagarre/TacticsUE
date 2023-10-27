// Fill out your copyright notice in the Description page of Project Settings.
#include "Unit.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Tile.generated.h"

UCLASS()
class TACTICSUE_API ATile : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATile();
	void SpawnTile(int x, int y,int sizeDecal,UWorld* world);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector2d TilePosition;
	TArray<ATile*> *neighbours;
	ACharacter* bpTile;

	AUnit* unit; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
