#pragma once
#include "Enum.h"

class Image;
class PokemonSkill
{
public:
	// �ʼ� ����
	string mSkillName = "default";
	SkillType eType;
	Image* mSkillImg;
	POINT mImgPos;

	int mAttack = {};
	int mAccuracyRate = {};
	// ���� ��� ��
	int mShield = {};
	int mSpecialAtt = {};
	int mSpecialShield = {};
	int mSpeed = {};

public:
	//void Shake();


};

