#include "stdafx.h"
#include "BattleScene.h"
#include "Image.h"
#include "PokemonManager.h"
#include "TextManager.h"
#include "InventoryManager.h"
#include "RandomManager.h"
#include "Bag.h"

HRESULT BattleScene::Init()
{
	mBattleBackground = IMG_MGR->FindImage(eImageTag::BattleFrame);
	mBattleSkill = IMG_MGR->FindImage(eImageTag::BattleSkill);
	mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);
	mCursor = IMG_MGR->FindImage(eImageTag::CursorRight);

	//mHpBar = IMG_MGR->FindImage(eImageTag::HpBar);
	mHpGauge = IMG_MGR->FindImage(eImageTag::HpGauge);
	mExpGauge = IMG_MGR->FindImage(eImageTag::ExpGauge);

	mGender = IMG_MGR->FindImage(eImageTag::Gender);


	mPlayerImg = IMG_MGR->FindImage(eImageTag::PlayerImg);
	mAppearMon = IMG_MGR->FindImage(eImageTag::AppearPoke);

	mMonsterball = IMG_MGR->FindImage(eImageTag::Monsterball);
	
	// 몬스터볼 개수는 인벤토리매니저로 관리
	mPokeballState = IMG_MGR->FindImage(eImageTag::PokeBallState);

	mBag = new Bag;
	mBag->Init();

	mbScripted = false;
	mbBattleFrame = false;
	mbAppeared = false;
	mbJiwooOut = false;
	mbParticle = false;
	mbSkillWindow = false;
	mbPokemon = false;
	mbBag = false;
	mbAttak[0] = false;
	mbAttak[1] = false;
	mbAttak[2] = false;
	mbAttak[3] = false;

	mElasedCnt = 0.0f;
	mScriptCnt = 0;
	mProgressCnt = 0;


	mBattlePokePosX = -100;
	mPlayerAppearX = WIN_SIZE_X + 100;

	mFrameX = 3;

	mCursorPos = { 300, 460 };
	mSkillCursorPos = { 60, WIN_SIZE_Y / 2 + 60 };
	mCursorCnt = 0;
	mSkillCurCnt = 0;
	mEnemySkillNum = 0;

	TXT_MGR->BattleScript();

	mMonsterballPos = { {173, 329}, {236, 228}, {293, 149}, {348, 106}, {429, 126}, {492, 165} };

	return S_OK;
}

void BattleScene::Update()
{
	/*cout << "mScriptCnt : " << mScriptCnt << endl;
	cout << "mProgressCnt : " << mProgressCnt << endl;
	cout << "mbSkillWindow : " << mbSkillWindow << endl << endl;*/

	mElasedCnt += DELTA_TIME;
	// 등장
	if (mbAppeared == false)
	{
		mPlayerAppearX = WIN_SIZE_X + 100 - (WIN_SIZE_X-50) * mElasedCnt / 1.5f;
		mBattlePokePosX = -100 + (WIN_SIZE_X - 50) * mElasedCnt / 1.5f;
		if (mElasedCnt > 1.5f)
		{
			mPlayerAppearX = 150;
			mBattlePokePosX = WIN_SIZE_X - 150;
			mbAppeared = true;
			mElasedCnt = 0.0f;
		}
	}
	// 진행카운터
	if (mbScripted == false)
	{
		if (Input::GetButtonDown('Z'))
		{
			if (mScriptCnt >= TXT_MGR->mBattleScript.size() - 1)
			{
				mProgressCnt = 2;
				mbScripted = true;
				mScriptCnt = 2;
			}
			else
			{
				++mScriptCnt;
			}
		}

	}
	
	if (mScriptCnt == 1 && mbParticle == false)
	{
		if (mElasedCnt > 0.15f)
		{
			--mFrameX;
			mElasedCnt = 0;
		}
		if (mFrameX < 0)
		{
			mbBattleFrame = true;
			mbParticle = true;
			mProgressCnt = 2;
		}
	}


	// 메인 배틀프레임 mProgressCnt == 0
	if (mbBattleFrame == true && mProgressCnt == 2)
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

		if (Input::GetButtonDown('Z') && mCursorCnt == 0)
		{
			mProgressCnt = 3;
			mbSkillWindow = true;
			mbBattleFrame = false;
		}
		if (Input::GetButtonDown('Z') && mCursorCnt == 1)
		{
			mProgressCnt = 3;
			mbPokemon = true;
			mbBattleFrame = false;
		}
		if (Input::GetButtonDown('Z') && mCursorCnt == 2)
		{
			mProgressCnt = 3;
			mbBag = true;
			mbBattleFrame = false;
		}
		if (Input::GetButtonDown('Z') && mCursorCnt == 3)
		{
			SAFE_DELETE(POKE_MGR->mTempPokemon);
			SCENE_MGR->ChangeScene(eSceneTag::CityScene);
		}

	}

	// 싸우다 선택
	if (mbSkillWindow == true && mProgressCnt == 3)
	{
		mSkillCursorPos.y = WIN_SIZE_Y / 2 + 60 + (60 * mSkillCurCnt);
		if (Input::GetButtonDown(VK_DOWN))
		{
			++mSkillCurCnt;
			if (mSkillCurCnt > POKE_MGR->mJiwooPokemon[0]->mPokeSkill.size() - 1)
			{
				mSkillCurCnt = 0;
			}
		}
		if (Input::GetButtonDown(VK_UP))
		{
			--mSkillCurCnt;
			if (mSkillCurCnt < 0)
			{
				mSkillCurCnt = POKE_MGR->mJiwooPokemon[0]->mPokeSkill.size() - 1;
			}
		}

		if (Input::GetButtonDown('A'))
		{
			mProgressCnt = 4;
			mbAttak[mSkillCurCnt] = true;
			Attack mfAttack{ POKE_MGR->mTempPokemon->mHp };
			POKE_MGR->mTempPokemon->mHp = mfAttack(POKE_MGR->mJiwooPokemon[0]->mPokeSkill[mSkillCurCnt]->mAttack);
			if (POKE_MGR->mTempPokemon->mHp <= 0)
			{
				mProgressCnt = 7;
			}

		}

		if (Input::GetButtonDown('X'))
		{
			mbSkillWindow = false;
			mbBattleFrame = true;
			mProgressCnt = 2;
		}
	}

	// 가방 선택
	if (mbBag == true && mProgressCnt == 3)
	{
		mBag->Update();
		if (mBag->mBagCnt == 3 && Input::GetButtonDown('Z'))
		{
			mbBag = false;
			mbBattleFrame = true;
			mProgressCnt = 2;
		}
	}
	if (mProgressCnt == 4)
	{
		if (Input::GetButtonDown('Z'))
		{
			mProgressCnt = 5;
			mEnemySkillNum = RandomManager::RandomPeeker(0, POKE_MGR->mTempPokemon->mPokeSkill.size() - 1);
			Attacked mfAttacked{ POKE_MGR->mTempPokemon, mEnemySkillNum };
			POKE_MGR->mJiwooPokemon[0]->mHp = mfAttacked(POKE_MGR->mTempPokemon, mEnemySkillNum);
			if (POKE_MGR->mTempPokemon->mHp <= 0)
			{
				mProgressCnt = 7;
			}
		}
	}

	if (mProgressCnt == 5)
	{
		if (Input::GetButtonDown('A'))
		{
			mbSkillWindow = false;
			mbBattleFrame = true;
			mProgressCnt = 2;
		}
	}
	// 몬스터 사망
	/*if (mProgressCnt == 7)
	{
		if (Input::GetButtonDown('Z'))
		{
			mbSkillWindow = false;
			mbBattleFrame = true;
			mProgressCnt = 2;
		}
	}*/

	//포켓볼 던지기

	mBallPos = DrawMonsterballLine((int)mElasedCnt);

	//////////////////////////////////
	if (POKE_MGR->mJiwooPokemon[0]->mHp <= 0)
	{
		mProgressCnt == 6;
	}
	else if (POKE_MGR->mTempPokemon->mHp <= 0)
	{
		mProgressCnt == 6;
	}
    
}

void BattleScene::Render(HDC hdc)
{
	mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

	SetTextColor(hdc, RGB(0, 0, 0));
	HFONT font = CreateFont(40, 0, 0, 0, 700, 0, 0, 0, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));
	HFONT oldFont = (HFONT)SelectObject(hdc, font);
	SetBkMode(hdc, TRANSPARENT);

	if (mbParticle == true)
	{
		BattleFrame(hdc);
	}

	Appear(hdc);

	if (mbSkillWindow == true && (3 <= mProgressCnt && mProgressCnt < 5))
	{
		PlayerAttack(hdc);
	}
	if (mbBag == true)
	{
		mBag->Render(hdc);
	}

	if (mProgressCnt == 5)
	{		
		mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

		char ch[100];
		strcpy_s(ch, TXT_MGR->mEnemyScript[mEnemySkillNum].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
			
	}

	DeleteObject(SelectObject(hdc, oldFont));
}


void BattleScene::Appear(HDC hdc)
{
	POKE_MGR->mTempPokemon->mFrontImg->Render(hdc, mBattlePokePosX, 120);

	if (mbParticle == false)
	{
		char ch[100];
		strcpy_s(ch, TXT_MGR->mBattleScript[mScriptCnt].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
	}

	if (mScriptCnt < 1)
	{
		mPlayerImg->Render(hdc, mPlayerAppearX, WIN_SIZE_Y / 2);
		for (int i = 0; i < 6; ++i)
		{
			mPokeballState->Render(hdc, 400 + (28 * i), 300, 0, 3);
		}
		for (int i = 0; i < ITEM_MGR->mMonsterball.amount; ++i)
		{
			mPokeballState->Render(hdc, 400 + (28 * i), 300, 0, 0);
		}
	}
	if (mProgressCnt > 1)
	{
		POKE_MGR->mJiwooPokemon[0]->mBackImg->Render(hdc, 150, WIN_SIZE_Y / 2);

	}
	// 포켓몬 등장
	if (mbParticle == false)
	{
		mAppearMon->Render(hdc, 150, WIN_SIZE_Y / 2, mFrameX, 0);
	}

}
void BattleScene::BattleFrame(HDC hdc)
{
	mBattleBackground->Render(hdc);
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
	TextOut(hdc, 360, 310, ch, strlen(ch));

	sprintf_s(ch, "%d", POKE_MGR->mJiwooPokemon[0]->mMaxHp);
	TextOut(hdc,480, 310, ch, strlen(ch));
}
void BattleScene::PlayerAttack(HDC hdc)
{
	if (mProgressCnt == 3)
	{
		mBattleSkill->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y - 150);
		mCursor->Render(hdc, mSkillCursorPos.x, mSkillCursorPos.y);


		char ch[100];
		for (int i = 0; i < POKE_MGR->mJiwooPokemon[0]->mPokeSkill.size(); ++i)
		{
			HFONT font = CreateFont(50, 0, 0, 0, 700, 0, 0, 0, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
				DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));
			HFONT oldFont = (HFONT)SelectObject(hdc, font);

			strcpy_s(ch, POKE_MGR->mJiwooPokemon[0]->mPokeSkill[i]->mSkillName.c_str());
			sprintf_s(mText, ch);
			TextOut(hdc, 80, WIN_SIZE_Y / 2 + 30 + (60 * i), mText, strlen(mText));


			DeleteObject(SelectObject(hdc, oldFont));
		}
	}
	
	if (mProgressCnt == 4)
	{
		mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		char ch[100];
		strcpy_s(ch, TXT_MGR->mBattleScript1[mSkillCurCnt].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
	}
	
}

void BattleScene::EnemyAttack(HDC hdc)
{
}

void BattleScene::UseMonsterBall(HDC hdc)
{
}

POINT BattleScene::DrawMonsterballLine(int curTime)
{
	POINT before, after, result;
	int delay = 3;
	int currentIndex = (curTime / delay) % mMonsterballPos.size();
	before = mMonsterballPos[currentIndex];
	after = mMonsterballPos[(currentIndex + 1) % mMonsterballPos.size()];

	// progress between [before] and [after]
	double progress = fmod((((double)curTime) / (double)delay), (double)mMonsterballPos.size()) - currentIndex;

	result.x = before.x + (int)progress * (after.x - before.x);
	result.y = before.y + (int)progress * (after.y - before.y);


	return result;
}

void BattleScene::Release()
{
  
}


