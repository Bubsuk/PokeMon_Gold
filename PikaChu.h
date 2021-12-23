#pragma once
#include "Pokemon.h"

class PikaChu : public Pokemon
{
public:
	PikaChu()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Pika_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Pika_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

		mName = "피카츄";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
		else mGender = Gender::Female;


		mPokeType = ePokemonType::Pika;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[0].SkillName = "전기쇼크";
		mPokeSkill[0].Attack = 40;
		mPokeSkill[0].AccuracyRate = 100;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[1].SkillName = "울음소리";
		mPokeSkill[1].Attack = 0;
		mPokeSkill[1].AccuracyRate = 100;

		mLv = 1;
		mIdNum = "No. 025";
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

