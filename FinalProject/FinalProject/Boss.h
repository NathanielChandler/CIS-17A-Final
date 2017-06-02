#pragma once
#include "Combatant.h"
class Boss : public Combatant
{
private:
	string _moveset;
public:
	Boss(int selection);
	~Boss();

	string getMoveset() { return _moveset; };
};

