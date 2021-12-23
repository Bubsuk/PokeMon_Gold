#include "stdafx.h"
#include "Alligay.h"


HRESULT Alligay::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Alligay_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Alligay_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "��������";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;


	mPokeType = ePokemonType::Etc;


	mPokeSkill.
	mPokeSkill.push_back(mSkill);
	mPokeSkill[0].SkillName = "������";
	mPokeSkill[0].Attack = 40;
	mPokeSkill[0].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[1].SkillName = "°������"; 
	mPokeSkill[1].Attack = 0;
	mPokeSkill[1].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[2].SkillName = "�г�";
	mPokeSkill[2].Attack = 20;
	mPokeSkill[2].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[3].SkillName = "������";
	mPokeSkill[3].Attack = 40;
	mPokeSkill[3].AccuracyRate = 100;

	mLv = 1;
	mIdNum = "No. 160";
	mMaxHp = 70;
	mHp = mMaxHp;

	mMaxExp = 50;
	mExp = 0;


	return S_OK;
}

void Alligay::Update()
{
}

void Alligay::Render(HDC hdc)
{
}

void Alligay::Release()
{
}
