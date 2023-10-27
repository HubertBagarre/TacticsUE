// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"

// Sets default values
ATile::ATile()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	bpTile = nullptr;
	unit = nullptr; 
}

void ATile::SpawnTile(int x, int y,int sizeDecal,UWorld* world)
{
	UE_LOG(LogTemp, Warning, TEXT("SpawnTile: %d %d"), x, y);
	UObject* SpawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Blueprints/BP_Tile.BP_Tile")));
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FVector actorLocation = FVector(0,0, 0);
	FRotator actorRotation = FRotator(0, 0, 0);
	UBlueprint* bp = Cast<UBlueprint>(SpawnActor);
	try
	{
		ACharacter *p = world->SpawnActor<ACharacter>(bp->GeneratedClass, actorLocation, actorRotation, SpawnParams);
		p->SetActorLocation(FVector(x * sizeDecal, y * sizeDecal, 0));
	}
	catch (...)
	{
	}
	

	
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	neighbours = new TArray<ATile*>();
	neighbours->Init(nullptr,8);
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

