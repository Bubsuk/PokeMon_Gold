#include "stdafx.h"
#include "PokemonManager.h"
#include "Caterpie.h"
#include "PikaChu.h"
#include "Chicorita.h"
#include "Bcane.h"
#include "Riaco.h"
#include "GgoRat.h"



void PokemonManager::Init()
{
	// ���ڻ� NPC�� ���ϸ� ������ ���� ��
	PIKACHU = FactoryFunc(ePokemon::Pika);
	CHIKO = FactoryFunc(ePokemon::Chicorita);

	mJiwooPokemon.emplace_back(PIKACHU);
	mJiwooPokemon.emplace_back(CHIKO);
	mPokeDogam.emplace_back(PIKACHU);
	mPokeDogam.emplace_back(CHIKO);
	///////////////////////////////////////
}

void PokemonManager::RegistDogam(Pokemon* monster)
{
	if (mPokeDogam.empty())
	{
		mPokeDogam.emplace_back(monster);
	}
	else if(!mPokeDogam.empty())
	{
		if (CheckExisted(monster) == true)
		{
			return;
		}
		else
		{
			Pokemon* Temp = FactoryFunc(monster->mPokeSpecies);
			mPokeDogam.emplace_back(Temp);
			SAFE_RELEASE(monster);
		}
	}
	
}

void PokemonManager::RegistDogamAfterCatch(Pokemon* monster)
{
	if (mPokeDogam.empty())
	{
		mPokeDogam.emplace_back(monster);
	}
	else if (!mPokeDogam.empty())
	{
		if (CheckExisted(monster) == true)
		{
			return;
		}
		else
		{
			mPokeDogam.emplace_back(monster);
		}
	}

}

bool PokemonManager::CheckExisted(Pokemon* monster)
{
	for (int i = 0; i < mPokeDogam.size(); ++i)
	{
		if (mPokeDogam[i]->mPokeSpecies == monster->mPokeSpecies)
		{
			return true;
		}
	}
	return false;
}

void PokemonManager::CatchPoke(Pokemon* monster)
{
	mJiwooPokemon.emplace_back(monster);
}


// ���ڻ� NPC ������ ����
void PokemonManager::Release()
{
	for (auto& elem : mPokeDogam)
	{
		SAFE_RELEASE(elem);
	}
}


Pokemon* PokemonManager::FactoryFunc(ePokemon pokemon)
{
	switch (pokemon)
	{
	case ePokemon::Caterpie:
		return new Caterpie;
		break;
	case ePokemon::Pika:
		return new PikaChu;
		break;
	case ePokemon::Chicorita:
		return new Chicorita;
		break;
	case ePokemon::Bcane:
		return new Bcane;
		break;
	case ePokemon::Riaco:
		return new Riaco;
		break;
	case ePokemon::Ggorat:
		return new GgoRat;
		break;
	default:
		break;
	}
}

