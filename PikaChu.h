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

		mTypeIndexX = 6;
		mTypeIndexY = 0;

		mName = "피카츄";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(50) == true)
		{
			mGender = Gender::Male;
		}
		else
		{
			mGender = Gender::Female;
		}

		mPokeSpecies = ePokemon::Pika;
		mPokeType = ePokemonType::Pika;

		PokemonSkill* mSkill1 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill1);
		mSkill1->mSkillName = "전기쇼크";
		mSkill1->mAttack = 30;
		mSkill1->mAccuracyRate = 100;
		mSkill1->mSkillImg = IMG_MGR->FindImage(eImageTag::ElectricShock);

		PokemonSkill* mSkill2 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill2);
		mSkill2->mSkillName = "울음소리";
		mSkill2->eType = SkillType::Normal;
		mSkill2->mAttack = 0;
		mSkill2->mAccuracyRate = 100;
		mSkill2->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);

		mLv = 1;
		mIdNum = "No. 025";
		strcpy_s(chIdNum, mIdNum.c_str());
		mMaxHp = 40 * RandomManager::WeightMaker();
		if (mHp >= mMaxHp)
		{
			mHp = mMaxHp;
		}
		else
		{
			mHp = mMaxHp;
		}

		mMaxExp = 40 * RandomManager::WeightMaker();
		mExp = 0;
	}

	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

