#pragma once
#include "GameEntity.h"

class IngameMap;
class CityScene : public GameEntity
{
public:
	
	IngameMap* mCityMap;
	
	

public:
	static POINT mCityPos;

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();


};

