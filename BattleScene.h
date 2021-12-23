#pragma once
#include "GameEntity.h"

class Image;
class BattleScene : public GameEntity
{
private:
	Image* mBattleMain;
	Image* mBattleSkill;
	Image* mBattleSelect;
	Image* mBattleCusor;

	Image* mJiwooImg;

public:

	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();


};

