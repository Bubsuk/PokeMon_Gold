#pragma once
#include "Singleton.h"
#include "Pokemon.h"


class PokemonManager : public Singleton<PokemonManager>
{
public:
	Pokemon* mTempPokemon;

	// ���ڻ� NPC�� ���ϸ� ������ ���� ��
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

