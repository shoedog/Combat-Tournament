
///Header file for Dice class and Loaded Dice Class
#ifndef DICE_HPP
#define DICE_HPP
#include<cstdio>
#include<ctime>
#include<cstdlib>

class Dice
{
	public:
		Dice();
		Dice( int numSides );
		int rollDice() const;
	protected:
		int numSides;
};
#endif
