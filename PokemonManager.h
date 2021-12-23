#pragma once
#include "Singleton.h"
#include "Pokemon.h"


class PokemonManager : public Singleton<PokemonManager>
{
public:
	Pokemon* mTestBcane;
	Pokemon* mTestPika;

	vector<Pokemon*> mPokeDogam;

	void CatchPoke(Pokemon* monster);
	void KillPoke(Pokemon* moster);

	void StartPoke();

};

