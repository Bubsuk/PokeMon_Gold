#include "stdafx.h"
#include "Config.h"
#include "Image.h"
#include "CatchPokemon.h"
#include "PokemonManager.h"

HRESULT CatchPokemon::Init()
{
    mMonsterball = IMG_MGR->FindImage(eImageTag::PokeBall);
    mMonsterGoalIn = IMG_MGR->FindImage(eImageTag::AppearPoke);
    mBlind = IMG_MGR->FindImage(eImageTag::Blind);
    mDialogue = IMG_MGR->FindImage(eImageTag::Dialogue);

    mGoalInFrameX = 3;

    mElapsedCnt = 0.0f;


    mbCatch = false;
    mbBall = false;
    mParticle = true;
    mbCatchEnd = false;

   

    return S_OK;
}

void CatchPokemon::Update()
{
    if (mbCatch == true)
    {
        mElapsedCnt += DELTA_TIME;

        if (mElapsedCnt > 1.0f)
        {
            POKE_MGR->CatchPoke(POKE_MGR->mTempPokemon);
            mbCatch = false;
            mbCatchEnd = true;

        }

        if (mParticle == true)
        {
            if (mElapsedCnt > 0.15f)
            {
                --mGoalInFrameX;
                mElapsedCnt = 0.0f;
            }
            if (mGoalInFrameX < 0)
            {
                mParticle = false;
            }
        }
    }
   
   
}

void CatchPokemon::Render(HDC hdc)
{

    mBlind->Render(hdc, 480, 150);
    mMonsterball->Render(hdc, 440, 175);
    if (mParticle == true)
    {
        mMonsterGoalIn->Render(hdc, 440, 175, mGoalInFrameX, 0);
    }

    mDialogue->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
    char ch[100];
    strcpy_s(ch, TXT_MGR->mBattleScript1[6].c_str());
    sprintf_s(mText, ch);
    RECT rc = { 25, WIN_SIZE_Y / 2 + 135, WIN_SIZE_X - 50, WIN_SIZE_Y - 30 };
    DrawText(hdc, mText, -1, &rc, DT_WORDBREAK);

}

void CatchPokemon::Release()
{
}
