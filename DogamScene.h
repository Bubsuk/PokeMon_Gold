#pragma once
#include "GameEntity.h"

class Image;
class DogamScene : public GameEntity
{
public:
	Image* mDogamMain;
	
public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

