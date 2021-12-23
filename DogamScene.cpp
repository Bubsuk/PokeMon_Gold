#include "stdafx.h"
#include "DogamScene.h"
#include "Image.h"
#include "PokemonManager.h"

HRESULT DogamScene::Init()
{
	mDogamMain = IMG_MGR->FindImage(eImageTag::Dogam);
	mDogamSelect = IMG_MGR->FindImage(eImageTag::DogamSelect);

	mSelectCnt = 0;

	mSelectPos = { WIN_SIZE_X - 202, 70};

	return S_OK;
}

void DogamScene::Update()
{
	if (Input::GetButtonDown(VK_DOWN))
	{
		++mSelectCnt;
		mSelectPos.y += 65;
	}
	if (Input::GetButtonDown(VK_UP))
	{
		--mSelectCnt;
		mSelectPos.y -= 65;
	}

	// Áö¿ï °Í
	if (Input::GetButtonDown('C'))
	{
		POKE_MGR->StartPoke();
	}


	if (mSelectCnt >= POKE_MGR->mPokeDogam.size() || mSelectCnt > 6)
	{
		mSelectCnt = 0;
		mSelectPos = { WIN_SIZE_X - 202, 70 };
	}
}

void DogamScene::Render(HDC hdc)
{
	mDogamMain->Render(hdc);
	mDogamSelect->Render(hdc, mSelectPos.x, mSelectPos.y);
}

void DogamScene::Release()
{
}
