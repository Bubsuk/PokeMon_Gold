#pragma once
#include "Pokemon.h"

class Riaco : public Pokemon
{
public:
	Riaco()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Riaco_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Riaco_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);


		mName = "리아코";

		if (RandomManager::PercentMaker(87) == true) mGender = Gender::Male;
		else mGender = Gender::Female;


		mPokeType = ePokemonType::Etc;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[0].SkillName = "할퀴기";
		mPokeSkill[0].Attack = 40;
		mPokeSkill[0].AccuracyRate = 100;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[1].SkillName = "째려보기";
		mPokeSkill[1].Attack = 0;
		mPokeSkill[1].AccuracyRate = 100;

		mLv = 1;
		mIdNum = "No. 158";
		mMaxHp = 40;
		mMaxHp = 40 * RandomManager::WeightMaker();

		mMaxExp = 40 * RandomManager::WeightMaker();
		mExp = 0;

	}

	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

