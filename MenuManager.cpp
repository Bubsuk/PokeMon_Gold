#include "stdafx.h"
#include "MenuManager.h"
#include "Image.h"
#include "Jiwoo.h"
#include "Dogam.h"
#include "MenuPokemon.h"
#include "Bag.h"

HRESULT MenuManager::Init()
{
	mMenuDogam = IMG_MGR->FindImage(eImageTag::MenuDogam);// 시작화면
	mMenuPoke = IMG_MGR->FindImage(eImageTag::MenuPoke);
	mMenuBag = IMG_MGR->FindImage(eImageTag::MenuBag);
	mMenuGear = IMG_MGR->FindImage(eImageTag::MenuGear);
	mMenuPlayer = IMG_MGR->FindImage(eImageTag::MenuPlayer);
	mMenuSetting = IMG_MGR->FindImage(eImageTag::MenuSet);
	mMenuClose = IMG_MGR->FindImage(eImageTag::MenuClose);

	mbMenuCon = true;

	mDogam = new Dogam;
	mDogam->Init();
	mbDogam = false;

	mPokemon = new MenuPokemon;
	mPokemon->Init();
	mbPokemon = false;

	mBag = new Bag;
	mBag->Init();
	mbBag = false;

	mMenuCnt = 0;

	//mbMenu = false;

	return S_OK;
}

void MenuManager::Update()
{

	

	if (mbMenuCon == true)
	{
		if (Input::GetButtonDown(VK_DOWN))
		{
			++mMenuCnt;
		}
		if (Input::GetButtonDown(VK_UP))
		{
			--mMenuCnt;
		}

		if (mMenuCnt <= 0)
		{
			mMenuCnt = 0;
		}
		if (mMenuCnt >= 6)
		{
			mMenuCnt = 6;
		}

		
	}
	

	if (Input::GetButtonDown('Z'))
	{
		mbMenuCon = false;

		switch (mMenuCnt)
		{
		case 0:
			mbDogam = true;
			break;
		case 1:
			mbPokemon = true;
			break;
		case 2:
			mbBag = true;
			break;
		default:
			break;
		}
	}

	if (mbMenuCon == false && mbDogam == true)
	{
		mDogam->Update();
	}
	if (mbMenuCon == false && mbPokemon == true)
	{
		mPokemon->Update();
	}
	if (mbMenuCon == false && mbBag == true)
	{
		mBag->Update();
	}
	
	if (Input::GetButtonDown('X'))
	{
		mbMenuCon = true;
		mbDogam = false;
		mbPokemon = false;
		mbGear = false;
	}
	if (mBag->mBagCnt == 3 && mbBag == true)
	{
		if (Input::GetButtonDown('Z'))
		{
			mbMenuCon = true;
			mBag->mBagCnt = 0;
			mbBag = false;
		}
	}

}

void MenuManager::Render(HDC hdc)
{
	if (mMenuCnt == 0)
	{
		mMenuDogam->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (mbDogam == true)
		{
			mDogam->Render(hdc);
		}
	}
	if (mMenuCnt == 1)
	{
		mMenuPoke->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (mbPokemon == true)
		{
			mPokemon->Render(hdc);
		}
	}
	if (mMenuCnt == 2)
	{
		mMenuBag->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (mbBag == true)
		{
			mBag->Render(hdc);
		}
	}
	if (mMenuCnt == 3)
	{
		mMenuGear->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
	}
	if (mMenuCnt == 4)
	{
		mMenuPlayer->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
	}
	if (mMenuCnt == 5)
	{
		mMenuSetting->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
	}
	if (mMenuCnt == 6)
	{
		mMenuClose->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
	}

}

void MenuManager::Release()
{
	SAFE_RELEASE(mDogam);
	SAFE_RELEASE(mPokemon);
	SAFE_RELEASE(mBag);
}
