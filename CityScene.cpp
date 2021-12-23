#include "stdafx.h"
#include "CityScene.h"
#include "MapManager.h"
#include "Jiwoo.h"
#include "MenuManager.h"

HRESULT CityScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("cityMap");
	POINT startPos = CAM_MGR->GetWarfPos();
	CAM_MGR->SetPos(startPos.x, startPos.y);
	mToCenter = { -2048, -1344 };
	mToMart = { -640, -832 };
	mToGym = { -1216, -832 };
	mToDrO = { -6976, -1088 };

	
	

	
	return S_OK;
}

void CityScene::Update()
{
	
	CON_MGR->Update();

	if (CAM_MGR->GetCamPos().x == mToCenter.x
		&& CAM_MGR->GetCamPos().y == mToCenter.y)
	{
		SCENE_MGR->ChangeScene(eSceneTag::CenterScene);
	}
	if (CAM_MGR->GetCamPos().x == mToMart.x
		&& CAM_MGR->GetCamPos().y == mToMart.y)
	{
		SCENE_MGR->ChangeScene(eSceneTag::MartScene);
	}
	if (CAM_MGR->GetCamPos().x == mToGym.x
		&& CAM_MGR->GetCamPos().y == mToGym.y)
	{
		SCENE_MGR->ChangeScene(eSceneTag::GymScene);
	}
	if (CAM_MGR->GetCamPos().x == mToDrO.x
		&& CAM_MGR->GetCamPos().y == mToDrO.y)
	{
		SCENE_MGR->ChangeScene(eSceneTag::DrOScene);
	}
	/*cout << CAM_MGR->GetCamPos().x << endl;
	cout << CAM_MGR->GetCamPos().y << endl << endl;*/

	

}

void CityScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	
	CON_MGR->Render(hdc);

}

void CityScene::Release()
{
	CON_MGR->Release();
}
