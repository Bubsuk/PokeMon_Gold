#pragma once
#include "GameEntity.h"

class Jiwoo;
class Home1stScene : public GameEntity
{
public:

	POINT mTo2ndFloor;
	POINT mToOutdoor;
	POINT mToOutdoor2;

public:

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();


};

