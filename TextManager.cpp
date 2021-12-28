#include "stdafx.h"
#include "TextManager.h"
#include "Enum.h"
#include "PokemonManager.h"
#include <fstream>

void TextManager::Init()
{
	ReadScript("Dialogue/DrODialogue.txt", mDrOScript);

	ItemScript();
		
}

void TextManager::ReadScript(const char* directory, vector<string> &strvec)
{
	ifstream input_file(directory);
	if (true == input_file.is_open())
	{
		string s;
		while (getline(input_file, s, ';'))
		{
			strvec.push_back(s);
		}
		input_file.close();
	}
	else
	{ 
		cout << "파일 열기에 실패" << endl;
	}
	
}

void TextManager::BattleScript()
{
	mBattleScript.emplace_back("앗!\n야생의 " + POKE_MGR->mTempPokemon->mName + "(이)가 나타났다!");
	mBattleScript.emplace_back("가랏! " + POKE_MGR->mJiwooPokemon[0]->mName + "!");


	for (int j = 0; j < POKE_MGR->mJiwooPokemon[0]->mPokeSkill.size(); ++j)
	{
		mBattleScript1.emplace_back(POKE_MGR->mJiwooPokemon[0]->mName + "의 " + POKE_MGR->mJiwooPokemon[0]->mPokeSkill[j]->mSkillName + "!");
	}
		

	for (int i = 0; i < POKE_MGR->mTempPokemon->mPokeSkill.size(); ++i)
	{
		mEnemyScript.emplace_back(POKE_MGR->mTempPokemon->mName + "의 " + POKE_MGR->mTempPokemon->mPokeSkill[i]->mSkillName + "!");
	}
	
	
	mBattleScript1.emplace_back("급소에 맞았다!");//2
	mBattleScript1.emplace_back("지우의 패배!");
	mBattleScript1.emplace_back(POKE_MGR->mTempPokemon->mName + "를 획득했다!"); //4
	mBattleScript1.emplace_back("적의 " + POKE_MGR->mTempPokemon->mName + "는 쓰러젔다!");
	mBattleScript1.emplace_back("신난다! " + POKE_MGR->mTempPokemon->mName + "를 잡았다!");

}

void TextManager::ItemScript()
{
	mItemScript.emplace_back("포켓몬을 잡기 위한 도구");
	mItemScript.emplace_back("체력을 20 회복시킨다");
	mItemScript.emplace_back("체력을 60 회복시킨다");
	
}

