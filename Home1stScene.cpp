#include "stdafx.h"
#include "Home1stScene.h"
#include "MapManager.h"
#include "Jiwoo.h"


HRESULT Home1stScene::Init()
{
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-4544, -64);
	CON_MGR->mState = eDir::Down;

	mToOutdoor = { -4416, -448 };
	return S_OK;
}

void Home1stScene::Update()
{
	

	if(CON_MGR->mState == eDir::Up 
		&& Collider::CheckDoor() == true
		&& CAM_MGR->GetCamPos().y >= 0)
	{
		SCENE_MGR->ChangeScene(eSceneTag::Home2ndScene);
	}
	else if(CON_MGR->mState == eDir::Down 
		&& Collider::CheckDoor() == true
		&& CAM_MGR->GetCamPos().y <= -448)
	{
		POINT outDoor;
		outDoor.x = -7488;
		outDoor.y = -1280;
		CAM_MGR->SetWarfPos(outDoor);
		SCENE_MGR->ChangeScene(eSceneTag::CityScene);
	}

	CON_MGR->Update();
}

void Home1stScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void Home1stScene::Release()
{
}
