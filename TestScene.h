#pragma once
#include "GameEntity.h"

class IngameMap;
class Pokemon;
class Jiwoo;
class Image;
class TestScene : public GameEntity
{
private:
	Image* mMonsterball;
	Image* mMonsterGoalIn;

	int mGoalInFrameX;

	float mElapsedCnt;


	int mMonsterballPosX;
	int mMonsterballPosY;
	float mBallSpeed;
	float mGravity;
	int mHeightLimit;


public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	
};