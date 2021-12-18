#include "stdafx.h"
#include "TestScene.h"
#include "Image.h"
#include "Jiwoo.h"
#include "Pokemon.h"
#include "PokemonFactory.h"



HRESULT TestScene::Init()
{
    mBackGround = IMG_MGR->FindImage(eImageTag::StartRoom);

    mJiwoo = new Jiwoo;
    mJiwoo->Init();
    auto factory = PokemonFactory();
    randomPokemon = factory.FactoryFunc(ePokemon::Caterpie);
    randomPokemon->Init();

    return S_OK;
}

void TestScene::Update()
{
    SAFE_UPDATE(mJiwoo);
    SAFE_UPDATE(randomPokemon);
}

void TestScene::Render(HDC hdc)
{
    PatBlt(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, WHITENESS);

    if (mBackGround)
    {
        mBackGround->Render(hdc);
    }
   
    randomPokemon->Render(hdc);

    mJiwoo->Render(hdc);
}

void TestScene::Release()
{
    SAFE_RELEASE(mJiwoo);
    SAFE_RELEASE(randomPokemon);
}
