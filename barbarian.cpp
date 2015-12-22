/****************************************************************************************
 * Program Filename: barbarian.cpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Barbarian class implementation file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#include "character.hpp"
#include "barbarian.hpp"

Barbarian::Barbarian( std::string bname, Dice *pDie6 = NULL )
	: Character( bname, "barbarian", 12, 0, 0, 0 ),
	 die6(*pDie6)
{
}

void Barbarian::attackRoll()
{
	this->attack = die6.rollDice() + die6.rollDice();
	//return att;;
}

void Barbarian::defenseRoll()
{
	this->defense = die6.rollDice() + die6.rollDice();
}

/******************************************************************************
 *  Function: resetStrength
 *  Description: resets Strength to starting value
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: strength is set to the starting value of the character*
 * ***************************************************************************/
void Barbarian::resetStrength()
{
	int currentStrength;
	currentStrength = this->strength;
	currentStrength *= 1.5;
	this->strength = currentStrength;
}
