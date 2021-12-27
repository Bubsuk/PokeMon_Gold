#pragma once
#include "GameEntity.h"
#include "MenuManager.h"
#include "PokemonManager.h"

class Attack
{
public:
	explicit Attack(int attackPoint) : enemyHp{ POKE_MGR->mTempPokemon->mHp } {}
	int operator() (int point) const
	{
		
		return enemyHp - point;
	}

private:
	int enemyHp;
};

class Attacked
{
public:
	explicit Attacked(Pokemon* enemy, int skillNum) : playerHp{ POKE_MGR->mJiwooPokemon[0]->mHp } {}
	int operator() (Pokemon* curEnemy, int skillNum) const
	{
		return playerHp - (curEnemy->mPokeSkill[skillNum]->mAttack);
	}

private:
	int playerHp;
};

class Bag;
class Image;
class BattleScene : public GameEntity, MenuManager
{
private:
	Bag* mBag;

	// 배틀 프레임
	Image* mBattleBackground;
	Image* mBattleSkill;
	Image* mDialogue;

	Image* mCursor;
	POINT mCursorPos;
	POINT mSkillCursorPos;
	int mCursorCnt;
	int mSkillCurCnt;

	Image* mHpGauge;

	Image* mExpGauge;
	//Image* mExpBackground;

	Image* mGender;

	Image* mPlayerImg; // 지우 이미지

	Image* mAppearMon;
	Image* mPokeballState;

	Image* mMonsterball;

	POINT mBallPos;

	bool mbScripted;
	bool mbBattleFrame;
	bool mbAppeared;
	bool mbJiwooOut;
	bool mbParticle;
	bool mbSkillWindow;
	bool mbPokemon;
	bool mbBag;
	bool mbAttak[4];
	

	int mBattlePokePosX;
	int mPlayerAppearX;
	int mScriptCnt;
	int mProgressCnt;
	int mFrameX;
	int mEnemySkillNum;

	float mElasedCnt;


	char mText[100];

	vector<POINT> mMonsterballPos;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void Appear(HDC hdc);
	void BattleFrame(HDC hdc);
	void PlayerAttack (HDC hdc);
	//void PlayerMonster(HDC hdc);
	//void PlayerBag(HDC hdc);
	void EnemyAttack(HDC hdc);
	void UseMonsterBall(HDC hdc);

	POINT DrawMonsterballLine(int curTime);



};

