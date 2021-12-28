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
		cout << "���� ���⿡ ����" << endl;
	}
	
}

void TextManager::BattleScript()
{
	mBattleScript.emplace_back("��!\n�߻��� " + POKE_MGR->mTempPokemon->mName + "(��)�� ��Ÿ����!");
	mBattleScript.emplace_back("����! " + POKE_MGR->mJiwooPokemon[0]->mName + "!");


	for (int j = 0; j < POKE_MGR->mJiwooPokemon[0]->mPokeSkill.size(); ++j)
	{
		mBattleScript1.emplace_back(POKE_MGR->mJiwooPokemon[0]->mName + "�� " + POKE_MGR->mJiwooPokemon[0]->mPokeSkill[j]->mSkillName + "!");
	}
		

	for (int i = 0; i < POKE_MGR->mTempPokemon->mPokeSkill.size(); ++i)
	{
		mEnemyScript.emplace_back(POKE_MGR->mTempPokemon->mName + "�� " + POKE_MGR->mTempPokemon->mPokeSkill[i]->mSkillName + "!");
	}
	
	
	mBattleScript1.emplace_back("�޼ҿ� �¾Ҵ�!");//2
	mBattleScript1.emplace_back("������ �й�!");
	mBattleScript1.emplace_back(POKE_MGR->mTempPokemon->mName + "�� ȹ���ߴ�!"); //4
	mBattleScript1.emplace_back("���� " + POKE_MGR->mTempPokemon->mName + "�� ��������!");
	mBattleScript1.emplace_back("�ų���! " + POKE_MGR->mTempPokemon->mName + "�� ��Ҵ�!");

}

void TextManager::ItemScript()
{
	mItemScript.emplace_back("���ϸ��� ��� ���� ����");
	mItemScript.emplace_back("ü���� 20 ȸ����Ų��");
	mItemScript.emplace_back("ü���� 60 ȸ����Ų��");
	
}

