#include "stdafx.h"
#include "Bag.h"
#include "Image.h"
#include "InventoryManager.h"
#include "TextManager.h"

HRESULT Bag::Init()
{
	mBag1 = IMG_MGR->FindImage(eImageTag::Bag1);
	mBag2 = IMG_MGR->FindImage(eImageTag::Bag2);
	mBag3 = IMG_MGR->FindImage(eImageTag::Bag3);
	mBag4 = IMG_MGR->FindImage(eImageTag::Bag4);

	mBagCnt = 0;

	mbControl = true;

	return S_OK;
}

void Bag::Update()
{
	if (mbControl == true)
	{
		if (Input::GetButtonDown(VK_DOWN))
		{
			++mBagCnt;
		}
		if (Input::GetButtonDown(VK_UP))
		{
			--mBagCnt;
		}

		if (mBagCnt <= 0)
		{
			mBagCnt = 0;
		}
		if (mBagCnt > 3)
		{
			mBagCnt = 3;
		}

		if (Input::GetButtonDown('A'))
		{
			mbControl = false;
			if (mBagCnt == 0)
			{
				if (ITEM_MGR->mMonsterball.amount > 0)
				{
					--ITEM_MGR->mMonsterball.amount;

				}
			}
			if (mBagCnt == 1)
			{
				if (ITEM_MGR->mPlayerHeal.amount > 0)
				{
					--ITEM_MGR->mPlayerHeal.amount;
				}
			}
			if (mBagCnt == 2)
			{
				if (ITEM_MGR->mPlayerPowerHeal.amount > 0)
				{
					--ITEM_MGR->mPlayerPowerHeal.amount;
				}
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

		DeleteObject(SelectObject(hdc, hOldFont));
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

		DeleteObject(SelectObject(hdc, hOldFont));
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

		DeleteObject(SelectObject(hdc, hOldFont));
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

	DeleteObject(SelectObject(hdc, hOldFont));
}

void Bag::Release()
{
}
