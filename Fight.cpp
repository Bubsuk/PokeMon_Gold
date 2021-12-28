#include "stdafx.h"
#include "Fight.h"

HRESULT Fight::Init()
{
    mBattleSkill = IMG_MGR->FindImage(eImageTag::BattleSkill);
	mCursor = IMG_MGR->FindImage(eImageTag::CursorRight);
	mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);

    mbFight = false;
	mSkillCurCnt = 0;
	mProgressCnt = 0;

	mSkillCursorPos = { 60, WIN_SIZE_Y / 2 + 60 };

	TXT_MGR->BattleScript();

    return S_OK;
}

void Fight::Update()
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
			Attack mfAttack{ POKE_MGR->mTempPokemon->mHp };
			POKE_MGR->mTempPokemon->mHp = mfAttack(POKE_MGR->mJiwooPokemon[0]->mPokeSkill[mSkillCurCnt]->mAttack);
		}
		else if (mProgressCnt == 2)
		{
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


			DeleteObject(SelectObject(hdc, oldFont));
		}
	}
	if (mProgressCnt == 1)
	{
		mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		char ch[100];
		strcpy_s(ch, TXT_MGR->mBattleScript1[mSkillCurCnt].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
	}
	if (mProgressCnt == 2)
	{
		mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		char ch[100];
		strcpy_s(ch, TXT_MGR->mEnemyScript[mSkillCurCnt].c_str());
		sprintf_s(mText, ch);
		RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
		DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);
	}
}

void Fight::Release()
{
}
