#pragma once
#include "GameEntity.h"

class Jiwoo;
class Home2ndScene : public GameEntity
{
public:
	Jiwoo* mJiwoo;
	POINT mTo1stFloor;

public:

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();


};