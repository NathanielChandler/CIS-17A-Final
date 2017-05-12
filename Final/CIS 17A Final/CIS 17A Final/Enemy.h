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

	int getMovesetSize() { return _moveset.size(); };

	string getMoveset(int selection);
	string getName() { return _name; };
};

