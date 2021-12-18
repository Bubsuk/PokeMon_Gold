#pragma once
#include "GameEntity.h"

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
public:
	virtual ~Pokemon() {};

	virtual HRESULT Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;
	
protected:
	Image* mBackImg;
	Image* mFrontImg;
	Image* mTypeImg;

	string mName;
	Gender mGender;
	ePokemonType mPokeType;
	PokemonSkill mSkill_1;
	PokemonSkill mSkill_2;
	PokemonSkill mSkill_3;
	PokemonSkill mSkill_4;

	vector<Item> mItem;

	int mLv = {};
	string mIdNum = "No. 0";
	int mHp = {};
	int mMaxHp = {};
	int mExp = {};
	int mMaxExp = {};
	// 체력 랜덤설정을 위한 가중치
	float mWeight;

};