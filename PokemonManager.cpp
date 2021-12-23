#include "stdafx.h"
#include "PokemonManager.h"
#include "Pokemon.h"
#include "PokemonFactory.h"
#include "Bcane.h"
#include "PikaChu.h"

void PokemonManager::CatchPoke(Pokemon* monster)
{
	mPokeDogam.push_back(monster);
}

void PokemonManager::KillPoke(Pokemon* monster)
{
	SAFE_DELETE(monster);
}

void PokemonManager::StartPoke()
{
	mTestBcane = new Bcane;
	mTestPika = new PikaChu;
	mPokeDogam.push_back(mTestBcane);
	mPokeDogam.push_back(mTestPika);

	cout << "Create Pokemons" << endl;

}




