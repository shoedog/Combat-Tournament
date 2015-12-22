/****************************************************************************************
 * Program Filename: reptilians.hpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Reptile People class specification/header file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#ifndef REPTILIANS_HPP
#define REPTILIANS_HPP

#include "character.hpp"

class Reptilian : public Character
{
	public:
		Reptilian( string rName, Dice *die6 );
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
};

#endif
