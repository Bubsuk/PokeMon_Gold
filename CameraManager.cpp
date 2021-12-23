#include "stdafx.h"
#include "CameraManager.h"
#include <cmath>

POINT CameraManager::GetCamPos()
{
	return mObjectPos;
}

// 보간 적용
void CameraManager::MovePos(POINT& destPos, float durTime, eDir dir)
{

	mStartPos = mObjectPos;

	switch (dir)
	{
	case eDir::Right:
		mElapsedTime += DELTA_TIME;
		if (mObjectPos.x >= -TILE_SIZE * TILE_COUNT_X)
		{
			mObjectPos.x = mStartPos.x - fabs(destPos.x - mStartPos.x) * mElapsedTime / durTime;
		}

		
		if (mElapsedTime >= durTime)
		{
			mObjectPos.x = destPos.x;
			mElapsedTime = 0.0f;
		}
	
		break;
	case eDir::Left:
		mElapsedTime += DELTA_TIME;
		if (mObjectPos.x <= 0)
		{
			mObjectPos.x = mStartPos.x + fabs(destPos.x - mStartPos.x) * mElapsedTime / durTime;
		}

		if (mElapsedTime >= durTime)
		{
			mObjectPos.x = destPos.x;
			mElapsedTime = 0.0f;
		}

		
		break;
	case eDir::Up:
		mElapsedTime += DELTA_TIME;
		if (mObjectPos.y <= 0)
		{
			mObjectPos.y = mStartPos.y + fabs(destPos.y - mStartPos.y) * mElapsedTime / durTime;
			
		}

		if (mElapsedTime >= durTime)
		{
			mObjectPos.y = destPos.y;
			mElapsedTime = 0.0f;
		}
		
		break;
	case eDir::Down:
		mElapsedTime += DELTA_TIME;
		if (mObjectPos.y >= -TILE_SIZE * TILE_COUNT_Y)
		{
			mObjectPos.y = mStartPos.y - fabs(destPos.y - mStartPos.y) * mElapsedTime / durTime;

		}

		if (mElapsedTime >= durTime)
		{
			mObjectPos.y = destPos.y;
			mElapsedTime = 0.0f;
		}
		
		break;
	}
	
}

void CameraManager::SetPos(int x, int y)
{
	mObjectPos.x = x;
	mObjectPos.y = y;
}

void CameraManager::SetWarfPos(POINT warfPos)
{
	mWarfPos.x = warfPos.x;
	mWarfPos.y = warfPos.y;
}

POINT CameraManager::GetWarfPos()
{
	return mWarfPos;
}
