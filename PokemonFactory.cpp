#include "stdafx.h"
#include "PokemonFactory.h"
#include "Caterpie.h"
#include "PikaChu.h"
#include "Chicorita.h"
#include "Bcane.h"
#include "Riaco.h"
#include "GgoRat.h"



Pokemon* PokemonFactory::FactoryFunc(ePokemon pokemon)
{
	switch(pokemon)
	{
	case ePokemon::Caterpie:
		return new Caterpie;
		break;
	case ePokemon::Pika:
		return new PikaChu;
		break;
	case ePokemon::Chicorita:
		return new Chicorita;
		break;
	case ePokemon::Bcane:
		return new Bcane;
		break;
	case ePokemon::Riaco:
		return new Riaco;
		break;
	case ePokemon::Ggorat:
		return new GgoRat;
		break;
	default:
		break;
	}
}
