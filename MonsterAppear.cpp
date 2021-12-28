#include "stdafx.h"
#include "MonsterAppear.h"
#include "Image.h"
#include "PokemonManager.h"


HRESULT MonsterAppear::Init()
{
    mPlayerImg = IMG_MGR->FindImage(eImageTag::PlayerImg);
    mAppearMon = IMG_MGR->FindImage(eImageTag::AppearPoke);
	mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);
	mWhiteBk = IMG_MGR->FindImage(eImageTag::Background);

    // 몬스터볼 개수는 인벤토리매니저로 관리
    mPokeballState = IMG_MGR->FindImage(eImageTag::PokeBallState);

	mPlayerAppearX = 0;
	mBattlePokePosX = 0;

	mElasedCnt = 0.0f;

	mbAppeared = false;
	mbScripted = false;
	mbParticle = false;

	mAppProgCnt = 0;
	mFrameX = 3;

    return S_OK;
}

void MonsterAppear::Update()
{
	mElasedCnt += DELTA_TIME;

	mPlayerAppearX = WIN_SIZE_X + 100 - (WIN_SIZE_X - 50) * mElasedCnt / 1.5f;
	mBattlePokePosX = -100 + (WIN_SIZE_X - 50) * mElasedCnt / 1.5f;

	if (mElasedCnt > 1.5f)
	{
		mPlayerAppearX = 150;
		mBattlePokePosX = WIN_SIZE_X - 150;
		
		if (mAppProgCnt >= TXT_MGR->mBattleScript.size())
		{
			mbScripted = true;
			mElasedCnt = 0.0f;
		}
	}

	if (mbScripted == true)
	{
		if (mElasedCnt > 0.15f)
		{
			--mFrameX;
			mElasedCnt = 0.0f;
			
		}
		if (mFrameX < 0)
		{
			mbParticle = true;
			mbAppeared = true;
		}
	}
	
	if (Input::GetButtonDown('Z'))
	{
		++mAppProgCnt;
	}

}

void MonsterAppear::Render(HDC hdc)
{
	mWhiteBk->Render(hdc);
	mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

	if (mbScripted == false)
	{
		POKE_MGR->mTempPokemon->mFrontImg->Render(hdc, mBattlePokePosX, 120);
		mPlayerImg->Render(hdc, mPlayerAppearX, WIN_SIZE_Y / 2);
		for (int i = 0; i < 6; ++i)
		{
			mPokeballState->Render(hdc, 400 + (28 * i), 300, 0, 3);
		}
		for (int i = 0; i < ITEM_MGR->mMonsterball.amount; ++i)
		{
			mPokeballState->Render(hdc, 400 + (28 * i), 300, 0, 0);
		}

		if (mAppProgCnt < TXT_MGR->mBattleScript.size())
		{
			char ch[256];
			strcpy_s(ch, TXT_MGR->mBattleScript[mAppProgCnt].c_str());
			sprintf_s(mText, ch);
			RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
			DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
		}
		
	}

	if (mbScripted == true)
	{
		mAppearMon->Render(hdc, 150, WIN_SIZE_Y / 2, mFrameX, 0);

	}
	
}

void MonsterAppear::Release()
{

}
