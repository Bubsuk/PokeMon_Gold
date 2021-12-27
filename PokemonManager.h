#pragma once
#include "Singleton.h"
#include "Pokemon.h"


class PokemonManager : public Singleton<PokemonManager>
{
public:
	Pokemon* mTempPokemon;

	// 오박사 NPC로 포켓몬 받으면 지울 것
	Pokemon* PIKACHU;
	Pokemon* CHIKO;
	/////////////////////////////////////


	vector<pair<ePokemon, Pokemon*>> mPokeDogam;
	vector<Pokemon*> mJiwooPokemon;

	void Init();
	void RegistDogam(Pokemon* monster);
	void CatchPoke(Pokemon* monster);
	void KillPoke(Pokemon* moster);

	static Pokemon* FactoryFunc(ePokemon pokemon);

};

