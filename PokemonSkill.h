#pragma once
#include "Enum.h"

class Image;
class PokemonSkill
{
public:
	// 필수 구현
	string mSkillName = "default";
	SkillType eType;
	Image* mSkillImg;
	POINT mImgPos;

	int mAttack = {};
	int mAccuracyRate = {};
	// 구현 고민 중
	int mShield = {};
	int mSpecialAtt = {};
	int mSpecialShield = {};
	int mSpeed = {};

public:
	//void Shake();


};

