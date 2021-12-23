#pragma once
#include "Pokemon.h"

class Bcane : public Pokemon
{
public:
	Bcane()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Bcane_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Bcane_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

		mName = "브케인";

		strcpy_s(chName, mName.c_str());
		if (RandomManager::PercentMaker(87) == true) mGender = Gender::Male;
		else mGender = Gender::Female;


		mPokeType = ePokemonType::Etc;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[0].SkillName = "몸통박치기";
		mPokeSkill[0].Attack = 35;
		mPokeSkill[0].AccuracyRate = 95;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[1].SkillName = "째려보기";
		mPokeSkill[1].Attack = 0;
		mPokeSkill[1].AccuracyRate = 100;

		mLv = 1;
		mIdNum = "No. 155";
		mMaxHp = 40 * RandomManager::WeightMaker();
		mHp = mMaxHp;

		mMaxExp = 40 * RandomManager::WeightMaker();
		mExp = 0;
	}

	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

};

