#include "stdafx.h"
#include "PokemonFactory.h"
#include "Caterpie.h"



Pokemon* PokemonFactory::FactoryFunc(ePokemon pokemon)
{
	switch(pokemon)
	{
	case ePokemon::Caterpie:
		return new Caterpie();
		break;
	case ePokemon::Dandegi:
		break;
	case ePokemon::Butter:
		break;
	case ePokemon::Bbul:
		break;
	case ePokemon::Ddak:
		break;
	case ePokemon::DokChung:
		break;
	case ePokemon::Gugu:
		break;
	case ePokemon::Rat:
		break;
	case ePokemon::Ggaebi:
		break;
	case ePokemon::Ggaebidrill:
		break;
	case ePokemon::Pika:
		break;
	case ePokemon::Richu:
		break;
	case ePokemon::Chicorita:
		break;
	case ePokemon::Bayleaf:
		break;
	case ePokemon::Meganium:
		break;
	case ePokemon::Bcane:
		break;
	case ePokemon::Riaco:
		break;
	case ePokemon::Alligay:
		break;
	case ePokemon::Jangcro:
		break;
	default:
		break;
	}
}
