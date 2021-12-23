#include "stdafx.h"
#include "Caterpie.h"

HRESULT Caterpie::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Caterpie_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Caterpie_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "ĳ����";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;

	
	mPokeType = ePokemonType::Bug;

	mPokeSkill.push_back(mSkill);
	mCaterSkill[0].SkillName = "�����ġ��";
	mCaterSkill[0].Attack = 35;
	mCaterSkill[0].AccuracyRate = 95;

	mPokeSkill.push_back(mSkill);
	mCaterSkill[1].SkillName = "�ǻձ�"; // �Կ��� �վ ���� �ְ��Ƽ� ����� ���ǵ带 ����߸���.
	mCaterSkill[1].Attack = 0;
	mCaterSkill[1].AccuracyRate = 95;

	mLv = 1;
	mIdNum = "No. 010";
	mMaxHp = 40;
	mHp = mMaxHp;

	mMaxExp = 40;
	mExp = 0;


	return S_OK;
}

void Caterpie::Update()
{
	
	if (Input::GetButtonDown('Z'))
	{
		mWeight = RandomManager::WeightMaker();
		mMaxHp = mWeight * mMaxHp;
		cout << "ü���� " << mMaxHp << "�� " << mName << "�� �����Ǿ����ϴ�." << endl;
		mMaxHp = 40;
		cout << "���ϸ� ������ " << (int)mGender << "�Դϴ�." << endl;
		cout << "��ų���� " << mPokeSkill[0].SkillName << endl;

		cout << RandomManager::WeightMaker() << endl;;
	}

}

void Caterpie::Render(HDC hdc)
{
	mBackImg->Render(hdc, 40, 40);
	mFrontImg->Render(hdc, 40, 240);
}

void Caterpie::Release()
{

}


