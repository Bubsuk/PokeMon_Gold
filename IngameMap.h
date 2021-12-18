#pragma once
#include "GameEntity.h"
#include "MapEditor.h"

class Jiwoo;
class Image;
class IngameMap : public GameEntity
{
public:

protected:
	Jiwoo* mTestJiwoo;

	Image* mDrawTileImage;
	Image* mBackground;

	RECT mSampleArea;
	RECT mDrawArea;

	TILE_INFO mTileInfo[TILE_COUNT_X * TILE_COUNT_Y];
	SAMPLE_TILE_INFO mSampleTileInfo[SAMPLE_TILE_COUNT_X * SAMPLE_TILE_COUNT_Y];
	SAMPLE_TILE_INFO mSelectedTile;

	eDir mDir;

	bool mbControl = {};
	bool mbIsClick = {};
	bool mbNeedRevise = {};

	float mRivisedDurTime = {};
	float mOneTileTime = {};

	int mMoveSpeed;
	// ������ ���� Ÿ�� ��ǥ��ǥ
	POINT mDestPos;
	// ī�޶�
	POINT mMovePixel;
	// �巡�׷� Ÿ�� ����
	POINT mClickStart;
	POINT mCLickEnd;
	// �巡�� ���ð��� ���밪
	POINT mClickArea;
	// ����Ÿ�Ͽ��� ���õ� Ÿ���� ��ǥ��
	POINT mClickIndex;


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

