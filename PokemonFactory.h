#pragma once
#include "Enum.h"


class Pokemon;
class PokemonFactory
{
public:
	virtual Pokemon* FactoryFunc(ePokemon pokemon);
};

