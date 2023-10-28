// Fill out your copyright notice in the Description page of Project Settings.

#include "TileManager.h"
#include "BattlePlayerController.h"

// Sets default values
ATileManager::ATileManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATileManager::ConstructData(int x, int y)
{
	
	tilemap = new TArray<TileData *>();
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < y; j++)
		{
			tilemap->Add(new TileData(i,j));
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < y; j++)
		{
			bool north = i + 1 < x;
			bool east = j + 1 < y;
			bool south = i - 1 >= 0;
			bool west = j - 1 >= 0;
			bool northEast = north && east;
			bool southEast = south && east;
			bool southWest = south && west;
			bool northWest = north && west;

			
			TileData* northTile = north ? GetTileData(j,i,x): nullptr;
			TileData* eastTile = east ? GetTileData(j,i,x): nullptr;
			TileData* southTile = south ? GetTileData(j,i,x): nullptr;
			TileData* westTile = west ? GetTileData(j,i,x): nullptr;
			TileData* northEastTile = northEast ? GetTileData(j,i,x): nullptr;
			TileData* southEastTile = southEast ? GetTileData(j,i,x): nullptr;
			TileData* southWestTile = southWest ? GetTileData(j,i,x): nullptr;
			TileData* northWestTile = northWest ? GetTileData(j,i,x): nullptr;
			
			GetTileData(j,i,x)->SetNeighbours(northTile, eastTile, southTile, westTile, northEastTile, southEastTile, southWestTile, northWestTile);
		}
	}
}

// Called when the game starts or when spawned
void ATileManager::BeginPlay()
{
	Super::BeginPlay();
	
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

TileData* ATileManager::GetTileData(int x, int y, int maxX)
{
	return tilemap->GetData()[x + y * maxX];
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

