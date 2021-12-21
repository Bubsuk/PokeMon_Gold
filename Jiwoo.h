#pragma once
#include "GameObject.h"

class Collider;
class Jiwoo : public GameObject
{
private:
	Image* mImageRunRL = nullptr;
	Image* mImageRunUD = nullptr;

	Collider* mCollider;

	eDir mState;

	int mframeX = 0;
	int mframeY = 0;

	bool mAnimPlay;
	bool mbControl = {};
	bool mbNeedRevise = {};

	const float mFlipAnimTime = 0.15f;
	float mElapsedCount = 0.0f;
	float mMoveSpeed = {};
	float mOneTileTime = {};

	POINT mDestPos;


public:
	virtual ~Jiwoo() {}
	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

};

