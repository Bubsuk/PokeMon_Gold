#include "stdafx.h"
#include "MartScene.h"
#include "MapManager.h"
#include "Jiwoo.h"

HRESULT MartScene::Init()
{
	MAP_MGR->LoadMap("etcMap");
	CAM_MGR->SetPos(-2112, -384);

	mToCity = { -2112, -384 };
	return S_OK;
}

void MartScene::Update()
{
	CON_MGR->Update();
	if (CON_MGR->mState == eDir::Down && Collider::CheckDoor() == true)
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

}
