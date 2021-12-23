#pragma once
#include "GameEntity.h"

class Image;
class OpeningScene : public GameEntity
{
private:
	Image* mOpImg[102];
	Image* mMainOpImg[10];
	float elapsedCnt = {};
	int cnt = {};
	bool mOpPlay;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
	
};

