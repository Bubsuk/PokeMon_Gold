#pragma once
#include "Pokemon.h"
#include "PokemonSkill.h"

class Caterpie : public Pokemon, PokemonSkill
{

public:
	Caterpie()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Caterpie_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Caterpie_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

		mTypeIndexX = 14;
		mTypeIndexY = 1;

		mName = "캐터피";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
		else mGender = Gender::Female;

		mPokeSpecies = ePokemon::Caterpie;
		mPokeType = ePokemonType::Bug;

		PokemonSkill* mSkill1 = new PokemonSkill;
		mSkill1->mSkillName = "몸통박치기";
		mSkill1->eType = SkillType::Normal;
		mSkill1->mAttack = 30;
		mSkill1->mAccuracyRate = 95;
		mSkill1->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);
		mPokeSkill.emplace_back(mSkill1);

		PokemonSkill* mSkill2 = new PokemonSkill;
		mSkill2->mSkillName = "실뿜기"; // 입에서 뿜어낸 실을 휘감아서 상대의 스피드를 떨어뜨린다.
		mSkill2->eType = SkillType::Bug;
		mSkill2->mAttack = 0;
		mSkill2->mAccuracyRate = 95;
		mSkill2->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);
		mPokeSkill.emplace_back(mSkill2);
		

		

		mLv = 1;
		mIdNum = "No. 010";
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

