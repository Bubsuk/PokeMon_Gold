#include "stdafx.h"
#include "CityScene.h"
#include "IngameMap.h"

HRESULT CityScene::Init()
{
	mCityMap = new IngameMap;
	mCityMap->Init();
	mCityMap->LoadMap("cityMap");

	CAM_MGR->SetPos( -640, -320);

	return S_OK;
}

void CityScene::Update()
{
	SAFE_UPDATE(mCityMap);
}

void CityScene::Render(HDC hdc)
{
	mCityMap->Render(hdc);
}

void CityScene::Release()
{
	SAFE_RELEASE(mCityMap);
}
