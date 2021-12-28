#include "stdafx.h"
#include "MenuPokemon.h"
#include "Image.h"
#include "PokemonManager.h"

HRESULT MenuPokemon::Init()
{
    mFrame1 = IMG_MGR->FindImage(eImageTag::PokeSelect1);
    mFrame2 = IMG_MGR->FindImage(eImageTag::PokeSelect2);
    mFrame3 = IMG_MGR->FindImage(eImageTag::PokeSelect3);
    mFrame4 = IMG_MGR->FindImage(eImageTag::PokeSelect4);
    mFrame5 = IMG_MGR->FindImage(eImageTag::PokeSelect5);
    mFrameCls = IMG_MGR->FindImage(eImageTag::PokeSelectCls);

    mPokePower = IMG_MGR->FindImage(eImageTag::PokePower);

	mHpFrame = IMG_MGR->FindImage(eImageTag::HpBar);
	mHpGauge = IMG_MGR->FindImage(eImageTag::HpGauge);

    mPokeCnt = 0;

    mIconPosY = 0;

	mbMenu = false;
    mbPowerWindow = false;

    return S_OK;
}

void MenuPokemon::Update()
{

	if (Input::GetButtonDown(VK_DOWN))
	{
		++mPokeCnt;
	}
	if (Input::GetButtonDown(VK_UP))
	{
		--mPokeCnt;
	}

	if (mPokeCnt <= 0)
	{
		mPokeCnt = 0;
	}
	if (!POKE_MGR->mJiwooPokemon.empty())
	{
		if (mPokeCnt >= POKE_MGR->mJiwooPokemon.size() - 1)
		{
			mPokeCnt = POKE_MGR->mJiwooPokemon.size() - 1;
		}
	}
		
	if (Input::GetButtonDown('A'))
	{
		mbPowerWindow = true;
	}
	if (Input::GetButtonDown('X'))
	{
		mbMenu = false;
		mPokeCnt = 0;
	}
		

}

void MenuPokemon::Render(HDC hdc)
{
	switch (mPokeCnt)
	{
	case 0:
		mFrame1->Render(hdc);
		break;
	case 1:
		mFrame2->Render(hdc);
		break;
	case 2:
		mFrame3->Render(hdc);
		break;
	case 3:
		mFrame4->Render(hdc);
		break;
	case 4:
		mFrame5->Render(hdc);
		break;
	case 6:
		mFrameCls->Render(hdc);
		break;
	default:
		break;
	}

	if (!POKE_MGR->mJiwooPokemon.empty())
	{
		for (int i = 0; i < POKE_MGR->mJiwooPokemon.size(); ++i)
		{
			POKE_MGR->mJiwooPokemon[i]->mTypeImg->Render(hdc, 60, 35 + (70 * i), POKE_MGR->mJiwooPokemon[i]->mTypeIndexX, POKE_MGR->mJiwooPokemon[i]->mTypeIndexY);
			mHpFrame->Render(hdc, WIN_SIZE_X / 2 + 170, 43 + (70 * i));
			mHpGauge->hpRender(hdc, WIN_SIZE_X / 2 + 194, 43 + (70 * i), POKE_MGR->mJiwooPokemon[i]->mMaxHp, POKE_MGR->mJiwooPokemon[i]->mHp);

			SetTextColor(hdc, RGB(0, 0, 0));
			SetBkColor(hdc, RGB(255, 255, 255));
			HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
				18, TEXT("PokemonGSC"));
			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

			sprintf_s(mSampleText, POKE_MGR->mJiwooPokemon[i]->chName);
			TextOut(hdc, 95, 22 + (70 * i), mSampleText, strlen(mSampleText));

			sprintf_s(mSampleText, ":L %d", POKE_MGR->mJiwooPokemon[i]->mLv);
			TextOut(hdc, WIN_SIZE_X / 2 - 70, 22 + (70 * i), mSampleText, strlen(mSampleText));

			sprintf_s(mSampleText, "%d / ", POKE_MGR->mJiwooPokemon[i]->mHp);
			TextOut(hdc, WIN_SIZE_X / 2 + 130, (70 * i), mSampleText, strlen(mSampleText));

			sprintf_s(mSampleText, "%d", POKE_MGR->mJiwooPokemon[i]->mMaxHp);
			TextOut(hdc, WIN_SIZE_X / 2 + 230, (70 * i), mSampleText, strlen(mSampleText));

			DeleteObject(SelectObject(hdc, hOldFont));
		}

		

	}

	if (mbPowerWindow == true)
	{
		mPokePower->Render(hdc);
	}

}

void MenuPokemon::Release()
{
	
}
