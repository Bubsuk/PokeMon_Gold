#include "stdafx.h"
#include "DogamScene.h"
#include "Image.h"

HRESULT DogamScene::Init()
{
	mDogamMain = IMG_MGR->FindImage(eImageTag::Dogam);

	return S_OK;
}

void DogamScene::Update()
{
}

void DogamScene::Render(HDC hdc)
{
}

void DogamScene::Release()
{
}
