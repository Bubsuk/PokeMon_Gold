#pragma once
#include "Pokemon.h"

class Caterpie : public Pokemon
{
public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

