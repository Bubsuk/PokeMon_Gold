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
	// 오박사 NPC로 포켓몬 받으면 지울 것
	PIKACHU = FactoryFunc(ePokemon::Pika);
	CHIKO = FactoryFunc(ePokemon::Chicorita);

	mJiwooPokemon.emplace_back(PIKACHU);
	mJiwooPokemon.emplace_back(CHIKO);
	RegistDogam(PIKACHU);
	RegistDogam(CHIKO);
	///////////////////////////////////////

	mExisted = false;
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
		else mPokeDogam.emplace_back(monster);
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

void PokemonManager::KillPoke(Pokemon* monster)
{
	SAFE_DELETE(monster);
}



// 오박사 NPC 나오면 수정
void PokemonManager::Release()
{
	SAFE_RELEASE(PIKACHU);
	SAFE_RELEASE(CHIKO);
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

