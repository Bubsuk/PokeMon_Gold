#pragma once
#include "Singleton.h"

typedef struct PokemonItem
{
	string itemName;
	int amount;
	bool monster;

} MONSTERBALL, HEAL, POWHEAL;


class InventoryManager : public Singleton<InventoryManager>
{
public:
	// 플레이어
	MONSTERBALL mMonsterball;
	HEAL mPlayerHeal;
	POWHEAL mPlayerPowerHeal;

	// 몬스터
	HEAL mMonHeal;
	POWHEAL mMonPowHeal;

	void Init();
	void Update();

	void HealItemToMon();
	void HealItemFromMon();
	void PowHealItemToMon();
	void PowHealItemFromMon();

};

