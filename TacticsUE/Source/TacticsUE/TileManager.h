// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tile.h"
#include "GameFramework/Actor.h"
#include "TileManager.generated.h"

UCLASS()
class TACTICSUE_API ATileManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileManager();

	void SpawnTiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int nbX = 10;
	UPROPERTY(EditAnywhere)
	int nbY = 10;
	UPROPERTY(EditAnywhere)
	int spacing = 170;

	TArray<ATile *> *tilemap;

	UFUNCTION()
	void ClickTile(float mouseX, float mouseY);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
