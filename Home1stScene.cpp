#include "stdafx.h"
#include "Home1stScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT Home1stScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-4544, -64);
	mTo2ndFloor = { -4544, 0 };
	mToOutdoor = { -4416, -448 };
	return S_OK;
}

void Home1stScene::Update()
{
	CON_MGR->Update();

	if(CON_MGR->mState == eDir::Up &&
		CAM_MGR->GetCamPos().x == mTo2ndFloor.x
		&& CAM_MGR->GetCamPos().y == mTo2ndFloor.y)
	{
		SCENE_MGR->ChangeScene(eSceneTag::Home2ndScene);
	}
	else if(CON_MGR->mState == eDir::Down &&
		(-4416 <= CAM_MGR->GetCamPos().x && CAM_MGR->GetCamPos().x <= -4352)
		&& (CAM_MGR->GetCamPos().y <= mToOutdoor.y))
	{
		POINT outDoor;
		outDoor.x = -7488;
		outDoor.y = -1280;
		CAM_MGR->SetWarfPos(outDoor);
		SCENE_MGR->ChangeScene(eSceneTag::CityScene);
	}


}

void Home1stScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void Home1stScene::Release()
{
	CON_MGR->Release();
}
