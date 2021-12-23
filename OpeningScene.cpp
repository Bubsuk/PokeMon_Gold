#include "stdafx.h"
#include "OpeningScene.h"
#include "Image.h"

HRESULT OpeningScene::Init()
{
	mOpPlay = true;
	elapsedCnt = 0;
	cnt = 0;

	for (int i = 0; i < 112; ++i)
	{
		mOpImg[i] = IMG_MGR->FindImage(i + 1);
	}
	

	return S_OK;
}

void OpeningScene::Update()
{

}

void OpeningScene::Render(HDC hdc)
{
	mOpImg[cnt]->Render(hdc);
	elapsedCnt += DELTA_TIME;
	if (cnt == 0)
	{
		if (elapsedCnt > 2)
		{
			++cnt;
			elapsedCnt = 0.0f;
		}
	}
	else if(1 <= cnt && cnt <= 101)
	{
		if (elapsedCnt > 0.065)
		{
			++cnt;
			elapsedCnt = 0.0f;
		}
	}

	if (102 <= cnt && cnt <= 111)
	{
		if (elapsedCnt > 0.085)
		{
			++cnt;
			elapsedCnt = 0.0f;
		}
	}
	if (cnt == 111)
	{
		cnt = 102;
	}

	if (Input::GetButtonDown('Z'))
	{
		SCENE_MGR->ChangeScene(eSceneTag::Home2ndScene);
	}
	
}

void OpeningScene::Release()
{
}
