#pragma once
#include "GameEntity.h"

class Jiwoo;
class Image;
class MenuManager : public GameEntity
{
public:
	Jiwoo* mJiwoo;

	Image* mGear1;
	Image* mGear2;
	Image* mGear3;

	int mMenuCnt;

	Image* mMenuDogam;
	Image* mMenuPoke;
	Image* mMenuBag;
	Image* mMenuGear;
	Image* mMenuPlayer;
	Image* mMenuSetting;
	Image* mMenuClose;

	Image* mSelectPoke1;
	Image* mSelectPoke2;
	Image* mSelectPoke3;
	Image* mSelectPoke4;
	Image* mSelectPoke5;
	Image* mSelectPoke6;
	Image* mSelectPokeClose;

	Image* mPower;

	Image* mSetting;
	Image* mSettingClose;

	Image* mPlayerStat1;
	Image* mPlayerStat2;

	bool mbMenu;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

