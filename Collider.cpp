#include "stdafx.h"
#include "Enum.h"
#include "Collider.h"
#include "Config.h"
#include "IngameMap.h"
#include "CityScene.h"


HRESULT Collider::Init(eDir dir, POINT currPos, eSceneTag scene)
{
	mUpIndexX = (288 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
	mUpIndexY = (224 - CAM_MGR->GetCamPos().y) / TILE_SIZE;

	mCity = new IngameMap;
	mCity->Init();
	mCity->LoadMap("cityMap");

	mColDir = dir;

	switch (scene)
	{
	case eSceneTag::CityScene:
		mColTile = mCity->GetTileInfo();
		break;
	}

	return S_OK;
}

void Collider::Update()
{
	if (mColDir == eDir::Up && mColTile[mUpIndexY * TILE_COUNT_X + mUpIndexX].Terrain == eTerrain::Close)
	{
		CAM_MGR->mObjectPos.y = mColTile[mUpIndexY * TILE_COUNT_X + mUpIndexX].Rc.bottom;
	}
}

void Collider::Render(HDC hdc)
{
}

void Collider::Release()
{
}

void Collider::SetLimit()
{
	

	

}
