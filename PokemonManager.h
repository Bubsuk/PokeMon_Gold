#pragma once
#include "Singleton.h"
#include "Pokemon.h"


class PokemonManager : public Singleton<PokemonManager>
{
public:
	Pokemon* mTempPokemon;

	// ���ڻ� NPC�� ���ϸ� ������ ���� ��
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

	// ���ڻ� NPC ������ ����
	void Release();

	static Pokemon* FactoryFunc(ePokemon pokemon);

};

