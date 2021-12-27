#include "stdafx.h"
#include "InventoryManager.h"



void InventoryManager::Init()
{
	// 플레이어
	mMonsterball.amount = 5;
	mMonsterball.itemName = "몬스터볼";
	mMonsterball.monster = false;

	mPlayerHeal.amount = 5;
	mPlayerHeal.itemName = "상처약";
	mPlayerHeal.monster = false;

	mPlayerPowerHeal.amount = 5;
	mPlayerPowerHeal.itemName = "고급 상처약";
	mPlayerPowerHeal.monster = false;

	// 몬스터
	mMonHeal.amount = 0;
	mMonHeal.itemName = "상처약";
	mMonHeal.monster = true;

	mMonPowHeal.amount = 0;
	mMonPowHeal.itemName = "고급 상처약";
	mMonPowHeal.monster = true;
}

void InventoryManager::Update()
{
}

void InventoryManager::HealItemToMon()
{
	if (mPlayerHeal.amount >= 0)
	{
		--mPlayerHeal.amount;
		++mMonHeal.amount;
	}
}

void InventoryManager::HealItemFromMon()
{
	if (mMonHeal.amount >= 0)
	{
		--mMonHeal.amount;
		++mPlayerHeal.amount;
	}
}

void InventoryManager::PowHealItemToMon()
{
	if (mPlayerPowerHeal.amount >= 0)
	{
		--mPlayerPowerHeal.amount;
		++mMonPowHeal.amount;
	}
}

void InventoryManager::PowHealItemFromMon()
{
	if (mMonPowHeal.amount >= 0)
	{
		--mMonPowHeal.amount;
		++mPlayerPowerHeal.amount;
	}
}

