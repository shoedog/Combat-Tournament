#include "character.hpp"

Character::Character(string cName, string ch, int str, int arm, int def, int att ) 
{
	setName(cName);
	charType = ch;
	strength = str;
	armor = arm;
	defense = def;
	attack = att;
	winCounter = 0;
	//die6 = die1;
	//die10 = die2;
}

void Character::battle( Character &opp )
{
	bool turn;
	int oppAttack;

	turn = rand() % 2;

	while( !(this->getStrength() <= 0) && !(opp.getStrength() <= 0) )
	{
		if( turn == 0 )
		{
			opp.defenseRoll();
			this->attackRoll();
			oppAttack = this->getAttack();
			opp.setDamageTaken( oppAttack );
				cout << this->getName() << " attack: " << this->getAttack() << " "
				 << opp.getName() <<" Defense: " << opp.getDefense() << " "
				 << opp.getName() << " strength: " << opp.getStrength() << "\n";
		}
		else if( turn == 1 )
		{
			this->defenseRoll();
			opp.attackRoll();
			oppAttack = opp.getAttack();
			this->setDamageTaken( oppAttack );
				cout << opp.getName() << " attack: " << opp.getAttack() << " "
				 << this->getName() << " Defense: " << this->getDefense() << " "
				 << this->getName() << " strength: " << this->getStrength() << "\n";
		}

		if( turn == 0 )
			turn = 1;
		else if( turn == 1)
			turn = 0;
	}

	this->incrementWinCounter( opp );
	
	if( this->getStrength() <= 0 )
		cout << opp.getType() << " " << opp.getName() << "  won \n ";
	else if( opp.getStrength() <= 0 )
		cout << this->getType() << " " << this->getName() << " won \n";

//	opp.resetStrength();	
//	this->resetStrength();

//	std::cout << "Opponent strength: " << opp.getStrength() << " Player strength: " << this->getStrength() << "\n";
}

void Character::incrementWinCounter( Character &char1 )
{
	if( char1.getStrength() <= 0 )
		this->winCounter++;
	else if( this->getStrength() <= 0 )
		char1.winCounter++;
}

void Character::setTotalPoints()
{
	this->totalPoints = (this->winCounter) + (this->strength);
}
int Character::getStrength() const	{ return strength; }
int Character::getArmor() const { return armor; }
int Character::getDefense() const { return defense; }
int Character::getAttack() const { return attack; }
int Character::getWinCounter() const { return winCounter; }
void Character::setStrength( int num ) { strength = num; }
void Character::setDamageTaken( int oppAttack )
{
	int damage;
	damage = ( oppAttack - this->getDefense() - this->getArmor() );
	
	if( damage > 0 )
	{
		this->strength -= damage;
		this->damageTaken = damage;
	}
}

/*	
std::ostream &operator<<( std::ostream &out, const Character c )
{
	out << c.getName() << " has " << c.getStrength << " strength. ";
	return out;
}*/
