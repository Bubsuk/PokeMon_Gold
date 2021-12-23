#pragma once
#include "GameEntity.h"
#include "Image.h"
#include "RandomManager.h"
#include "Singleton.h"


struct PokemonSkill
{
	string SkillName = "default";
	SkillType Type;
	Image* SkillImg;
	
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
	Image* mBackImg;
	Image* mFrontImg;
	Image* mTypeImg;

	string mName;
	char chName[256];
	Gender mGender;
	ePokemonType mPokeType;

	vector<PokemonSkill> mPokeSkill;
	PokemonSkill mSkill;

	
	

	int mLv = {};
	string mIdNum = "No. 0";
	char chIdNum[256];

	int mHp = {};
	int mMaxHp = {};
	int mExp = {};
	int mMaxExp = {};

public:
	virtual HRESULT Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;


	
	virtual ~Pokemon() {};

};