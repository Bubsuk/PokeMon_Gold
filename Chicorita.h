#pragma once
#include "Pokemon.h"

class Chicorita : public Pokemon
{
public:
	Chicorita()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Chicorita_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Chicorita_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

		mName = "치코리타";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(87) == true) mGender = Gender::Male;
		else mGender = Gender::Female;


		mPokeType = ePokemonType::Etc;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[0].SkillName = "몸통박치기";
		mPokeSkill[0].Attack = 35;
		mPokeSkill[0].AccuracyRate = 95;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[1].SkillName = "울음소리";
		mPokeSkill[1].Attack = 0;
		mPokeSkill[1].AccuracyRate = 100;

		mLv = 1;
		mIdNum = "No. 152";
		strcpy_s(chIdNum, mIdNum.c_str());
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

