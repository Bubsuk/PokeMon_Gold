#pragma once
#include "Pokemon.h"

class Dandegi : public Pokemon
{
public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

