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
	// �÷��̾�
	MONSTERBALL mMonsterball;
	HEAL mPlayerHeal;
	POWHEAL mPlayerPowerHeal;

	// ����
	HEAL mMonHeal;
	POWHEAL mMonPowHeal;

	void Init();
	void Update();

	void HealItemToMon();
	void HealItemFromMon();
	void PowHealItemToMon();
	void PowHealItemFromMon();

};

