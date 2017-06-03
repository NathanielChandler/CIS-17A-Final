#include "CombatManager.h"
#include <random>
#include <time.h>


void CombatManager::getEnemyMoveset()
{
	if (isBossFight) _enemyMoveset = _enemy->getMoveset(0);
	else
	{
		int size = _enemy->getMovesetSize();
		srand(time(NULL));
		int selection = rand() % size;
		_enemyMoveset = _enemy->getMoveset(selection);
	}
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
	//boss list: 1 - Pontiff Void, 2 - Sentinal Viaduct, 3 - Great Belfry Daemon, 4 - Mog
	/*unique moves:			g, h, i, j - Windups
							k - Rise into air
							l - Slams into the earth
	*/
	switch (attack)
	{
	case 'g': 
		toReturn += " murmurs null chantings\n";
		break;
	case 'h':
		toReturn += " takes an arched stance\n";
		break;
	case 'i':
		toReturn += " rings out a shriek\n";
		break;
	case 'j':
		toReturn += " draws upon the ether of its forefathers";
		break;
	case 'k':
		toReturn += " rose into the air\n";
		break;
	case 's':
		toReturn += " was staggered!\n";
		break;
	case 'f':
		damageMod++;
		*attackerMod = 'z';
	case 'l':
	case 'a':
		if (attacker->getCurrentStm() >= attacker->getAtk())							// checks if there's enough stamina
		{
			if(attack == 'l') toReturn += " slammed into the ground\n\t";
			else toReturn += " attacked\n\t";
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
			case 'k':
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
		else
		{
			toReturn +=" tried to attack, but failed!\n";
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

CombatManager::CombatManager(shared_ptr<Player> player, shared_ptr<Combatant> enemy) : _player(player) , _enemy(enemy)
{
	if (_enemy->getTag() == "boss") isBossFight = true;
	else isBossFight = false;
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

	_playerMove = c;
	if (c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e') _playerMove = 'e';
	else if (_playerMod == 'f' && c == 'a') _playerMove = 'f';
	else if (_playerMod != 'z' &&_playerMod != 'f')
	{
		_playerMove = _playerMod;
		_playerMod = 'z';
	}
	toReturn += _player->getName() + ruleBook(_player, _playerMove, _enemy, _enemyMove, &_playerMod, &_enemyMod);

	if (_enemy->isDead() == false)
	{
		_enemyMove = enemyMoveManager();
		if (_enemyMod == 'f' && _enemyMove == 'a') _enemyMove = 'f';
		else if (_enemyMod != 'z' &&_enemyMod != 'f')
		{
			_enemyMove = _enemyMod;
			_enemyMod = 'z';
		}

		toReturn += _enemy->getName() + ruleBook(_enemy, _enemyMove, _player, _playerMove, &_enemyMod, &_playerMod);

		if (_playerMod == 's' && _player->isDead() == false)
		{
			turn('e');
		}
	}
	return toReturn;
}
