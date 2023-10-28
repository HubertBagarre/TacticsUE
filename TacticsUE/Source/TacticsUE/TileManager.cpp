// Fill out your copyright notice in the Description page of Project Settings.

#include "TileManager.h"
#include "BattlePlayerController.h"

// Sets default values
ATileManager::ATileManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATileManager::ConstructData()
{
	//TileData::SetManager(this);
	
	tilemap = new TArray<TileData *>();
	for (float y = 0; y < nbY; y++)
	{
		for (float x = 0; x < nbX; x++)
		{
			tilemap->Add(new TileData(x,y));
		}
	}

	for (float y = 0; y < nbY; y++)
	{
		for (float x = 0; x < nbX; x++)
		{
			bool north = y + 1 < nbY;
			bool east = x + 1 < nbX;
			bool south = y - 1 >= 0;
			bool west = x - 1 >= 0;
			bool northEast = north && east;
			bool southEast = south && east;
			bool southWest = south && west;
			bool northWest = north && west;

			
			TileData* northTile = north ? GetTileData(x,y): nullptr;
			TileData* eastTile = east ? GetTileData(x,y): nullptr;
			TileData* southTile = south ? GetTileData(x,y): nullptr;
			TileData* westTile = west ? GetTileData(x,y): nullptr;
			TileData* northEastTile = northEast ? GetTileData(x,y): nullptr;
			TileData* southEastTile = southEast ? GetTileData(x,y): nullptr;
			TileData* southWestTile = southWest ? GetTileData(x,y): nullptr;
			TileData* northWestTile = northWest ? GetTileData(x,y): nullptr;
			
			GetTileData(x,y)->SetNeighbours(northTile, eastTile, southTile, westTile, northEastTile, southEastTile, southWestTile, northWestTile);
		}
	}
}

// Called when the game starts or when spawned
void ATileManager::BeginPlay()
{
	Super::BeginPlay();
	
	ConstructData();

	SetupCallbacks();
}

void ATileManager::SetupCallbacks()
{
	auto player = static_cast<ABattlePlayerController*>(GetWorld()->GetFirstPlayerController());
	
	player->OnLeftClick.AddDynamic(this, &ATileManager::ClickTile);
}

void ATileManager::ClickTile(float mouseX, float mouseY)
{
	FHitResult hitResult;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, hitResult);
	/*
	if (hitResult.GetActor() != nullptr)
	{
		auto tile = static_cast<ATile*>(hitResult.GetActor());
		UE_LOG(LogTemp, Log, TEXT("Tile %f %f"), tile->TilePosition.X, tile->TilePosition.Y);
	}*/
}

TileData* ATileManager::GetTileData(int x, int y)
{
	return tilemap->GetData()[x + y * nbX];
}

TileData* ATileManager::GetTileData(int index)
{
	return tilemap->GetData()[index];
}

void ATileManager::OnTileClicked(int index)
{
	if(index < 0 || index >= tilemap->Num()) return;
	auto tile = GetTileData(index);

	//display tile position on screen
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tile %f %f"), tile->Position.X, tile->Position.Y));
}

// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

