#pragma once
#include "GameEntity.h"

class CityScene : public GameEntity
{
public:

	POINT mToCenter;
	POINT mToMart;
	POINT mToGym;
	POINT mToDrO;
	
public:


	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();


};

