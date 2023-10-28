// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileData.h"
#include "TileManager.generated.h"

UCLASS()
class TACTICSUE_API ATileManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileManager();

	UFUNCTION(BlueprintCallable)
	void ConstructData(int x,int y);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	TArray<TileData *> *tilemap;

	void SetupCallbacks();
	
	UFUNCTION()
	void ClickTile(float mouseX, float mouseY);
	TileData* GetTileData(int x, int y, int maxX);
	TileData* GetTileData(int index);

	UFUNCTION(BlueprintCallable)
	void OnTileClicked(int index);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
