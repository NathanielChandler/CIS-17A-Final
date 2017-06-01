#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Boss.h"
#include "CombatManager.h"
using namespace std;

/*create methods for:
combat
room navigation
save/load

*/

int main()
{
	int select;
	cout << "\t--------------------\n" << "\t|   Rest in Heap   |\n" << "\t--------------------\n" << endl;
	cin >> select;
	auto player = shared_ptr<Player>(new Player("Bob"));
	player->setMaxVit(10);
	player->setMaxStm(10);
	player->resetStats();
	player->setAtk(2);
	player->setDef(2);

	auto enemy = shared_ptr<Enemy>(new Enemy(1, 1));
	char in;
	auto combat = CombatManager(player, enemy);
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
	if (enemy->isDead()) cout << enemy->getName() << " was killed" << endl;
	return 0;
}