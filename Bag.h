#pragma once
#include "GameEntity.h"

class Image;
class Bag : public GameEntity
{
public:
	Image* mBag1;
	Image* mBag2;
	Image* mBag3;
	Image* mBag4;

	int mBagCnt;

	bool mbControl;

	char mSampleText[256];
	

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

