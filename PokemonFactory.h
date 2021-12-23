#pragma once
#include "Enum.h"


class Pokemon;
class PokemonFactory
{
public:
	static Pokemon* FactoryFunc(ePokemon pokemon);
};

