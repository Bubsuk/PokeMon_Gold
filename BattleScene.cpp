#include "stdafx.h"
#include "BattleScene.h"
#include "BattleManager.h"

HRESULT BattleScene::Init()
{
	mBattle = new BattleManager;
	mBattle->Init();
	return S_OK;
}

void BattleScene::Update()
{
	mBattle->Update();
    
}

void BattleScene::Render(HDC hdc)
{
	mBattle->Render(hdc);
}

void BattleScene::Release()
{
	mBattle->Release();
	SAFE_RELEASE(mBattle);
}

