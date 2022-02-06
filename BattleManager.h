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

	// 시작이미지
	Image* mPlayerImg; // 지우 이미지
	Image* mAppearMon;
	Image* mPokeballState;

	// 배틀 프레임
	Image* mBattleBackground;
	Image* mBattleSkill;
	Image* mDialogue;
	Image* mCursor;
	Image* mHpGauge;
	Image* mExpGauge;
	Image* mGender;

	// 던지기용 몬스터볼

	MonsterAppear* mAppear;
	Fight* mFightScene;
	Bag* mBag;
	MenuPokemon* mMenuPoke;
	CatchPokemon* mCatchScene;

	char mText[256];

	int mCursorCnt;
	int mEffectFrameX;
	POINT mCursorPos;

	
	bool mbBasicFrame;
	bool mPlayerPokeEffect;
	bool mEnemyPokeEffect;
	
	//bool mbMenu;
	//bool mbBag;

	float mElapsedCnt;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void BattleFrameRender(HDC hdc);
};

