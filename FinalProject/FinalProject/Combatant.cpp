#include "Combatant.h"



Combatant::Combatant()
{
}


Combatant::~Combatant()
{
}

bool Combatant::isDead()
{
	if (_currentVit <= 0)
	{
		_currentVit = 0;
		_isDead = true;
	}
	else
	{
		_isDead = false;
	}
	return _isDead;
}
