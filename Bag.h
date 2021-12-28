#pragma once
#include "BattleManager.h"
#include "MenuManager.h"

class Image;
class Bag : public BattleManager, MenuManager
{
public:
	Image* mBag1;
	Image* mBag2;
	Image* mBag3;
	Image* mBag4;

	int mBagCnt;
	int mProgressCnt;

	bool mbControl;
	bool mbBag;
	bool mbMonsterball;



	char mSampleText[256];
	

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

