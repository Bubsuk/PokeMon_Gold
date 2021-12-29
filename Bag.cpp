#include "stdafx.h"
#include "Config.h"
#include "Bag.h"
#include "Image.h"
#include "PokemonManager.h"
#include "InventoryManager.h"
#include "TextManager.h"

HRESULT Bag::Init()
{
	mBag1 = IMG_MGR->FindImage(eImageTag::Bag1);
	mBag2 = IMG_MGR->FindImage(eImageTag::Bag2);
	mBag3 = IMG_MGR->FindImage(eImageTag::Bag3);
	mBag4 = IMG_MGR->FindImage(eImageTag::Bag4);

	mBagCnt = 0;
	mProgressCnt = 0;

	mbBag = false;
	mbMonsterball = false;


	return S_OK;
}

void Bag::Update()
{
	if (mbBag == true)
	{
		if (Input::GetButtonDown(VK_DOWN))
		{
			++mBagCnt;
			if (mBagCnt > 3)
			{
				mBagCnt = 3;
			}
		}
		if (Input::GetButtonDown(VK_UP))
		{
			--mBagCnt;
			if (mBagCnt <= 0)
			{
				mBagCnt = 0;
			}
		}

	
		if (Input::GetButtonDown('A'))
		{
			++mProgressCnt;
			if (mBagCnt == 0)
			{
				if (ITEM_MGR->mMonsterball.amount > 0)
				{
					--ITEM_MGR->mMonsterball.amount;
					mbBag = false;
					mbMonsterball = true;
				}
			}
			if (mBagCnt == 1)
			{
				if (ITEM_MGR->mPlayerHeal.amount > 0)
				{
					--ITEM_MGR->mPlayerHeal.amount;
					POKE_MGR->mJiwooPokemon[0]->mHp += 20;
				}
			}
			if (mBagCnt == 2)
			{
				if (ITEM_MGR->mPlayerPowerHeal.amount > 0)
				{
					--ITEM_MGR->mPlayerPowerHeal.amount;
					POKE_MGR->mJiwooPokemon[0]->mHp += 60;
				}
			}
			if (mBagCnt == 3)
			{
				mbBag = false;
				mBagCnt = 0;
			}
		}
	}
	

}

void Bag::Render(HDC hdc)
{

	if (mBagCnt == 0)
	{
		mBag1->Render(hdc);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
			18, TEXT("PokemonGSC"));
		HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

		char ch[100];
		strcpy_s(ch, TXT_MGR->mItemScript[0].c_str());
		sprintf_s(mSampleText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mSampleText, -1, &rc, DT_WORDBREAK);
		SelectObject(hdc, hOldFont);
		DeleteObject(hFont);
	}
	if (mBagCnt == 1)
	{
		mBag2->Render(hdc);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
			18, TEXT("PokemonGSC"));
		HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

		char ch[100];
		strcpy_s(ch, TXT_MGR->mItemScript[1].c_str());
		sprintf_s(mSampleText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mSampleText, -1, &rc, DT_WORDBREAK);

		SelectObject(hdc, hOldFont);
		DeleteObject(hFont);
	}
	if (mBagCnt == 2)
	{
		mBag3->Render(hdc);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
			18, TEXT("PokemonGSC"));
		HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

		char ch[100];
		strcpy_s(ch, TXT_MGR->mItemScript[2].c_str());
		sprintf_s(mSampleText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mSampleText, -1, &rc, DT_WORDBREAK);

		SelectObject(hdc, hOldFont);
		DeleteObject(hFont);
	}
	if (mBagCnt == 3)
	{
		mBag4->Render(hdc);
	}
	
	SetTextColor(hdc, RGB(0, 0, 0));
	SetBkMode(hdc, TRANSPARENT);
	HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
		18, TEXT("PokemonGSC"));
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

	sprintf_s(mSampleText, "%d", ITEM_MGR->mMonsterball.amount);
	TextOut(hdc, 580, 76, mSampleText, strlen(mSampleText));

	sprintf_s(mSampleText, "%d", ITEM_MGR->mPlayerHeal.amount);
	TextOut(hdc, 580, 140, mSampleText, strlen(mSampleText));

	sprintf_s(mSampleText, "%d", ITEM_MGR->mPlayerPowerHeal.amount);
	TextOut(hdc, 580, 205, mSampleText, strlen(mSampleText));

	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
}

void Bag::Release()
{
}
