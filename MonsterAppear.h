#pragma once
#include "BattleManager.h"

class Image;
class MonsterAppear : public BattleManager
{
public:
	Image* mWhiteBk;

	int mPlayerAppearX;
	int mBattlePokePosX;

	bool mbAppeared = false;
	bool mbScripted;
	bool mbParticle;

	int mAppProgCnt;

	// ���ϸ� ��Ÿ���� ȿ�� ������
	int mFrameX;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

