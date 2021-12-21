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


	Image* mBackGround = nullptr;
	Image* aaa = nullptr;
	IngameMap* mCityMap;
	TILE_INFO* mTileIn;


public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	
};