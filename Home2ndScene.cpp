#include "stdafx.h"
#include "Home2ndScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT Home2ndScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-5376, -64);
	mTo1stFloor = { -5376, 0 };
	return S_OK;
}

void Home2ndScene::Update()
{
	if (CON_MGR->mState == eDir::Up &&
		CAM_MGR->GetCamPos().x == mTo1stFloor.x 
		&& CAM_MGR->GetCamPos().y == mTo1stFloor.y)
	{
		SCENE_MGR->ChangeScene(eSceneTag::Home1stScene);
	}
	SAFE_UPDATE(mJiwoo);
}

void Home2ndScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void Home2ndScene::Release()
{
	CON_MGR->Release();
}
