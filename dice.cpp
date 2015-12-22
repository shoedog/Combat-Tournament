
//Dice class implementation file

#include "dice.hpp"

Dice::Dice()
{
	numSides = 6;
	srand( time (NULL) ); //seeds random num generation
}

Dice::Dice( int numSides )
{
	this->numSides = numSides;
	srand( time(NULL) ); //eeds random num generation
}

int Dice::rollDice()  const
{
	return (rand() % numSides + 1);
}

