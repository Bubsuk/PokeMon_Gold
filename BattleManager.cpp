#include "stdafx.h"
#include "BattleManager.h"
#include "Image.h"
#include "PokemonManager.h"
#include "Fight.h"
#include "Bag.h"
#include "MenuPokemon.h"
#include "CatchPokemon.h"
#include "MonsterAppear.h"


HRESULT BattleManager::Init()
{
	// 기본 프레임
	mBattleBackground = IMG_MGR->FindImage(eImageTag::BattleFrame);
	
	mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);
	mCursor = IMG_MGR->FindImage(eImageTag::CursorRight);
	mHpGauge = IMG_MGR->FindImage(eImageTag::HpGauge);
	mExpGauge = IMG_MGR->FindImage(eImageTag::ExpGauge);
	mGender = IMG_MGR->FindImage(eImageTag::Gender);
	
	TXT_MGR->BattleScript();

	mAppear = new MonsterAppear;
	mAppear->Init();
	
	mFightScene = new Fight;
	mFightScene->Init();

	mBag = new Bag;
	mBag->Init();

	mMenuPoke = new MenuPokemon;
	mMenuPoke->Init();
	
	mCatchScene = new CatchPokemon;
	mCatchScene->Init();

	mCursorCnt = 0;
	mCursorPos = { 300, 460 };

	
	
	/*mbBasicFrame = false;
	mbMenu = false;
	mbBag = false;
	mbCatch = false;*/

	mElapsedCnt = 0.0f;


    return S_OK;
}

void BattleManager::Update()
{
	mElapsedCnt += DELTA_TIME;

	mAppear->Update();

	mFightScene->Update();

	mMenuPoke->Update();

	mBag->Update();

	if (mBag->mbMonsterball == true)
	{
		mCatchScene->mbCatch = true;
	}

	mCatchScene->Update();


	if (mMenuPoke->mbMenu == false && mFightScene->mbFight == false
		&& mBag->mbBag == false && mAppear->mbAppeared == true)
	{
		if (Input::GetButtonDown(VK_DOWN))
		{
			++mCursorCnt;
			if (mCursorCnt >= 4)
			{
				mCursorCnt = 0;
			}
			mCursorPos.x = 300 + (mCursorCnt / 2) * 150;
			mCursorPos.y = 460 + (mCursorCnt % 2) * 70;
		}
		if (Input::GetButtonDown(VK_UP))
		{
			--mCursorCnt;
			if (mCursorCnt < 0)
			{
				mCursorCnt = 0;
			}
			mCursorPos.x = 300 + (mCursorCnt / 2) * 150;
			mCursorPos.y = 460 + (mCursorCnt % 2) * 70;
		}
		
		if (Input::GetButtonDown('A') && mCursorCnt == 0)
		{
			mFightScene->mbFight = true;
		}
		if (Input::GetButtonDown('Z') && mCursorCnt == 1)
		{
			mMenuPoke->mbMenu = true;
		}
		if (Input::GetButtonDown('Z') && mCursorCnt == 2)
		{
			mBag->mbBag = true;
		}
		if ((Input::GetButtonDown('Z') && mCursorCnt == 3) || mCatchScene->mbCatchEnd == true
			|| mFightScene->mbFightEnd == true)
		{
			TXT_MGR->ClearBattleScript();
			SCENE_MGR->ChangeScene(eSceneTag::CityScene);
		}

		
	}
	
}

void BattleManager::Render(HDC hdc)
{
	SetTextColor(hdc, RGB(0, 0, 0));
	SetBkColor(hdc, RGB(248, 248, 248));
	HFONT hFont = CreateFont(36, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 3, 2, 1,
		18, TEXT("PokemonGSC"));
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

	BattleFrameRender(hdc);

	if(mAppear->mbAppeared == false)
	{
		mAppear->Render(hdc);
	}
	if (mFightScene->mbFight == true)
	{
		mFightScene->Render(hdc);
	}
	if (mBag->mbBag == true)
	{
		mBag->Render(hdc);
	}
	if (mMenuPoke->mbMenu == true)
	{
		mMenuPoke->Render(hdc);
	}
	if (mCatchScene->mbCatch == true)
	{
		mCatchScene->Render(hdc);
	}

	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
}

void BattleManager::Release()
{
	SAFE_RELEASE(mAppear);
	SAFE_RELEASE(mFightScene);
	SAFE_RELEASE(mBag);
	SAFE_RELEASE(mMenuPoke);
	SAFE_RELEASE(mCatchScene);
}

void BattleManager::BattleFrameRender(HDC hdc)
{
	mBattleBackground->Render(hdc);

	POKE_MGR->mTempPokemon->mFrontImg->Render(hdc, WIN_SIZE_X - 150, 120);
	POKE_MGR->mJiwooPokemon[0]->mBackImg->Render(hdc, 150, WIN_SIZE_Y / 2);

	mHpGauge->hpRender(hdc, 478, WIN_SIZE_Y / 2 + 17, POKE_MGR->mJiwooPokemon[0]->mMaxHp, POKE_MGR->mJiwooPokemon[0]->mHp);
	mHpGauge->hpRender(hdc, 223, 80, POKE_MGR->mTempPokemon->mMaxHp, POKE_MGR->mTempPokemon->mHp);
	mCursor->Render(hdc, mCursorPos.x, mCursorPos.y);
	if (POKE_MGR->mTempPokemon->mGender == Gender::Male)
	{
		mGender->Render(hdc, WIN_SIZE_X / 2 - 80, 50, 0, 0);
	}
	else
	{
		mGender->Render(hdc, WIN_SIZE_X / 2 - 80, 50, 0, 1);
	}
	if (POKE_MGR->mJiwooPokemon[0]->mGender == Gender::Male)
	{
		mGender->Render(hdc, WIN_SIZE_X - 145, WIN_SIZE_Y / 2 - 10, 0, 0);
	}
	else
	{
		mGender->Render(hdc, WIN_SIZE_X - 145, WIN_SIZE_Y / 2 - 10, 0, 0);
	}

	char ch[100];
	strcpy_s(ch, POKE_MGR->mTempPokemon->mName.c_str());
	sprintf_s(mText, ch);
	TextOut(hdc, WIN_SIZE_X / 2 - 200, 25, mText, strlen(mText));

	strcpy_s(ch, POKE_MGR->mJiwooPokemon[0]->mName.c_str());
	sprintf_s(mText, ch);
	TextOut(hdc, WIN_SIZE_X / 2 + 60, WIN_SIZE_Y / 2 - 35, mText, strlen(mText));

	sprintf_s(ch, "%d ", POKE_MGR->mJiwooPokemon[0]->mHp);
	TextOut(hdc, 360, 320, ch, strlen(ch));

	sprintf_s(ch, "%d", POKE_MGR->mJiwooPokemon[0]->mMaxHp);
	TextOut(hdc, 480, 320, ch, strlen(ch));
}

