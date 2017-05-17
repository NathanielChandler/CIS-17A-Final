#include "CombatManager.h"
#include <random>
#include <time.h>


void CombatManager::getEnemyMoveset()
{
	int size = _enemy->getMovesetSize();
	srand(time(NULL));
	int selection = rand() % size;
	_enemy->getMoveset(selection);
}

string CombatManager::enemyMoveManager()
{
	return string();
}

string CombatManager::ruleBook(shared_ptr<Combatant> attacker, char attack, shared_ptr<Combatant> defender, char lastmove)
{
	string toReturn;
	//Moveset: a = attack, b = guard, c = evade, d = stance, e = strafe, f = stanced attack, s = staggered
	switch (attack)
	{
	case 'a':
		switch (lastmove)
		{
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		default:
			break;
		}
		break;
	case 'b':
		switch (lastmove)
		{
		case 'a':
		default:
			break;
		}
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 's':
	default:
		break;
	}

	return toReturn;
}

CombatManager::CombatManager(shared_ptr<Player> player, shared_ptr<Enemy> enemy) : _player(player) , _enemy(enemy)
{
}

CombatManager::~CombatManager()
{
}

string CombatManager::turn(char c)
{
	return string();
}
