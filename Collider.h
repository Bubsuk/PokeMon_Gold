#pragma once
#include "GameEntity.h"

class IngameMap;
class Collider : public GameEntity
{
private:
	IngameMap* mCity;
	IngameMap* mEtc;
	TILE_INFO* mColTile;

	RECT mPlayer;

	eDir mColDir;

	int mUpIndexX;
	int mUpIndexY;

public:
	HRESULT Init(eDir dir, POINT currPos, eSceneTag scene);
	void Update();
	void Render(HDC hdc);
	void Release();

	void SetLimit();

};

