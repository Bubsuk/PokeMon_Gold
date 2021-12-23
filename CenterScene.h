#pragma once
#include "GameEntity.h"

class Jiwoo;
class CenterScene : public GameEntity
{
public:
	Jiwoo* mJiwoo;
	
public:

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};
