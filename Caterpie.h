#pragma once
#include "Pokemon.h"

class Caterpie : public Pokemon
{
private:
	vector<PokemonSkill> mCaterSkill;

public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

