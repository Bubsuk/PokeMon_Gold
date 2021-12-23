#include "stdafx.h"
#include "DrOLabScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT DrOLabScene::Init()
{
	CON_MGR->Init();
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-3328, -640);

	return S_OK;
}

void DrOLabScene::Update()
{
	CON_MGR->Update();
	if (CON_MGR->mState == eDir::Down &&
		(-3328 <= CAM_MGR->GetCamPos().x && CAM_MGR->GetCamPos().x <= -3264)
		&& (CAM_MGR->GetCamPos().y <= -640))
	{
		POINT outDoor;
		outDoor.x = -6976;
		outDoor.y = -1152;
		CAM_MGR->SetWarfPos(outDoor);
		SCENE_MGR->ChangeScene(eSceneTag::CityScene);
	}

}

void DrOLabScene::Render(HDC hdc)
{
	MAP_MGR->DrawMap(hdc);
	CON_MGR->Render(hdc);
}

void DrOLabScene::Release()
{
	CON_MGR->Release();
}
