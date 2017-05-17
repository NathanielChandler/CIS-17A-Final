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

string CombatManager::ruleBook(shared_ptr<Combatant> attacker, char attack, shared_ptr<Combatant> defender, char previousmove, char* attackerMod, char* defenderMod)
{
	string toReturn;
	//Moveset: a = attack, b = guard, c = evade, d = stance, e = strafe, f = stanced attack, s = staggered
	switch (attack)
	{
	case 'a':
		if (attacker->getCurrentStm() >= attacker->getAtk())							// checks if there's enough stamina
		{
			switch (previousmove)
			{
			case 'e':
			case 'b':
				defender->setCurrentStm(defender->getCurrentStm() - attacker->getAtk()); //knocks down D's stamina
				if (defender->getCurrentStm() <= 0)										// check to see if D's stamina is out		
				{
					*defenderMod = 's';
				}
				if(attacker-> getAtk() > defender-> getDef())							// check for damage
				{
					int vitChange = defender->getCurrentVit() - (attacker->getAtk() - defender->getDef()); 
					defender->setCurrentVit(vitChange);
				}
				attacker->setCurrentStm(attacker->getCurrentStm() - attacker->getAtk());  //deducts from A's stamina
				break;
			case 'c':
			case 'd':
			
			default:
				break;
			}
		}
		else 
		break;
	case 'b':
		switch (previousmove)
		{
		case 'a':
		default:
			break;
		}
	case 'c':
	//case 'd':
	case 'e':
	case 'f':
	case 's':
	default:
		break;
	}
	//check for damage if last move was 'stance'
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
