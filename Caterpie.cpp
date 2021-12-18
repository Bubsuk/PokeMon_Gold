#include "stdafx.h"
#include "Caterpie.h"
#include "Image.h"
#include "RandomManager.h"

HRESULT Caterpie::Init()
{
	mBackImg = IMG_MGR->FindImage(eImageTag::Caterpie_R);
	mFrontImg = IMG_MGR->FindImage(eImageTag::Caterpie_F);
	mTypeImg = IMG_MGR->FindImage(eImageTag::PokeIcon);

	mWeight = 1;

	mName = "캐터피";

	if (RandomManager::PercentMaker(50) == true) mGender = Gender::Male;
	else mGender = Gender::Female;

	
	mPokeType = ePokemonType::Bug;
	mSkill_1.SkillName = "몸통박치기";
	mSkill_1.Attack = 35;
	mSkill_1.AccuracyRate = 95;

	mSkill_2.SkillName = "실뿜기"; // 입에서 뿜어낸 실을 휘감아서 상대의 스피드를 떨어뜨린다.
	mSkill_2.Attack = 0;
	mSkill_2.AccuracyRate = 95;

	mLv = 1;
	mIdNum = "No. 010";
	mMaxHp = 40;
	mHp = mMaxHp;

	mMaxExp = 40;
	mExp = 0;


	return E_NOTIMPL;
}

void Caterpie::Update()
{
	
	if (Input::GetButtonDown('Z'))
	{
		mWeight = RandomManager::WeightMaker();
		mMaxHp = mWeight * mMaxHp;
		cout << "체력이 " << mMaxHp << "인 " << mName << "이 생성되었습니다." << endl;
		mMaxHp = 40;
		cout << "포켓몬 성별은 " << (int)mGender << "입니다." << endl;
		cout << "스킬명은 " << mSkill_1.SkillName << endl;

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


