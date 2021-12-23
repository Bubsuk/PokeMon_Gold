#include "stdafx.h"
#include "Bayleaf.h"

HRESULT Bayleaf::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Caterpie_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Caterpie_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "ĳ����";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;


	mPokeType = ePokemonType::Etc;

	
	mPokeSkill.push_back(mSkill);
	mPokeSkill[0].SkillName = "�����ġ��";
	mPokeSkill[0].Attack = 35;
	mPokeSkill[0].AccuracyRate = 95;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[1].SkillName = "�����Ҹ�";
	mPokeSkill[1].Attack = 0;
	mPokeSkill[1].AccuracyRate = 100;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[2].SkillName = "�ٳ�������";
	mPokeSkill[2].Attack = 55;
	mPokeSkill[2].AccuracyRate = 95;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[3].SkillName = "���÷���";
	mPokeSkill[3].Attack = 0;
	mPokeSkill[3].AccuracyRate = 0;

	mLv = 1;
	mIdNum = "No. 153";
	mMaxHp = 70;
	mHp = mMaxHp;

	mMaxExp = 40;
	mExp = 0;


	return S_OK;
}

void Bayleaf::Update()
{
}

void Bayleaf::Render(HDC hdc)
{
}

void Bayleaf::Release()
{
}
