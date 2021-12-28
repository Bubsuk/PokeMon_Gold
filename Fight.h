#pragma once
#include "BattleManager.h"
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

class Image;
class Fight : public BattleManager
{
public:
	Image* mCursor;
	
	bool mbFight;

	int mSkillCurCnt;
	int mEnemySkillNum;
	int mProgressCnt;

	POINT mSkillCursorPos;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

