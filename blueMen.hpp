/****************************************************************************************
 * Program Filename: blueMen.hpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Blue Men class specification/header file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class BlueMen : public Character
{
	public:
		BlueMen( string bName, Dice *die6, Dice *die10 );
		virtual void attackRoll();
		virtual void defenseRoll();	
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
