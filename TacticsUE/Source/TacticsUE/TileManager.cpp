// Fill out your copyright notice in the Description page of Project Settings.


#include "TileManager.h"

// Sets default values
ATileManager::ATileManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATileManager::SpawnTiles()
{
	tilemap = new TArray<ATile *>();
	for (float y = 0; y < nbY; y++)
	{
		for (float x = 0; x < nbX; x++)
		{
			auto world = GetWorld();
			ATile * tile = static_cast<ATile*>(world->SpawnActor(ATile::StaticClass()));
			tilemap->Add(tile);
			tile->SpawnTile( x, y,spacing,world);
		}
	}
}

// Called when the game starts or when spawned
void ATileManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnTiles();
}

// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

