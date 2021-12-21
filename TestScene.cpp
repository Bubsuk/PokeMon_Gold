#include "stdafx.h"
#include "TestScene.h"
#include "Image.h"
#include "Jiwoo.h"
#include "Pokemon.h"
#include "PokemonFactory.h"
#include "IngameMap.h"
#include "Collider.h"
#include "MapEditor.h"


HRESULT TestScene::Init()
{
    mBackGround = IMG_MGR->FindImage(eImageTag::StartRoom);
    aaa = IMG_MGR->FindImage(1);
    mJiwoo = new Jiwoo;
    mJiwoo->Init();
    auto factory = PokemonFactory();
    randomPokemon = factory.FactoryFunc(ePokemon::Caterpie);
    randomPokemon->Init();

    mCityMap = new IngameMap;
    mCityMap->Init();
    mCityMap->LoadMap("cityMap");
    mTileIn = mCityMap->GetTileInfo();
    CAM_MGR->SetPos(-640, -320);
    

    return S_OK;
}

void TestScene::Update()
{
    // 지우 위 타일좌표
    int indexX = (288 - CAM_MGR->GetCamPos().x) / TILE_SIZE;
    int indexY = (224 - CAM_MGR->GetCamPos().y) / TILE_SIZE;

    cout << indexY * TILE_COUNT_X + indexX << endl << endl;

    cout << (int)mTileIn[indexY * TILE_COUNT_X + indexX].Terrain << endl << endl;

    SAFE_UPDATE(mJiwoo);
    SAFE_UPDATE(randomPokemon);
    SAFE_UPDATE(mCityMap);
}

void TestScene::Render(HDC hdc)
{
    PatBlt(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, WHITENESS);

    if (mBackGround)
    {
        mBackGround->Render(hdc);
    }
    //aaa->Render(hdc);
    mCityMap->Render(hdc);
    randomPokemon->Render(hdc);

    mJiwoo->Render(hdc);
}

void TestScene::Release()
{
    SAFE_RELEASE(mJiwoo);
    SAFE_RELEASE(randomPokemon);
    SAFE_RELEASE(mCityMap);
}
