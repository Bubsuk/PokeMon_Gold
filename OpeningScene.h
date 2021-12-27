#pragma once
#include "GameEntity.h"

class Image;
class OpeningScene : public GameEntity
{
private:
	Image* mOpImg[112];
	float elapsedCnt = {};
	int cnt = {};
	bool mOpPlay;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
	
};

