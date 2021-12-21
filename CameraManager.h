#pragma once
#include "Config.h"
#include "Singleton.h"

class CameraManager : public Singleton<CameraManager>
{
public:
	POINT mObjectPos;
private:
	POINT mMaxPos = {};
	// �������� �̵��Ÿ�
	POINT mStartPos;
	POINT mDestPos;
	// ���� �ð���
	float mRivisedDurTimeX = {};
	float mRivisedDurTimeY = {};
	float mElapsedTime = {};

public:	
	// ��ü ������Ʈ�� ��ġ�̵����� ī�޶�ȿ��
	POINT GetCamPos();

	void MovePos(POINT& destPos, float durTime, eDir dir);

	// ����
	void SetPos(int x, int y);

};

