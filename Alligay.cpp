#include "stdafx.h"
#include "Alligay.h"


HRESULT Alligay::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Alligay_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Alligay_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "엘리게이";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;


	mPokeType = ePokemonType::Etc;


	mPokeSkill.
	mPokeSkill.push_back(mSkill);
	mPokeSkill[0].SkillName = "할퀴기";
	mPokeSkill[0].Attack = 40;
	mPokeSkill[0].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[1].SkillName = "째려보기"; 
	mPokeSkill[1].Attack = 0;
	mPokeSkill[1].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[2].SkillName = "분노";
	mPokeSkill[2].Attack = 20;
	mPokeSkill[2].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[3].SkillName = "물대포";
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
