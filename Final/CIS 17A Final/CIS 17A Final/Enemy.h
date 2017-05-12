#pragma once
#include "Combatant.h"
#include <vector>
class Enemy : public Combatant
{
private:
	vector<string> _moveset;
public:
	Enemy(int lvl,int type);
	~Enemy();
	string getMoveset(int selection);
};

