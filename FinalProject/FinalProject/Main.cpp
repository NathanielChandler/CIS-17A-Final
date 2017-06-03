#pragma once
#include <iostream>
#include "CombatManager.h"
#include "SaveSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Map.h"
using namespace std;

void startGame();
void turn(shared_ptr<Player> player);
void combat(shared_ptr<Player> player, shared_ptr<Combatant> enemy);
void move();
/*create methods for:
combat
room navigation
save/load

*/

SaveSystem saveSystem;
Map dungeon;
vector<string> saveFiles;

int main()
{	
	dungeon.InitMap();

	startGame();
	
	/*
	auto enemy = shared_ptr<Enemy>(new Enemy(1, 1));
	//auto combat = CombatManager(player, enemy);
	*/
	return 0;
}

void startGame()
{
	cout << "\t--------------------\n" << "\t|   Rest in Heap   |\n" << "\t--------------------\n"
		<< "By Nate,     Xavier,   and   Deven" << endl << endl;

	char choice;
	cout << "<N> : New Game" << endl
	//	<< "<C> : Continue" << endl
		<< "<Q> : Quit" << endl
		<< ">> ";
	cin >> choice;
	/*
	switch (toupper(choice))
	{
		case 'N':
		{
			system("cls");
			string name;
			cout << "Enter new player name:" << endl << ">> ";
			cin >> name;
			auto player = Player(name);
			player.setMaxVit(10);
			player.setMaxStm(10);
			player.resetStats();
			player.setAtk(2);
			player.setDef(2);
			player.setAmd(0);
			player.setAud(0);
			//saveSystem.addNewSaveFile(player, name, saveFiles, dungeon);
			break;
		}
			
		case 'C':
		{
			string name;
			system("cls");
			cout << "Enter the name of the player you wish to play as:" << endl << ">>";
			cin >> name;
			Player player = saveSystem.retrieveSaveData(name, dungeon);
			break;
		}
			
		case 'Q':
			break;
	}
	*/
	if (choice == 'N')
	{
		system("cls");
		string name;
		cout << "Enter new player name:" << endl << ">> ";
		cin >> name;
		shared_ptr<Player> player(new Player(name));
		player->setMaxVit(20);
		player->setMaxStm(20);
		player->resetStats();
		player->setAtk(5);
		player->setDef(2);
		player->setAmd(0);
		player->setAud(0);
		while (player->isDead() == false)
		{
			turn(player);
		}
	}
}

void turn(shared_ptr<Player> player)
{
	//ask to fight
	if (dungeon.getCurrentLocation()->getOccupant()->isDead() == false)
	{
		combat(player, dungeon.getCurrentLocation()->getOccupant());
	}
	//ask to move
	if (player->isDead() == false)
	{
		move();
	}
}

void combat(shared_ptr<Player> player,shared_ptr<Combatant> enemy)
{
	char in;
	auto combat = CombatManager(player, enemy);
	system("cls");
	if (enemy->getTag() == "enemy") cout << "A " << enemy->getName() << " occupies this room" << endl;
	else 
	{
		cout << "________________________________________________________" << endl;
		cout << "You have enterd the domain of " << enemy->getName() << endl;
		cout << "########################################################" << endl;
	}
	while (player->isDead() == false && enemy->isDead() == false)
	{
		cout << "\t"<< enemy->getName() << "\t" << enemy->getCurrentVit() << "/" << enemy->getMaxVit() << "\n" <<  endl;
		cout << "Vitality: " << player->getCurrentVit() << "/" << player->getMaxVit() << "\t";
		cout << "Stamina: " << player->getCurrentStm() << "/" << player->getMaxStm() << endl;
		cout << "Make a move [a = attack, b = guard, c = evade, d = stance, e = strafe]" << endl;
		cin >> in;
		system("cls");
		cout << combat.turn(in) << endl;
	}
	if (player->isDead()) cout << player->getName() << " died" << endl;
	else if (enemy->isDead())
	{
		system("cls");
		cout << enemy->getName() << " was killed!" << endl;
		cout << "You have gained: \n";
		if (enemy->getAmd() > 0) 
		{
			cout << "\t" << enemy->getAmd() << " Animation Dregs\n";
			player->setAmd(player->getAmd() + enemy->getAmd());
		}
		if (enemy->getAud() > 0)
		{
			cout << "\t" << enemy->getAud() << " Automation Dregs\n";
			player->setAud(player->getAud() + enemy->getAud());
		}
		player->resetStats();
		system("pause");
	}
}

void move()
{
	char in;
	system("cls");
	cout << dungeon.getCurrentLocation()->GenerateDescription() << endl;
	cout << "Where would you like to go?\n\t[ ";
	if (dungeon.getCurrentLocation()->getNorth()) cout << "N = North ";
	if (dungeon.getCurrentLocation()->getSouth()) cout << "S = South ";
	if (dungeon.getCurrentLocation()->getEast()) cout << "E = East ";
	if (dungeon.getCurrentLocation()->getWest()) cout << "W = West ";
	cout << " ]\n>>";
	cin >> in;
	switch (toupper(in))
	{
	case 'N':dungeon.move(NORTH); break;
	case 'S':dungeon.move(SOUTH); break;
	case 'E':dungeon.move(EAST); break;
	case 'W':dungeon.move(WEST); break;
	default: cout << "That's not an option, you doltz";
	}
}
