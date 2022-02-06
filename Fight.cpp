#include "stdafx.h"
#include "Fight.h"

HRESULT Fight::Init()
{
    mBattleSkill = IMG_MGR->FindImage(eImageTag::BattleSkill);
	mCursor = IMG_MGR->FindImage(eImageTag::CursorRight);
	mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);

    mbFight = false;
	mPlayerPokeEffect = false;
	mbPlayerDie = false;
	mbEnemyDie = false;
	mbFightEnd = false;
	mSkillCurCnt = 0;
	mProgressCnt = 0;
	mEffectFrameX = 0;
	
	mSkillCursorPos = { 60, WIN_SIZE_Y / 2 + 60 };

	mElapsedCnt = 0.0f;

    return S_OK;
}

void Fight::Update()
{
	if (mbFight == true && mbPlayerDie == false && mbEnemyDie == false)
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

		if (Input::GetButtonDown('Z'))
		{
			
			++mProgressCnt;
			if (mProgressCnt == 1)
			{
				mPlayerPokeEffect = true;
				Attack mfAttack{ POKE_MGR->mTempPokemon->mHp };
				POKE_MGR->mTempPokemon->mHp = mfAttack(POKE_MGR->mJiwooPokemon[0]->mPokeSkill[mSkillCurCnt]->mAttack);

			}
			else if (mProgressCnt == 2)
			{
				mEnemyPokeEffect = true;
				mEnemySkillNum = RandomManager::RandomPeeker(0, POKE_MGR->mTempPokemon->mPokeSkill.size() - 1);
				Attacked mfAttacked{ POKE_MGR->mTempPokemon, mEnemySkillNum };
				POKE_MGR->mJiwooPokemon[0]->mHp = mfAttacked(POKE_MGR->mTempPokemon, mEnemySkillNum);
				
			}

		}
		

		if (Input::GetButtonDown('X') || mProgressCnt == 3)
		{
			mbFight = false;
			mSkillCurCnt = 0;
			mProgressCnt = 0;
		}
	}

	if (POKE_MGR->mTempPokemon->mHp <= 0 && mbPlayerDie == false)
	{
		POKE_MGR->mTempPokemon->mHp = 0;
		mElapsedCnt += DELTA_TIME;
		mbEnemyDie = true;
		if (mElapsedCnt > 2.0f)
		{
			mbFightEnd = true;
			mbFight = false;
			mSkillCurCnt = 0;
			mProgressCnt = 0;
			mElapsedCnt = 0.0f;
		
		}
	}
	if (POKE_MGR->mJiwooPokemon[0]->mHp <= 0 && mbEnemyDie == false)
	{
		POKE_MGR->mJiwooPokemon[0]->mHp = 0;
		mElapsedCnt += DELTA_TIME;
		mbPlayerDie = true;
		if (mElapsedCnt > 2.0f)
		{
			mbFightEnd = true;
			mbFight = false;
			mSkillCurCnt = 0;
			mProgressCnt = 0;
			mElapsedCnt = 0.0f;
			
		}
	}

	if (mPlayerPokeEffect == true)
	{
		mElapsedCnt += DELTA_TIME;
		mEffectFrameX = (mElapsedCnt * 100) / 8;
		
		if (mEffectFrameX > POKE_MGR->mJiwooPokemon[0]->mPokeSkill[mSkillCurCnt]->mSkillFrameX)
		{
			mElapsedCnt = 0.0f;
			mEffectFrameX = 0;
			mPlayerPokeEffect = false;
		}
	}

	if (mEnemyPokeEffect == true)
	{
		mElapsedCnt += DELTA_TIME;
		mEffectFrameX = (mElapsedCnt * 100) / 8;

		if (mEffectFrameX > POKE_MGR->mTempPokemon->mPokeSkill[mSkillCurCnt]->mSkillFrameX)
		{
			mElapsedCnt = 0.0f;
			mEffectFrameX = 0;
			mEnemyPokeEffect = false;
		}
	}
	
}

void Fight::Render(HDC hdc)
{
	if (mProgressCnt < 1)
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


			SelectObject(hdc, oldFont);
			DeleteObject(font);
		}
	}
	if (mProgressCnt == 1)
	{
		mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		if (mPlayerPokeEffect == true)
		{
			POKE_MGR->mJiwooPokemon[0]->mPokeSkill[mSkillCurCnt]->mSkillImg->Render(hdc, WIN_SIZE_X - 200, 120, mEffectFrameX, 0, 2.5f);
		}
		
		char ch[100];
		strcpy_s(ch, TXT_MGR->mBattleScript1[mSkillCurCnt].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);

		if (mbEnemyDie == true)
		{
			char ch[100];
			strcpy_s(ch, TXT_MGR->mBattleScript1[5].c_str());
			sprintf_s(mText, ch);
			RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
			DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
		}
	}
	if (mProgressCnt == 2)
	{
		mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		if (mEnemyPokeEffect == true)
		{
			POKE_MGR->mTempPokemon->mPokeSkill[mEnemySkillNum]->mSkillImg->Render(hdc, 100, WIN_SIZE_Y / 2, mEffectFrameX, 0, 2.5f);
		}

		char ch[100];
		strcpy_s(ch, TXT_MGR->mEnemyScript[mEnemySkillNum].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);

		if (mbPlayerDie == true)
		{
			char ch[100];
			strcpy_s(ch, TXT_MGR->mBattleScript1[3].c_str());
			sprintf_s(mText, ch);
			RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
			DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
		}
	}
}

void Fight::Release()
{
}
