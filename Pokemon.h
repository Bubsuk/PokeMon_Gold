#pragma once
#include "GameEntity.h"
#include "Image.h"
#include "RandomManager.h"
#include "Singleton.h"
#include "PokemonSkill.h"

class Image;
class Pokemon
{
public:
	Image* mBackImg;
	Image* mFrontImg;
	Image* mTypeImg;

	int mTypeIndexX;
	int mTypeIndexY;
	
	string mName;
	char chName[256];
	Gender mGender;
	ePokemon mPokeSpecies;
	ePokemonType mPokeType;

	PokemonSkill* mSkill;
	vector<PokemonSkill*> mPokeSkill;

	int mLv = {};
	string mIdNum = "No. 0";
	char chIdNum[256];
	int mHp = {};
	int mMaxHp = {};
	int mExp = {};
	int mMaxExp = {};

public:
	virtual HRESULT Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	virtual ~Pokemon() 
	{
		SAFE_DELETE(mSkill);
		for (auto& elem : mPokeSkill)
		{
			SAFE_DELETE(elem);
		}
	};

};