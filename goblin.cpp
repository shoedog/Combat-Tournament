/****************************************************************************************
 * Program Filename: goblin.cpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Goblin class implementation file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#include "character.hpp"
#include "goblin.hpp"

Goblin::Goblin( string gName, Dice *pDie6 = NULL )
	: Character( gName, "Goblin", 8, 3, 0, 0 ),
	die6(*pDie6)
{
}

void Goblin::attackRoll()
{
	this->attack = die6.rollDice() + die6.rollDice();
//	std::cout << "Goblin attack: " << this->attack;
	if( this->attack == 12 )
		this->achilles = 1;
}

void Goblin::defenseRoll()
{
	this->defense = die6.rollDice();
}

void Goblin::setDamageTaken( int oppAttack )
{	
	int damage;		

	if( achilles == 0 )
	{
		damage = ( oppAttack - this->getDefense() );
		damage -= this->getArmor();
	//	std::cout << "Achilles OFF \n";
	}
	else if( achilles == 1 )
	{
		damage = ( ( oppAttack / 2 ) - this->getDefense() ) ;
		damage -= this->getArmor();
	//	std::cout << "Achilles ON \n";
	}

	if( damage > 0 )
	{
		this->strength -= damage;
		this->damageTaken = damage;
	}
}

/******************************************************************************
 *  Function: resetStrength
 *  Description: resets Strength to starting value
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: strength is set to the starting value of the character*
 * ***************************************************************************/
void Goblin::resetStrength()
{
	int currentStrength;
	currentStrength = this->strength;
	currentStrength *= 1.65;
	this->strength = currentStrength;
	this->achilles = 0;
}
