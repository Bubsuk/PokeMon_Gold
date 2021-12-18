#pragma once
#include "GameObject.h"

class Jiwoo : public GameObject
{
private:
	Image* mImageRunRL = nullptr;
	Image* mImageRunUD = nullptr;

	eDir mState;

	int mframeX = 0;
	int mframeY = 0;

	bool mAnimPlay;
	const float mFlipAnimTime = 0.15f;
	float mElapsedCount = 0.0f;

public:
	virtual ~Jiwoo() {}
	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

};

