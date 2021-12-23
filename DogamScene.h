#pragma once
#include "GameEntity.h"

class Image;
class DogamScene : public GameEntity
{
public:
	Image* mDogamMain;
	Image* mDogamSelect;

	POINT mSelectPos;

	int mSelectCnt;
	
public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

