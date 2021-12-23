#pragma once
#include "GameEntity.h"

class IngameMap;
class Collider : public GameEntity
{
private:
	IngameMap* mCity;
	IngameMap* mEtc;

	
	RECT mPlayer;

	eDir mColDir;


public:


	int SetLimit(eDir dir);
	bool CheckJump();

};

