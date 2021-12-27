#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "Singleton.h"

class MenuManager;
class Jiwoo : public Singleton<Jiwoo>, GameObject, Collider
{
public:
	Image* mImageRunRL = nullptr;
	Image* mImageRunUD = nullptr;
	Image* mShadow;
	Image* mDetectFlash;

	Collider* mCollider;

	eDir mState;

	MenuManager* mMenu;

	
	int mframeX = 0;
	int mframeY = 0;

	float mJumpWeight;
	int mJumpHeight;

	bool mAnimPlay;
	bool mbControl;
	bool mbNeedRevise;
	bool mbJump = {};
	bool mbDetected = {};
	bool mbCoolTime;

	const float mFlipAnimTime = 0.15f;
	float mElapsedCount;
	float mCoolTimeCnt;
	float mJumpCount = 0.0f;
	float mMoveSpeed = {};
	float mOneTileTime = {};

	POINT mDestPos;
	POINT mBarometerPos;


public:
	bool mbMenuSwitch;
	bool mbControlSwitch;


	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void Jump();

	virtual ~Jiwoo() {}
};

