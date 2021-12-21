#pragma once
#include "GameEntity.h"
#include "Image.h"
#include "RandomManager.h"


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
class Pokemon
{

protected:
	Image* mBackImg;
	Image* mFrontImg;
	Image* mTypeImg;

	string mName;
	Gender mGender;
	ePokemonType mPokeType;
	vector<PokemonSkill> mPokeSkill;

	vector<Item> mItem;

	int mLv = {};
	string mIdNum = "No. 0";
	int mHp = {};
	int mMaxHp = {};
	int mExp = {};
	int mMaxExp = {};
	// 체력 랜덤설정을 위한 가중치
	float mWeight;

public:
	virtual HRESULT Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	virtual void SetHp(int hp) { this->mHp = hp; }

	virtual ~Pokemon() {};

};