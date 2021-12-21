#pragma once
#include "Pokemon.h"

class PigeonTwo : public Pokemon
{
public:
	HRESULT Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
};

