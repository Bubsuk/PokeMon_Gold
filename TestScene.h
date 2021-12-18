#pragma once
#include "GameEntity.h"

class Pokemon;
class Jiwoo;
class Image;
class TestScene : public GameEntity
{
private:
	Jiwoo* mJiwoo;
	Pokemon* randomPokemon;


	Image* mBackGround = nullptr;

	


public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};