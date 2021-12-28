#pragma once
#include "MenuManager.h"

class Image;
class MenuPokemon : public MenuManager
{
public:
	Image* mFrame1;
	Image* mFrame2;
	Image* mFrame3;
	Image* mFrame4;
	Image* mFrame5;
	Image* mFrameCls;

	Image* mPokeIcon;

	Image* mPokePower;

	Image* mHpFrame;
	Image* mHpGauge;

	int mPokeCnt;

	int mIconPosY;

	bool mbMenu;
	bool mbPowerWindow;

	char mSampleText[256];
	
public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

