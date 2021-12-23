#pragma once
#include "Singleton.h"

class Pokemon;
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

