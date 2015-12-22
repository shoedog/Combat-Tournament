/****************************************************************************************
 * Program Filename: shadow.cpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: The Shadow class implementation file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#include "character.hpp"
#include "shadow.hpp"

//Constructor for Shadow Class
// Inherited from Character
// 2 references to Dice objects are passed
Shadow::Shadow( string sName, Dice *pDie6 = NULL, Dice *pDie10 = NULL )
	: Character( sName, "Shadow", 12, 0, 0, 0 ),
	die6(*pDie6),
	die10(*pDie10)
{
}

/******************************************************************************
 *  Function: attack
 *  Description: rolls 2 dice to attack
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: attack is set to the sum of the dice roll *
 * ***************************************************************************/
void Shadow::attackRoll()
{
	this->attack = die10.rollDice() + die10.rollDice();
}

/******************************************************************************
 *  Function: defense
 *  Description: rolls 1 dice to defend
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: attack is set to the sum of the dice roll *
 * ***************************************************************************/
void Shadow::defenseRoll()
{
	this->defense = die6.rollDice();	
}

/******************************************************************************
 *  Function: setDamageTaken
 *  Description: uses a 50-50 rand to determine if special is active, then
 *			determines damage based on opponents attack, as well as defense
 *			and armor
 *  Parameters: Opponents attack: an integer
 *  Pre-Conditions: a valid integer must be passed
 *  Post-Conditions: damage is 0 if special is active, otherwise it is
 *		attack - defense - armor
 * ***************************************************************************/
void Shadow::setDamageTaken( int oppAttack )
{
	int special;
	int damage;

	special = rand() % 2;

	if( special == 1 )
		this->damageTaken = 0;
	else if( special == 0 )
	{
		damage = ( oppAttack - this->getDefense() - this->getArmor() );
	
		if( damage > 0 )
		{
			this->damageTaken = damage;
			this->strength -= damage;
		}
	}	
}

/******************************************************************************
 *  Function: resetStrength
 *  Description: resets Strength to starting value
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: strength is set to the starting value of the character*
 * ***************************************************************************/
void Shadow::resetStrength()
{
	int currentStrength;
	currentStrength = this->strength;
	currentStrength *= 1.7;
	this->strength = currentStrength;
}
