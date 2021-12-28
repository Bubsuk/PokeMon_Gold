#pragma once
#include "BattleManager.h"

class Image;
class CatchPokemon : public BattleManager
{
public:
	Image* mMonsterball;
	Image* mMonsterGoalIn;
	Image* mBlind;
	Image* mDialogue;

	int mGoalInFrameX;

	float mElapsedCnt;

	POINT mMonsterballPos;
	float mBallSpeed;
	float mBallWeight;
	int mHeightLimit;

	bool mbCatch;
	bool mbBall;
	bool mParticle;
	bool mbCatchEnd;


	char mText[256];

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

