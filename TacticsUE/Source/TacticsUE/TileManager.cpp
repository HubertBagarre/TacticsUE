// Fill out your copyright notice in the Description page of Project Settings.


#include "TileManager.h"

#include "BattlePlayerController.h"

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

			// TODO - wait for tile to finish spawning (probably use setTimer()) :c
			
			tilemap->Add(tile);
			
			tile->SpawnTile( x, y,spacing,world);
			tile->TilePosition = FVector2D(x, y);
		}
	}

	
}

// Called when the game starts or when spawned
void ATileManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnTiles();

	auto player = static_cast<ABattlePlayerController*>(GetWorld()->GetFirstPlayerController());
	
	player->OnLeftClick.AddDynamic(this, &ATileManager::ClickTile);

	UE_LOG(LogTemp, Log, TEXT("Added event"));
}

void ATileManager::ClickTile(float mouseX, float mouseY)
{
	//raycast to tile
	FVector2D mousePos(mouseX, mouseY);
	FHitResult hitResult;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, hitResult);
	if (hitResult.GetActor() != nullptr)
	{
		auto tile = static_cast<ATile*>(hitResult.GetActor());
		UE_LOG(LogTemp, Log, TEXT("Tile %f %f"), tile->TilePosition.X, tile->TilePosition.Y);
	}
}


// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

