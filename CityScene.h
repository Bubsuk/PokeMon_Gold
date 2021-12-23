#pragma once
#include "GameEntity.h"

class Jiwoo;
class CityScene : public GameEntity
{
public:
	Jiwoo* mJiwoo;

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

