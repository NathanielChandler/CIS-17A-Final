#include <iostream>
#include "CombatManager.h"
#include "SaveSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Map.h"
using namespace std;

void startGame();
void turn();
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
	char in;
	//auto combat = CombatManager(player, enemy);
	cout << enemy->getName() << " has appeared!" << endl;
	while (player->isDead() == false && enemy->isDead() == false)
	{
		cout << enemy->getName() << "\t" << enemy->getCurrentVit() << "/" << enemy->getMaxVit() << endl;
		cout << "Vitality: " << player->getCurrentVit() << "/" << player->getMaxVit() << endl;
		cout << "Stamina: " << player->getCurrentStm() << "/" << player->getMaxStm() << endl;
		cout << "Make a move [a = attack, b = guard, c = evade, d = stance, e = strafe]" << endl;
		cin >> in;
		system("cls");
		cout << combat.turn(in) << endl;
	}
	if (player->isDead()) cout << player->getName() << " died" << endl;
	if (enemy->isDead()) cout << enemy->getName() << " was killed" << endl;*/
	return 0;
}

void startGame()
{
	cout << "\t--------------------\n" << "\t|   Rest in Heap   |\n" << "\t--------------------\n"
		<< "By Nate,     Xavier,   and   Deven" << endl << endl;

	char choice;
	cout << "<N> : New Game" << endl
		<< "<C> : Continue" << endl
		<< "<Q> : Quit" << endl
		<< ">> ";
	cin >> choice;

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
			saveSystem.addNewSaveFile(player, name, saveFiles);
			break;
		}
			
		case 'C':
		{
			string name;
			system("cls");
			cout << "Enter the name of the player you wish to play as:" << endl << ">>";
			cin >> name;
			Player player = saveSystem.retrieveSaveData(name);
			break;
		}
			
		case 'Q':
			break;
	}
}

void turn()
{
	//ask to fight
	//ask to move
}