#include "stdafx.h"
#include "Dogam.h"
#include "Image.h"
#include "PokemonManager.h"

HRESULT Dogam::Init()
{
	mDogamMain = IMG_MGR->FindImage(eImageTag::Dogam);
	mDogamSelect = IMG_MGR->FindImage(eImageTag::DogamSelect);

	mSelectCnt = 0;

	mSelectPos = { WIN_SIZE_X - 202, 70};

	mbDogam = false;

	return S_OK;
}

void Dogam::Update()
{
	if (Input::GetButtonDown(VK_DOWN))
	{
		++mSelectCnt;
	}
	if (Input::GetButtonDown(VK_UP))
	{
		--mSelectCnt;
	}
	if (Input::GetButtonDown('X'))
	{
		mbDogam = false;
	}


	mSelectPos.y = 75 + (mSelectCnt * 70);

	if (mSelectCnt > POKE_MGR->mPokeDogam.size() - 1 || mSelectCnt > 6)
	{
		mSelectCnt = 0;
		mSelectPos = { WIN_SIZE_X - 202, 75 };
	}

}

void Dogam::Render(HDC hdc)
{
	mDogamMain->Render(hdc);

	if (!POKE_MGR->mPokeDogam.empty())
	{
		int cnt = 0;
		for (int i = 0; i < POKE_MGR->mPokeDogam.size(); ++i)
		{
			SetTextColor(hdc, RGB(255, 255, 255));
			SetBkColor(hdc, RGB(0, 0, 0));
			HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
				18, TEXT("PokemonGSC"));
			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

			sprintf_s(mSampleText, POKE_MGR->mPokeDogam[i]->chName);
			TextOut(hdc, WIN_SIZE_X - 250, 55 +(70 * i), mSampleText, strlen(mSampleText));
			
			DeleteObject(SelectObject(hdc, hOldFont));
		}

		POKE_MGR->mPokeDogam[mSelectCnt]->mFrontImg->Render(hdc, 145, 145);

	}

	mDogamSelect->Render(hdc, mSelectPos.x, mSelectPos.y);
}

void Dogam::Release()
{
}
