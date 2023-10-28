// Fill out your copyright notice in the Description page of Project Settings.


#include "TileData.h"

TileData::TileData(float x,float y)
{
	Position = FVector2D(x, y);
	neighbours = new TArray<TileData *>();
}

TileData::~TileData()
{
}

void TileData::SetNeighbours(TileData* north, TileData* east, TileData* south, TileData* west, TileData* northEast,
                             TileData* southEast, TileData* southWest, TileData* northWest)
{
	neighbours->Empty();
	neighbours->Add(north);
	neighbours->Add(east);
	neighbours->Add(south);
	neighbours->Add(west);
	neighbours->Add(northEast);
	neighbours->Add(southEast);
	neighbours->Add(southWest);
	neighbours->Add(northWest);
}