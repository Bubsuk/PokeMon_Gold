#include "stdafx.h"
#include "Home2ndScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT Home2ndScene::Init()
{
	MAP_MGR->LoadMap("etcMap");
	if (SCENE_MGR->mbStartScene == true)
	{
		CAM_MGR->SetPos(-5120, -192);
	}
	else
	{
		POINT startPos = CAM_MGR->GetWarfPos();
		CAM_MGR->SetPos(startPos.x, startPos.y);
	}

	mTo1stFloor = { -5376, 0 };

	return S_OK;
}

void Home2ndScene::Update()
{
	
	if (CON_MGR->mState == eDir::Up 
		&& Collider::CheckDoor() == true 
		&& CAM_MGR->GetCamPos().y >= 0)
	{
		SCENE_MGR->mbStartScene = false;
		POINT warfPos = { -5375, -64 };
		CAM_MGR->SetWarfPos(warfPos);
		SCENE_MGR->ChangeScene(eSceneTag::Home1stScene);
	}

	CON_MGR->Update();
}

void Home2ndScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void Home2ndScene::Release()
{
}
