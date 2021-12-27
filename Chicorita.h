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

		mTypeIndexX = 30;
		mTypeIndexY = 0;

		mName = "ġ�ڸ�Ÿ";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(87) == true) mGender = Gender::Male;
		else mGender = Gender::Female;

		mPokeSpecies = ePokemon::Chicorita;
		mPokeType = ePokemonType::Etc;

		PokemonSkill* mSkill1 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill1);
		mSkill1->mSkillName = "�����ġ��";
		mSkill1->eType = SkillType::Normal;
		mSkill1->mAttack = 30;
		mSkill1->mAccuracyRate = 95;
		mSkill1->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);

		PokemonSkill* mSkill2 = new PokemonSkill;
		mPokeSkill.emplace_back(mSkill2);
		mSkill2->mSkillName = "�����Ҹ�";
		mSkill2->eType = SkillType::Normal;
		mSkill2->mAttack = 0;
		mSkill2->mAccuracyRate = 100;
		mSkill2->mSkillImg = IMG_MGR->FindImage(eImageTag::Slash);

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

