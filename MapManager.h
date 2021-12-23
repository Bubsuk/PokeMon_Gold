#pragma once
#include "Config.h"
#include "Singleton.h"

typedef struct TagTile
{
	eTerrain Terrain;
	RECT Rc;
	POINT TilePos;

} TILE_INFO, SAMPLE_TILE_INFO;

class Image;
class MapManager : public Singleton<MapManager>
{
public:
	Image* mTileImg;
	TILE_INFO mTileInfo[TILE_COUNT_X * TILE_COUNT_Y];

	void SetMap();
	void DrawMap(HDC hdc);

	void SaveMap(string index);
	void LoadMap(string index);

	TILE_INFO* GetTileInfo() { return this->mTileInfo; }

};

