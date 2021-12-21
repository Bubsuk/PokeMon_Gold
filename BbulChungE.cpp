#include "stdafx.h"
#include "BbulChungE.h"

HRESULT BbulChungE::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Caterpie_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Caterpie_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "캐터피";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;


	mPokeType = ePokemonType::Bug;

	mPokeSkill.reserve(4);

	mPokeSkill[0].SkillName = "독침";
	mPokeSkill[0].Attack = 40;
	mPokeSkill[0].AccuracyRate = 100;

	mPokeSkill[1].SkillName = "실뿜기";
	mPokeSkill[1].Attack = 0;
	mPokeSkill[1].AccuracyRate = 100;


	mLv = 1;
	mIdNum = "No. 013";
	mMaxHp = 40;
	mHp = mMaxHp;

	mMaxExp = 40;
	mExp = 0;


	return S_OK;
}

void BbulChungE::Update()
{
}

void BbulChungE::Render(HDC hdc)
{
}

void BbulChungE::Release()
{
}
