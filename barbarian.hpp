/****************************************************************************************
 * Program Filename: barbarian.hpp
 * Author: Wesley Jinks
 * Date: Feb. 13th, 2015
 * Description: Barbarian class specification/header file 
 * Input: None
 * Output: None
 * *************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
	public:
		Barbarian( std::string bname, Dice *die6 );
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
