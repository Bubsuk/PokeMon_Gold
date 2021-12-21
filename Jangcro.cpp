#include "stdafx.h"
#include "Jangcro.h"

HRESULT Jangcro::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Caterpie_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Caterpie_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "ĳ����";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;


	mPokeType = ePokemonType::Bug;

	mPokeSkill.reserve(4);

	mPokeSkill[0].SkillName = "�����ġ��";
	mPokeSkill[0].Attack = 35;
	mPokeSkill[0].AccuracyRate = 95;

	mPokeSkill[1].SkillName = "�ǻձ�"; // �Կ��� �վ ���� �ְ��Ƽ� ����� ���ǵ带 ����߸���.
	mPokeSkill[1].Attack = 0;
	mPokeSkill[1].AccuracyRate = 95;

	mLv = 1;
	mIdNum = "No. 010";
	mMaxHp = 40;
	mHp = mMaxHp;

	mMaxExp = 40;
	mExp = 0;


	return S_OK;
}

void Jangcro::Update()
{
}

void Jangcro::Render(HDC hdc)
{
}

void Jangcro::Release()
{
}
