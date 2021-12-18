#include "stdafx.h"
#include "OpeningScene.h"
#include "Image.h"

HRESULT OpeningScene::Init()
{
	mOpPlay = true;
	elapsedCnt = 0;
	cnt = 0;

	for (int i = 0; i < 102; ++i)
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
	else 
	{
		if (elapsedCnt > 0.065)
		{
			++cnt;
			elapsedCnt = 0.0f;
		}
	}


	if (cnt == 102)
	{
		// 체인지씬으로 바꾸기
		mOpPlay = false;
	}
}

void OpeningScene::Release()
{
}
