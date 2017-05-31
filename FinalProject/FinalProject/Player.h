#pragma once
#include "Combatant.h"
class Player : public Combatant
{
private:
	 //Square currentLocation;
public:
	std::string getName() { return _name; };


	Player(std::string name) { _name = name; };
	~Player();
};

