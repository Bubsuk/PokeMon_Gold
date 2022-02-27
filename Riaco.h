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

		mTypeIndexX = 14;
		mTypeIndexY = 0;

		mName = "리아코";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(87) == true) mGender = Gender::Male;
		else mGender = Gender::Female;

		mPokeSpecies = ePokemon::Riaco;
		mPokeType = ePokemonType::Etc;

		PokemonSkill* mSkill1 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill1);
		mSkill1->mSkillName = "할퀴기";
		mSkill1->mAttack = 25;
		mSkill1->mAccuracyRate = 100;
		mSkill1->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);
		mSkill1->mSkillFrameX = 8;

		PokemonSkill* mSkill2 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill2);
		mSkill2->mSkillName = "째려보기";
		mSkill2->eType = SkillType::Normal;
		mSkill2->mAttack = 0;
		mSkill2->mAccuracyRate = 100;
		mSkill2->mSkillImg = IMG_MGR->FindImage(eImageTag::WildConfusion);
		mSkill2->mSkillFrameX = 10;

		mLv = 1;
		mIdNum = "No. 158";
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
	~Riaco()
	{

	}
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

