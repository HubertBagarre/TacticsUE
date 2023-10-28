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

	void ConstructData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int nbX = 10;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int nbY = 10;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int spacing = 170;

	TArray<TileData *> *tilemap;

	void SetupCallbacks();
	
	UFUNCTION()
	void ClickTile(float mouseX, float mouseY);
	TileData* GetTileData(int x, int y);
	TileData* GetTileData(int index);

	UFUNCTION(BlueprintCallable)
	void OnTileClicked(int index);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
