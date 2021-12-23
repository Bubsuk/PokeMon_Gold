#include "stdafx.h"
#include "PikaChu.h"

HRESULT PikaChu::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Pika_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Pika_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mName = "��ī��";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;


	mPokeType = ePokemonType::Bug;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[0].SkillName = "�����ġ��";
	mPokeSkill[0].Attack = 35;
	mPokeSkill[0].AccuracyRate = 95;

	mPokeSkill.push_back(mSkill);
	mPokeSkill[1].SkillName = "�ǻձ�"; // �Կ��� �վ ���� �ְ��Ƽ� ����� ���ǵ带 ����߸���.
	mPokeSkill[1].Attack = 0;
	mPokeSkill[1].AccuracyRate = 95;

	mLv = 1;
	mIdNum = "No. 025";
	mMaxHp = 40;
	mHp = mMaxHp;

	mMaxExp = 40;
	mExp = 0;


	return S_OK;
}

void PikaChu::Update()
{
}

void PikaChu::Render(HDC hdc)
{
}

void PikaChu::Release()
{
}
