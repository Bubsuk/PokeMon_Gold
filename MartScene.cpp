#include "stdafx.h"
#include "MartScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT MartScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-2112, -384);

	return S_OK;
}

void MartScene::Update()
{
	
	SAFE_UPDATE(mJiwoo);
	if (CON_MGR->mState == eDir::Down &&
		(-2112 <= CAM_MGR->GetCamPos().x && CAM_MGR->GetCamPos().x <= -2048)
		&& (CAM_MGR->GetCamPos().y <= -384))
	{
		POINT outDoor;
		outDoor.x = -640;
		outDoor.y = -870;
		CAM_MGR->SetWarfPos(outDoor);
		SCENE_MGR->ChangeScene(eSceneTag::CityScene);
	}
}

void MartScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void MartScene::Release()
{
	CON_MGR->Release();
}
