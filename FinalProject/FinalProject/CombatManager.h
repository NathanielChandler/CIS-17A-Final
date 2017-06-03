#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Boss.h"
#include <memory>
class CombatManager
{
private:
	bool isBossFight;
	char _playerMod;
	char _enemyMod;
	char _playerMove;
	char _enemyMove;
	shared_ptr<Player> _player;
	shared_ptr<Combatant> _enemy;
	string _enemyMoveset;
	void getEnemyMoveset();
	char enemyMoveManager();
	string ruleBook(shared_ptr<Combatant> attacker, char attack, shared_ptr<Combatant> defender,
		char lastmove, char* attackerMod, char* defenderMod);
public:
	CombatManager(shared_ptr<Player> player, shared_ptr<Combatant> enemy);
	~CombatManager();
	string turn(char c);
};

