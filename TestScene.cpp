#include "stdafx.h"
#include "TestScene.h"
#include "Jiwoo.h"
#include "Pokemon.h"
#include "PokemonFactory.h"
#include "MapManager.h"
#include "Collider.h"


HRESULT TestScene::Init()
{
    //mBackGround = IMG_MGR->FindImage(eImageTag::StartRoom);
    //aaa = IMG_MGR->FindImage(1);
    CON_MGR->Init();
    //mJiwooPos = mJiwoo->GetPosition();

    MAP_MGR->LoadMap("cityMap");
    
    CAM_MGR->SetPos(-500, -320);
    

    return S_OK;
}

void TestScene::Update()
{
    // 지우 위 타일좌표
   

    CON_MGR->Update();
    //SAFE_UPDATE(randomPokemon);

}

void TestScene::Render(HDC hdc)
{
   // PatBlt(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, WHITENESS);

    //if (mBackGround)
    //{
    //    mBackGround->Render(hdc);
    //}
    //aaa->Render(hdc);
    MAP_MGR->DrawMap(hdc);
   // randomPokemon->Render(hdc);

    CON_MGR->Render(hdc);
}

void TestScene::Release()
{
    CON_MGR->Release();
   // SAFE_RELEASE(randomPokemon);
  
}
