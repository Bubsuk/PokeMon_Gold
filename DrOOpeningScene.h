#pragma once
#include "GameEntity.h"

class Image;
class DrOOpeningScene : public GameEntity
{
private:
	Image* mBackground;
	Image* mDialogue;
	Image* mOBaksa;
	Image* mPageCursor;

	float mElapsedCnt;
	bool mBlinkCursor = {};

	int mScriptCnt;

	char mText[100];

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

};

