#include "stdafx.h"
#include "CenterScene.h"
#include "MapManager.h"
#include "Jiwoo.h"


HRESULT CenterScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-256, -448);

	return S_OK;
}

void CenterScene::Update()
{
	CON_MGR->Update();
	if (CON_MGR->mState == eDir::Down && 
		(-256 <= CAM_MGR->GetCamPos().x && CAM_MGR->GetCamPos().x <= -192)
		&& (CAM_MGR->GetCamPos().y <= -448))
	{
		POINT outDoor;
		outDoor.x = -2048;
		outDoor.y = -1412;
		CAM_MGR->SetWarfPos(outDoor);
		SCENE_MGR->ChangeScene(eSceneTag::CityScene);
	}
	
}

void CenterScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void CenterScene::Release()
{
	CON_MGR->Release();
}
