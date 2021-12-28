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

	mDogam = new Dogam;
	mDogam->Init();
	
	mPokeMenu = new MenuPokemon;
	mPokeMenu->Init();
	
	mBag = new Bag;
	mBag->Init();

	mMenuCnt = 0;

	return S_OK;
}

void MenuManager::Update()
{

	if ((mDogam->mbDogam == false) && (mPokeMenu->mbMenu == false) && (mBag->mbBag == false))
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

		switch (mMenuCnt)
		{
		case 0:
			mDogam->mbDogam = true;
			break;
		case 1:
			mPokeMenu->mbMenu = true;
			break;
		case 2:
			mBag->mbBag = true;
			break;
		default:
			break;
		}
	}

	if (mDogam->mbDogam == true)
	{
		mDogam->Update();
	}
	if (mPokeMenu->mbMenu == true)
	{
		mPokeMenu->Update();
	}
	if (mBag->mbBag == true)
	{
		mBag->Update();
	}

}

void MenuManager::Render(HDC hdc)
{
	if (mMenuCnt == 0)
	{
		mMenuDogam->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (mDogam->mbDogam == true)
		{
			mDogam->Render(hdc);
		}
	}
	if (mMenuCnt == 1)
	{
		mMenuPoke->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (mPokeMenu->mbMenu == true)
		{
			mPokeMenu->Render(hdc);
		}
	}
	if (mMenuCnt == 2)
	{
		mMenuBag->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (mBag->mbBag == true)
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
	SAFE_RELEASE(mPokeMenu);
	SAFE_RELEASE(mBag);
}
