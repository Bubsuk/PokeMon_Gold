#pragma once
#include "MapEditor.h"

class Jiwoo;
class Image;
class IngameMap : public MapEditor 
{
public:

protected:
	eDir mDir;

	bool mbControl = {};
	bool mbIsClick = {};
	bool mbNeedRevise = {};

	float mRivisedDurTime = {};
	float mOneTileTime = {};


	int mMoveSpeed;

	POINT mMovePixel;
	// ������ ���� Ÿ�� ��ǥ��ǥ
	POINT mDestPos;


	string mSaveIndex = {};
	char mSave[10] = {};
	char mSampleText[256];

public:
	virtual HRESULT Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void LoadMap(string index);
};

