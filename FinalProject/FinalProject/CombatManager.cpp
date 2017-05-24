#include "CombatManager.h"
#include <random>
#include <time.h>


void CombatManager::getEnemyMoveset()
{
	int size = _enemy->getMovesetSize();
	srand(time(NULL));
	int selection = rand() % size;
	_enemyMoveset = _enemy->getMoveset(selection);
}

char CombatManager::enemyMoveManager()
{
	char move;
	if (_enemyMoveset.size() < 1) getEnemyMoveset();
	move = _enemyMoveset.at(0);
	_enemyMoveset.erase(_enemyMoveset.begin());
	return move;
}

string CombatManager::ruleBook(shared_ptr<Combatant> attacker, char attack, shared_ptr<Combatant> defender, char previousmove, char* attackerMod, char* defenderMod)
{
	srand(time(NULL));
	int hit = rand() % 4;
	int change;
	int damageMod = 1;
	string toReturn;
	//Moveset: a = attack, b = guard, c = evade, d = stance, e = strafe, f = stanced attack, s = staggered
	switch (attack)
	{
	case 's':
		toReturn += " was staggered!\n";
		break;
	case 'f':
		damageMod++;
		*attackerMod = 'z';
	case 'a':
		if (attacker->getCurrentStm() >= attacker->getAtk())							// checks if there's enough stamina
		{
			toReturn += " attacked\n\t";
			switch (previousmove)
			{
			case 'b':
				defender->setCurrentStm(defender->getCurrentStm() - (attacker->getAtk() * damageMod)); //knocks down D's stamina
				if (defender->getCurrentStm() <= 0)										// check to see if D's stamina is out		
				{
					*defenderMod = 's';
				}
				if(attacker-> getAtk() * damageMod > defender-> getDef())							// check for damage
				{
					int vitChange = (attacker->getAtk() * damageMod) - defender->getDef(); 
					defender->setCurrentVit(defender->getCurrentVit() - vitChange);
					toReturn += "and hit for " + to_string(vitChange) + " damage!\n";
				}
				else
				{
					toReturn += "and the hit was absorbed!\n";
				}
				attacker->setCurrentStm(attacker->getCurrentStm() - attacker->getAtk());  //deducts from A's stamina
				break;
			case 'c': // successful evade, enemy doesn't take damage
				toReturn += "and missed!\n";
				break;
			case 'e': // 25% chance to dodge attack when strafeing
				if (hit > 2)
				{
					toReturn += "and missed!\n";
					break;
				}//carries on down  past d to register hit
			case 'd':// def mod = z, cancels stanced attack
				*defenderMod = 'z';
			case 's':
				if(previousmove == 's') damageMod++;
			default: // hits for damage
				defender->setCurrentVit(defender->getCurrentVit() - (attacker->getAtk() * damageMod));
				attacker->setCurrentStm(attacker->getCurrentStm() - attacker->getAtk());  //deducts from A's stamina
				toReturn += "and hit for " + to_string((attacker->getAtk() * damageMod)) + " damage!\n";
				break;
			}
		}
		break;
	case 'b':// restores stamina
		change = attacker->getMaxStm() / 10;
		if (attacker->getMaxStm() >= attacker->getCurrentStm() + change)
			attacker->setCurrentStm(attacker->getCurrentStm() + change);
		else
			attacker->setCurrentStm(attacker->getMaxStm());
		toReturn += " put up their guard\n";
		break;
	case 'c':  // if enough stamina, dodge, else mod into 'e'
		change = attacker->getMaxStm() / 5;
		if (attacker->getCurrentStm() >= change)
		{
			attacker->setCurrentStm(attacker->getCurrentStm() - change);
			toReturn += " evaded\n";
		}
		else
		{
			*attackerMod = 'e';
			toReturn += " tried to evade, but failed\n";
		}
		break;
	case 'd':  // restore stamia, mod f
		*attackerMod = 'f';
		toReturn += " raised their weapon\n\t";
	case 'e':	
		toReturn += " restored ";
		change = attacker->getMaxStm() / 5;
		if (attacker->getMaxStm() >= attacker->getCurrentStm() + change)
		{
			attacker->setCurrentStm(attacker->getCurrentStm() + change);
			toReturn += to_string(change) + " stamina\n";
		}
		else
		{
			attacker->setCurrentStm(attacker->getMaxStm());
			toReturn += "all stamina\n";
		}
		break;
	default:
		break;
	}
	return toReturn;
}

CombatManager::CombatManager(shared_ptr<Player> player, shared_ptr<Enemy> enemy) : _player(player) , _enemy(enemy)
{
	_playerMod = 'z';
	_enemyMod = 'z';
	_playerMove = 'z';
	_enemyMove = 'z';
}

CombatManager::~CombatManager()
{
}

string CombatManager::turn(char c)
{
	string toReturn;
	
	if (_playerMod == 'f' && c == 'a') _playerMove = 'f';
	else if (_playerMod != 'z')
	{
		_playerMove = _playerMod;
		_playerMod = 'z';
	}
	else _playerMove = c;
	toReturn += _player->getName() + ruleBook(_player, _playerMove, _enemy, _enemyMove, &_playerMod, &_enemyMod);

	_enemyMove = enemyMoveManager();
	if (_enemyMod == 'f' && _enemyMove == 'a') _enemyMove = 'f';
	else if (_enemyMod != 'z')
	{
		_enemyMove = _enemyMod;
		_enemyMod = 'z';
	}
	toReturn += _enemy->getName() + ruleBook( _enemy, _enemyMove, _player, _playerMove,&_enemyMod ,&_playerMod);

	if (_playerMod == 's') _playerMove = 's';
	if (_playerMove == 's')
	{
		toReturn += _player->getName() + " was staggered!\n";
		toReturn += ruleBook(_enemy, _enemyMove, _player, _playerMove, &_enemyMod, &_playerMod);
	}
	
	return toReturn;
}
