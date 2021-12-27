#include "stdafx.h"
#include "InventoryManager.h"



void InventoryManager::Init()
{
	// �÷��̾�
	mMonsterball.amount = 5;
	mMonsterball.itemName = "���ͺ�";
	mMonsterball.monster = false;

	mPlayerHeal.amount = 5;
	mPlayerHeal.itemName = "��ó��";
	mPlayerHeal.monster = false;

	mPlayerPowerHeal.amount = 5;
	mPlayerPowerHeal.itemName = "��� ��ó��";
	mPlayerPowerHeal.monster = false;

	// ����
	mMonHeal.amount = 0;
	mMonHeal.itemName = "��ó��";
	mMonHeal.monster = true;

	mMonPowHeal.amount = 0;
	mMonPowHeal.itemName = "��� ��ó��";
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

