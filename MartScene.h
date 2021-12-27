#pragma once
#include "GameEntity.h"

class Jiwoo;
class MartScene : public GameEntity
{
public:
	POINT mToCity;

public:

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

