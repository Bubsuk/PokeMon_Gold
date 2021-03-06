#include "stdafx.h"
#include "DrOLabScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT DrOLabScene::Init()
{
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-3328, -640);
	
	return S_OK;
}

void DrOLabScene::Update()
{
	CON_MGR->Update();
	if (CON_MGR->mState == eDir::Down && Collider::CheckDoor() == true)
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
}
