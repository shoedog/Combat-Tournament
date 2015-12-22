/****************************************************************************************
 * Program Filename: blueMen.cpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Blue Men class implementation file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#include "character.hpp"
#include "blueMen.hpp"

BlueMen::BlueMen( string bName, Dice *pDie6 = NULL, Dice *pDie10 = NULL )
	: Character( bName, "Blue Men", 12, 3, 0, 0 ),
	die6(*pDie6),
	die10(*pDie10)
{
}

void BlueMen::attackRoll()
{
	this->attack = die10.rollDice() + die10.rollDice();
}

void BlueMen::defenseRoll()
{
	this->defense = die6.rollDice() + die6.rollDice() + die6.rollDice();;
}

/******************************************************************************
 *  Function: resetStrength
 *  Description: resets Strength to starting value
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: strength is set to the starting value of the character*
 * ***************************************************************************/
void BlueMen::resetStrength()
{
	int currentStrength;
	currentStrength = this->strength;
	currentStrength *= 1.25;
	this->strength = currentStrength;
}
