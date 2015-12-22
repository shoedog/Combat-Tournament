/****************************************************************************************
 * Program Filename: ex4.cpp
 * Author: Wesley Jinks
 * Date: March 1, 2015
 * Description: Main program file 
 * Input: None
 * Output: None
 * *************************************************************************************/
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include "character.hpp"
#include "barbarian.hpp"
#include "reptilian.hpp"
#include "blueMen.hpp"
#include "goblin.hpp"
#include "shadow.hpp"

using std::cout;
using std::cin;
using std::queue;
using std::stack;
//void battle( Character &, Character & );

int main()
{
	Dice dieSix(6);
	Dice dieTen(10);
//	Barbarian conan( "Howard", &dieSix );;
//	Barbarian Thor( "Donald", &dieSix );;
//	Reptilian QueenElizabeth( &dieSix );
//	Reptilian Thoth( &dieSix );
///	BlueMen Man1( &dieSix, &dieTen );
//	BlueMen Man2( &dieSix, &dieTen );
//	Goblin Goblin1( &dieSix );
//	Goblin Goblin2( &dieSix );
//	Shadow TheShadow1( &dieSix, &dieTen );
//	Shadow TheShadow2( &dieSix, &dieTen );
	int numChar;
	int charCount;
	int charChoice;
	string name;
	queue<Character *> p1LineUp;
	queue<Character *> p2LineUp;
	stack<Character *> losersP1;
	stack<Character *> losersP2;
	Character *p1Fighter;
	Character *p2Fighter;
	Character *top1;
	Character *top2;
	Character *top3;
	Character *temp;
	bool player = 0;
	int pointsP1 = 0;
	int pointsP2 = 0;

	//Prompts for number of characters per team
	cout << "Welcome to the Tournament. How many characters do you want per team? \n";
	cin >> numChar;
	charCount = numChar;

	//Loops twice, once for each player
	//Prompts for character types and names for each team
	//Builds teams and adds characters to linups
	for( int i = 0; i < 2; i++ )
	{
		do
		{
			if( player == 0 )
				cout << "\n   Player 1: ";
			else if( player == 1 )
				cout << "\n   Player 2: ";
			cout << "\nChoose your team.\n  Barbarian is 1, Reptilian is 2, Blue Man is 3, "
				 << "Goblin is 4, and Shadow is 5. ";
			cin >> charChoice;
			cout << "\n What is the name of your fighter ";
			cin.ignore();
			getline( cin, name );

			if( charChoice == 1 )
			{
				Barbarian *fighter = new Barbarian( name, &dieSix );
				numChar--;
				if( player == 0 )
					p1LineUp.push( fighter );
				else if( player == 1 )
					p2LineUp.push( fighter );
			}
			else if( charChoice == 2 )
			{
				Reptilian* fighter = new Reptilian( name, &dieSix );	
				numChar--;
				if( player == 0 )
					p1LineUp.push( fighter );
				else if( player == 1 )
					p2LineUp.push( fighter );
			}
			else if( charChoice == 3 )
			{
				BlueMen* fighter = new BlueMen( name, &dieSix, &dieTen );
				numChar--;
				if( player == 0 )
					p1LineUp.push( fighter );
				else if( player == 1 )
					p2LineUp.push( fighter );
			}
			else if( charChoice == 4 )
			{
				Goblin* fighter = new Goblin( name, &dieSix );
				numChar--;
				if( player == 0 )
					p1LineUp.push( fighter );
				else if( player == 1 )
					p2LineUp.push( fighter );
			}
			else if( charChoice == 5 )
			{
				Shadow* fighter = new Shadow( name, &dieSix, &dieTen );
				numChar--;
				if( player == 0 )
					p1LineUp.push( fighter );
				else if( player == 1 )
					p2LineUp.push( fighter );
			}
			else
				cout << "You didn't enter a valid choice. Character choices are 1-5.\n";
		}while( ( charChoice < 1 || charChoice > 5 ) || numChar > 0 );
		player = 1;
		numChar = charCount;
	}


	//Have LineUps Battle
	//Add winner back to LineUp and reset some strength
	//Add loser to Loser Pile
	//Add Points for each round won
	while( (p1LineUp.size() != 0 ) && (p2LineUp.size() != 0 ) )
	{
		int round = 1; 
		p1Fighter = p1LineUp.front();
		p2Fighter = p2LineUp.front();
		p1LineUp.pop();
		p2LineUp.pop();

		cout << "\nRound " << round << ": \n";
		p1Fighter->battle( *p2Fighter );	

		if( p1Fighter->getStrength() <= 0 )
		{
			losersP1.push( p1Fighter );
			p2Fighter->resetStrength();
			p2LineUp.push( p2Fighter );
			pointsP2++;
		}
		else if( p2Fighter->getStrength() <= 0 )
		{
			losersP2.push( p2Fighter );
			p1Fighter->resetStrength();
			p1LineUp.push( p1Fighter );
			pointsP1++;
		}
	}

	//Display Points and winner
	cout << "\nBattle Over!\n"
		 << "Player 1's points: " << pointsP1 << ". \n"
		 << "Player 2's points: " << pointsP2 << ". \n";

	if( pointsP1 > pointsP2 )
		cout << "Player 1 won! \n";
	else
		cout << "Player 2 won! \n";


	while( p1LineUp.size() > 0 )
	{
		top1 = p1LineUp.front();
		p1LineUp.pop();
		losersP1.push( top1 );
	}	

	while( p2LineUp.size() > 0 )
	{
		top1 = p2LineUp.front();
		p2LineUp.pop();
		losersP2.push( top1 );
	}

	p1Fighter = losersP1.top();
	p2Fighter = losersP2.top();
	losersP1.pop();
	losersP2.pop();

	if( p1Fighter->getTotalPoints() < p2Fighter->getTotalPoints() )
	{
		top1 = p2Fighter;
		if( losersP2.size() != 0 )
		{
			p2Fighter = losersP2.top();
			losersP2.pop();
		}
	}
	else
	{
		top1 = p1Fighter;
		if( losersP1.size() != 0 )
		{
			p1Fighter = losersP1.top();
			losersP1.pop();
		}
	}

	if( p1Fighter->getTotalPoints() < p2Fighter->getTotalPoints() )
	{
		top2 = p2Fighter;
		if( losersP2.size() != 0 )
		{
			p2Fighter = losersP2.top();
			losersP2.pop();
		}
	}
	else
	{
		top2 = p1Fighter;
		if( losersP1.size() != 0 )
		{
			p1Fighter = losersP1.top();
			losersP1.pop();
		}
	}
	
	if( p1Fighter->getTotalPoints() < p2Fighter->getTotalPoints() )
	{
		top3 = p2Fighter;
		if( losersP2.size() != 0 )
		{
			p2Fighter = losersP2.top();
			losersP2.pop();
		}
	}
	else
	{
		top3 = p1Fighter;
		if( losersP1.size() != 0 )
		{
			p1Fighter = losersP1.top();
			losersP2.pop();
		}
	}

	if( top2->getTotalPoints() < top3->getTotalPoints() )
	{
		temp = top2;
		top2 = top3;
		top3 = temp;
	}

	if( top1->getTotalPoints() < top2->getTotalPoints() )
	{
		temp = top1;
		top1 = top2;
		top2 = temp;
	}
	
	cout << "The first place fighter is a " << top1->getType() << " named "
		 << top1->getName() << ".\n     Wins: " << top1->getWinCounter()
		 << "\n    Strength Remaining: " << top1->getStrength() << "\n";
	
	cout << "The second place fighter is a " << top2->getType() << " named "
		 << top2->getName() << ".\n     Wins: " << top2->getWinCounter()
		 << "\n    Strength Remaining: " << top2->getStrength() << "\n";
	
	cout << "The third place fighter is a " << top3->getType() << " named "
		 << top3->getName() << ".\n     Wins: " << top3->getWinCounter()
		 << "\n    Strength Remaining: " << top3->getStrength()  << "\n";
	
/*	for( int i = 0; i < 10000000; i++ )
	{
		cout << "Barbarian vs Barbarian: \n";
		conan.battle( Thor );
		cout << "\n Barbarian vs Reptilian: \n";
		conan.battle( QueenElizabeth );
		cout << "\n Barbarian vs Blue Man: \n";
		conan.battle( Man1 );
		cout << "\n Barbarian vs Goblin: \n";
		conan.battle( Goblin1 );
		cout << "\n Barbarian vs Shadow: \n";
		conan.battle( TheShadow1 );
		cout << "\n Reptilian vs Reptilian: \n";
		QueenElizabeth.battle( Thoth );
		cout << "\n Reptilian vs Blue Man: \n";
		QueenElizabeth.battle( Man1 );
		cout << "\n Reptilian vs Goblin: \n";
		QueenElizabeth.battle( Goblin1 );
		cout << "\n Reptilian vs Shadow: \n";
		QueenElizabeth.battle( TheShadow1 );
		cout << "\n Blue Man vs Blue Man: \n";
		Man1.battle( Man2 );
		cout << "\n Blue Man vs Goblin: \n";
		Man1.battle( Goblin1 );
		cout << "\n Blue man vs Shadow: \n";
		Man1.battle( TheShadow1 );
		cout << "\n Goblin vs Goblin: \n";
		Goblin1.battle( Goblin2 );
		cout << "\n Goblin vs Shadow: \n";
	 	Goblin1.battle( TheShadow1 );
		cout << "\n Shadow vs Shadow: \n";
		TheShadow1.battle( TheShadow2 );	
	}

*/
//	std::cout << "Conan wins: " << conan.getWinCounter() << "\n";
//	std::cout << "Thor wins: " << Thor.getWinCounter() << "\n";
//	std::cout << "Queen Elizabeth wins: " << QueenElizabeth.getWinCounter() << "\n";
//	std::cout << "Thoth: " << Thoth.getWinCounter() << "\n";
//	std::cout << "Blue Man: " << Man1.getWinCounter() << "\n";
//	std::cout << "Goblin: " << Goblin1.getWinCounter() << "\n";
//	std::cout << "Shadow: " << TheShadow1.getWinCounter() << "\n";
	return 0;
}

/*
void battle( Character &p1, Character &p2 )
{
	bool turn;
	int damage;
	srand( time(NULL) );
	
	turn = rand() % 2;

	while( !(p1.getStrength() <= 0) && !(p2.getStrength() <= 0) )
	{
		if( turn == 0 )
		{
			p2.defenseRoll();
			p1.attackRoll();
			damage = ( p1.getAttack() - p2.getDefense() - p2.getArmor() );
			p2.setDamageTaken( damage );
		//	turn = 1;
			cout << "p1 attack: " << p1.getAttack() << " P2 Defense: " << p2.getDefense() << "  P2 strength: " << p2.getStrength() << "\n";
		}
		else if( turn == 1 )
		{
			p1.defenseRoll();
			p2.attackRoll();
			damage = ( p2.getAttack() - p1.getDefense() -p1.getArmor() );
			p1.setDamageTaken( damage );
		//	turn = 0;
			cout << "p2 attack: " << p2.getAttack() << " P1 Defense: " << p1.getDefense() << " P1 strength: " << p1.getStrength() << "\n";
		}

		if( turn == 0 )
			turn = 1;
		else if( turn == 1)
			turn = 0;
	}
	
	if( p1.getStrength() <= 0 )
		cout << "Player 2 won \n ";
	else if( p2.getStrength() <= 0 )
		cout << "Player 1 won \n";

}
*/
