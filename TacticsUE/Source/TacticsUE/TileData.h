// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TACTICSUE_API TileData
{
public:
	TileData(float x,float y);
	~TileData();

	FVector2D Position;

	void SetNeighbours(TileData* north, TileData* east, TileData* south, TileData* west, TileData* northEast, TileData* southEast, TileData* southWest, TileData* northWest);

protected:
	TArray<TileData *> *neighbours;
};
