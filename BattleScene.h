#pragma once
#include "GameEntity.h"

class BattleManager;
class BattleScene : public GameEntity
{
private:
	BattleManager* mBattle;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();



};

