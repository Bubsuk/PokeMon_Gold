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
}

void PokemonManager::RegistDogam(Pokemon* monster)
{
	mPokeDogam.emplace_back(monster->mPokeSpecies, monster);

	sort(mPokeDogam.begin(), mPokeDogam.end());
	mPokeDogam.erase(unique(mPokeDogam.begin(), mPokeDogam.end()), mPokeDogam.end());
}

void PokemonManager::CatchPoke(Pokemon* monster)
{
	mJiwooPokemon.emplace_back(monster);
}

void PokemonManager::KillPoke(Pokemon* monster)
{
	SAFE_DELETE(monster);
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




