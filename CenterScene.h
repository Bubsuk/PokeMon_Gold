#pragma once
#include "GameEntity.h"

class CenterScene : public GameEntity
{
public:
	
public:

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};
