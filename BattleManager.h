#pragma once
#include "GameEntity.h"

class MonsterAppear;
class CatchPokemon;
class MenuPokemon;
class Bag;
class Fight;
class Image;
class BattleManager
{
protected:

	// �����̹���
	Image* mPlayerImg; // ���� �̹���
	Image* mAppearMon;
	Image* mPokeballState;

	// ��Ʋ ������
	Image* mBattleBackground;
	Image* mBattleSkill;
	Image* mDialogue;
	Image* mCursor;
	Image* mHpGauge;
	Image* mExpGauge;
	Image* mGender;

	// ������� ���ͺ�

	MonsterAppear* mAppear;
	Fight* mFightScene;
	Bag* mBag;
	MenuPokemon* mMenuPoke;
	CatchPokemon* mCatchScene;

	char mText[256];

	int mCursorCnt;
	POINT mCursorPos;

	
	bool mbBasicFrame;
	
	//bool mbMenu;
	//bool mbBag;

	float mElasedCnt;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void BattleFrameRender(HDC hdc);
};

