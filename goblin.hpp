/****************************************************************************************
 * Program Filename: goblin.hpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Goblin class specification/header file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "character.hpp"

class Goblin : public Character
{
	public:
		Goblin( string gName, Dice *die6 );
		virtual void attackRoll();
		virtual void defenseRoll();	
		virtual void setDamageTaken( int oppAttack );
/******************************************************************************
 *  Function: resetStrength
 *  Description: resets Strength to starting value
 *  Parameters: none
 *  Pre-Conditions: none
 *  Post-Conditions: strength is set to the starting value of the character*
 * ***************************************************************************/
		virtual void resetStrength();
		//virtual void battle( Character & );

	protected:
		bool achilles;
		Dice &die6;
};

#endif
