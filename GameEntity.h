#pragma once
#include "Config.h"

typedef struct TagTile
{
	eTerrain Terrain;
	RECT Rc;
	POINT TilePos;

} TILE_INFO, SAMPLE_TILE_INFO;

class GameEntity
{
public:
	TILE_INFO mTileInfo[TILE_COUNT_X * TILE_COUNT_Y];

	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	TILE_INFO* GetTileInfo() { return this->mTileInfo; }
	
	virtual ~GameEntity() = default;
};