#include "stdafx.h"
#include "TestScene.h"
#include "Jiwoo.h"
#include "Pokemon.h"
#include "MapManager.h"
#include "Collider.h"


HRESULT TestScene::Init()
{
    mMonsterball = IMG_MGR->FindImage(eImageTag::PokeBall);
    mMonsterGoalIn = IMG_MGR->FindImage(eImageTag::AppearPoke);

    mGoalInFrameX = 3;

    mElapsedCnt = 0.0f;

    mMonsterballPosX = 0;
    mMonsterballPosY = 500;
    mBallSpeed = 150.0f;
    mGravity = 800.0f;
    mHeightLimit = 80;

    return S_OK;
}

void TestScene::Update()
{
    float a = DELTA_TIME;
    mElapsedCnt += (a * 100.0f);

    mMonsterballPosX += 300 * DELTA_TIME
    mMonsterballPosY -= 150 * DELTA_TIME - mElapsedCnt * mGravity;

    //float a = DELTA_TIME;
    cout << mElapsedCnt << endl;
    cout << mMonsterballPosX << endl;
    cout << mMonsterballPosY << endl << endl;
}

void TestScene::Render(HDC hdc)
{
    mMonsterball->Render(hdc, mMonsterballPosX, mMonsterballPosY);
}

void TestScene::Release()
{
   
}
