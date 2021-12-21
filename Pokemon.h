#pragma once
#include "GameEntity.h"
#include "Image.h"
#include "RandomManager.h"


struct PokemonSkill
{
	string SkillName = "default";
	SkillType Type;
	
	// �ʼ� ����
	int Attack = {};
	int AccuracyRate = {};
	// ���� ��� ��
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
	// ü�� ���������� ���� ����ġ
	float mWeight;

public:
	virtual HRESULT Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	virtual void SetHp(int hp) { this->mHp = hp; }

	virtual ~Pokemon() {};

};