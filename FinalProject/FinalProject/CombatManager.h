#pragma once
#include "Enemy.h"
#include "Player.h"
#include <memory>
class CombatManager
{
private:
	char playerMod;
	char enemyMod;
	shared_ptr<Player> _player;
	shared_ptr<Enemy> _enemy;
	string _enemyMoveset;
	void getEnemyMoveset();
	string enemyMoveManager();
	string ruleBook(shared_ptr<Combatant> attacker, char attack, shared_ptr<Combatant> defender,
		char lastmove, char* attackerMod, char* defenderMod);
public:
	CombatManager(shared_ptr<Player> player, shared_ptr<Enemy> enemy);
	~CombatManager();
	string turn(char c);
};
