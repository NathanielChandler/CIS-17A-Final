#pragma once
#include "Enemy.h"
#include "Player.h"
#include <memory>
class CombatManager
{
private:
	string _enemyMoveset;
	void getEnemyMoveset();
	string enemyMoveManager();
public:
	CombatManager(shared_ptr<Player> player, shared_ptr<Enemy> enemy);
	~CombatManager();
	string turn(char c);
};

