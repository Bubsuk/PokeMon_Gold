#pragma once
#include "Pokemon.h"
#include "PokemonSkill.h"


class Bcane : public Pokemon, PokemonSkill
{
public:
	Bcane()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Bcane_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Bcane_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

		mTypeIndexX = 14;
		mTypeIndexY = 0;

		mName = "브케인";

		strcpy_s(chName, mName.c_str());
		if (RandomManager::PercentMaker(87) == true) mGender = Gender::Male;
		else mGender = Gender::Female;

		mPokeSpecies = ePokemon::Bcane;
		mPokeType = ePokemonType::Etc;

		PokemonSkill* mSkill1 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill1);
		mSkill1->mSkillName = "몸통박치기";
		mSkill1->eType = SkillType::Normal;
		mSkill1->mAttack = 30;
		mSkill1->mAccuracyRate = 95;
		mSkill1->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);
		mSkill1->mSkillFrameX = 8;

		PokemonSkill* mSkill2 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill2);
		mSkill2->mSkillName = "째려보기";
		mSkill2->eType = SkillType::Normal;
		mSkill2->mAttack = 0;
		mSkill2->mAccuracyRate = 100;
		mSkill2->mSkillImg = IMG_MGR->FindImage(eImageTag::MyConfusion);
		mSkill2->mSkillFrameX = 8;

		mLv = 1;
		mIdNum = "No. 155";
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
	~Bcane()
	{
		
	}
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

};

