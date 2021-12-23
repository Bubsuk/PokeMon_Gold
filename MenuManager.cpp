#include "stdafx.h"
#include "MenuManager.h"
#include "Image.h"
#include "Jiwoo.h"

HRESULT MenuManager::Init()
{
	mMenuDogam = IMG_MGR->FindImage(eImageTag::MenuDogam);// 시작화면
	mMenuPoke = IMG_MGR->FindImage(eImageTag::MenuPoke);
	mMenuBag = IMG_MGR->FindImage(eImageTag::MenuBag);
	mMenuGear = IMG_MGR->FindImage(eImageTag::MenuGear);
	mMenuPlayer = IMG_MGR->FindImage(eImageTag::MenuPlayer);
	mMenuSetting = IMG_MGR->FindImage(eImageTag::MenuSet);
	mMenuClose = IMG_MGR->FindImage(eImageTag::MenuClose);

	mMenuCnt = 0;

	//mbMenu = false;

	return S_OK;
}

void MenuManager::Update()
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

void MenuManager::Render(HDC hdc)
{
	switch (mMenuCnt)
	{
	case 0:
		mMenuDogam->Render(hdc, WIN_SIZE_X/2+192, WIN_SIZE_Y - WIN_SIZE_Y /2);
	/*	if (Input::GetButtonDown(VK_RETURN))
		{
			
		}*/
		break;
	case 1:
		mMenuPoke->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		break;
	case 2:
		mMenuBag->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		break;
	case 3:
		mMenuGear->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		break;
	case 4:
		mMenuPlayer->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		break;
	case 5:
		mMenuSetting->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		break;
	case 6:
		mMenuClose->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		if (Input::GetButtonDown(VK_RETURN))
		{
			CON_MGR->mbMenuSwitch = false;
			CON_MGR->mbControlSwitch = true;
		}
		break;
	default:
		mMenuDogam->Render(hdc, WIN_SIZE_X / 2 + 192, WIN_SIZE_Y - WIN_SIZE_Y / 2);
		break;
	}
}

void MenuManager::Release()
{
}
