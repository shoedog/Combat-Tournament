/****************************************************************************************
 * Program Filename: shadow.hpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Shadow class specification/header file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "character.hpp"

class Shadow : public Character
{
	public:
		Shadow( string sName, Dice *die6, Dice *die10 );
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

	private:
		Dice &die6;
		Dice &die10;
};

#endif
