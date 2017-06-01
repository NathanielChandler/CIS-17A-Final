#pragma once
#include "Enemy.h"
class Boss : public Combatant
{
private:
	string _moveset;
public:
	Boss(int selection);
	~Boss();

	string getMoveset() { return _moveset; };
	string getName() { return _name; };
};

