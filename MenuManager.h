#pragma once
#include "GameEntity.h"

class Bag;
class MenuPokemon;
class Dogam;
class Image;
class MenuManager : public GameEntity
{
public:

	Dogam* mDogam;
	MenuPokemon* mPokemon;
	Bag* mBag;


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
	bool mbMenuCon;

	bool mbDogam;
	bool mbPokemon;
	bool mbBag;
	bool mbGear;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

