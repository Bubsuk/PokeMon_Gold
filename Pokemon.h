#pragma once
#include "GameEntity.h"
#include "Image.h"
#include "RandomManager.h"
#include "PokemonManager.h"


struct PokemonSkill
{
	string SkillName = "default";
	SkillType Type;
	
	// 필수 구현
	int Attack = {};
	int AccuracyRate = {};
	// 구현 고민 중
	int Shield = {};
	int SpecialAtt = {};
	int SpecialShield = {};
	int Speed = {};
};


class Image;
class Pokemon : public PokemonManager
{

protected:
	Image* mBackImg;
	Image* mFrontImg;
	Image* mTypeImg;

	string mName;
	Gender mGender;
	ePokemonType mPokeType;

	vector<PokemonSkill> mPokeSkill;
	PokemonSkill mSkill;


	

	int mLv = {};
	string mIdNum = "No. 0";
	int mHp = {};
	int mMaxHp = {};
	int mExp = {};
	int mMaxExp = {};

public:
	virtual HRESULT Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	virtual void SetHp(int hp) { this->mHp = hp; }

	virtual ~Pokemon() {};

};