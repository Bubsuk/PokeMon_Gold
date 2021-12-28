#pragma once
#include "MenuManager.h"

class Image;
class Dogam : public MenuManager
{
public:
	Image* mDogamMain;
	Image* mDogamSelect;

	POINT mSelectPos;

	int mSelectCnt;

	char mSampleText[256];
	string str;

	bool mbDogam;
	
public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

