#pragma once
#include "Singleton.h"
#include "Pokemon.h"


class PokemonManager : public Singleton<PokemonManager>
{
public:
	Pokemon* mTempPokemon;

	// 오박사 NPC로 포켓몬 받으면 지울 것
	Pokemon* PIKACHU;
	Pokemon* PIKA;
	Pokemon* CHIKO;
	/////////////////////////////////////


	vector<Pokemon*> mPokeDogam;
	vector<Pokemon*> mJiwooPokemon;

	bool mExisted;

	void Init();
	void RegistDogam(Pokemon* monster);
	void CatchPoke(Pokemon* monster);
	void KillPoke(Pokemon* monster);
	bool CheckExisted(Pokemon* monster);

	// 오박사 NPC 나오면 수정
	void Release();

	static Pokemon* FactoryFunc(ePokemon pokemon);

};

