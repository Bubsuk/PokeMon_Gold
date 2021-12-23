#pragma once
#include "Pokemon.h"

class GgoRat : public Pokemon
{
public:

	GgoRat()
	{
		mBackImg = IMG_MGR->FindImage(eImageTag::Ggorat_R);
		mFrontImg = IMG_MGR->FindImage(eImageTag::Ggorat_F);
		mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);


		mName = "����";
		strcpy_s(chName, mName.c_str());

		if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
		else mGender = Gender::Female;


		mPokeType = ePokemonType::Etc;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[0].SkillName = "�����ġ��";
		mPokeSkill[0].Attack = 35;
		mPokeSkill[0].AccuracyRate = 95;

		mPokeSkill.push_back(mSkill);
		mPokeSkill[1].SkillName = "��������";
		mPokeSkill[1].Attack = 0;
		mPokeSkill[1].AccuracyRate = 100;

		mLv = 1;
		mIdNum = "No. 019";
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

