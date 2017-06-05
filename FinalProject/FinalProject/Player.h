#pragma once
#include "Combatant.h"
class Player : public Combatant
{
private:
	 //Square currentLocation;
public:
	Player(string name) { _name = name; };
	~Player();
	string getName() { return _name; };
	void setName(string name) { _name = name; };
};

