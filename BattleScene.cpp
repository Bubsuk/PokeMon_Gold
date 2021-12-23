#include "stdafx.h"
#include "BattleScene.h"
#include "Image.h"

HRESULT BattleScene::Init()
{
    mBattleMain = IMG_MGR->FindImage(eImageTag::BattleFrame);
    mBattleSkill = IMG_MGR->FindImage(eImageTag::BattleSkill);
    mBattleSelect = IMG_MGR->FindImage(eImageTag::BattleSelect);
    mBattleCusor = IMG_MGR->FindImage(eImageTag::CursorRight);

    mJiwooImg = IMG_MGR->FindImage(eImageTag::PlayerImg);

    return S_OK;
}

void BattleScene::Update()
{
    
}

void BattleScene::Render(HDC hdc)
{
    mBattleMain->Render(hdc);
}

void BattleScene::Release()
{
  
}
