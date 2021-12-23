#pragma once
#include "GameEntity.h"

class IngameMap;
class Pokemon;
class Jiwoo;
class Image;
class TestScene : public GameEntity
{
private:
	Jiwoo* mJiwoo;
	Pokemon* randomPokemon;
	POINT mJiwooPos;

	Image* mBackGround = nullptr;
	Image* aaa = nullptr;



public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	
};