#include "stdafx.h"
#include "GymScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT GymScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-1280, -896);

	return S_OK;
}

void GymScene::Update()
{
	CON_MGR->Update();
	if (CON_MGR->mState == eDir::Down &&
		(-1280 <= CAM_MGR->GetCamPos().x && CAM_MGR->GetCamPos().x <= -1216)
		&& (CAM_MGR->GetCamPos().y <= -896))
	{
		POINT outDoor;
		outDoor.x = -1216;
		outDoor.y = -896;
		CAM_MGR->SetWarfPos(outDoor);
		SCENE_MGR->ChangeScene(eSceneTag::CityScene);
	}

}

void GymScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void GymScene::Release()
{
	CON_MGR->Release();
}
