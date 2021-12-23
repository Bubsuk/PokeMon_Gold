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
		mSelectPos.y += 70;
	}
	if (Input::GetButtonDown(VK_UP))
	{
		--mSelectCnt;
		mSelectPos.y -= 70;
	}

	// Áö¿ï °Í
	if (Input::GetButtonDown('C'))
	{
		POKE_MGR->StartPoke();
		if (!POKE_MGR->mPokeDogam.empty())
		{
			cout << POKE_MGR->mPokeDogam[0]->mName << endl;
		}
	}


	if (mSelectCnt >= POKE_MGR->mPokeDogam.size() || mSelectCnt > 5)
	{
		mSelectCnt = 0;
		mSelectPos = { WIN_SIZE_X - 202, 75 };
		
	}
}

void DogamScene::Render(HDC hdc)
{
	mDogamMain->Render(hdc);

	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkColor(hdc, RGB(0, 0, 0));
	HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
		18, TEXT("PokemonGSC"));
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);


	if (!POKE_MGR->mPokeDogam.empty())
	{
		for (int i = 0; i < POKE_MGR->mPokeDogam.size(); ++i)
		{
			sprintf_s(mSampleText, POKE_MGR->mPokeDogam[i]->chName);
			TextOut(hdc, WIN_SIZE_X - 250, 55 +(70 * i), mSampleText, strlen(mSampleText));
		}
		switch (mSelectCnt)
		{
		case 0:
			POKE_MGR->mPokeDogam[0]->mFrontImg->Render(hdc, 145, 145);
			break;
		case 1:
			POKE_MGR->mPokeDogam[1]->mFrontImg->Render(hdc, 145, 145);
			break;
		case 2:
			POKE_MGR->mPokeDogam[2]->mFrontImg->Render(hdc, 145, 145);
			break;
		case 3:
			POKE_MGR->mPokeDogam[3]->mFrontImg->Render(hdc, 145, 145);
			break;
		case 4:
			POKE_MGR->mPokeDogam[4]->mFrontImg->Render(hdc, 145, 145);
			break;
		case 5:
			POKE_MGR->mPokeDogam[5]->mFrontImg->Render(hdc, 145, 145);
			break;
		}

	}

	DeleteObject(SelectObject(hdc, hOldFont));

	mDogamSelect->Render(hdc, mSelectPos.x, mSelectPos.y);
}

void DogamScene::Release()
{
}
