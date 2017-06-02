#include "Enemy.h"
#include <exception>

//lvl(1-4) dictates movesets, stats, and currency payouts
//type(0-1) dictates type of currency paid out (0 = AUD, 1 = AMD) and certain stats
Enemy::Enemy(int lvl, int type)
{
	if (type < 0 || type > 1)
	{
		throw domain_error("Invalid int Type");
	}
	if (lvl <= 0 || lvl > 4)
	{
		throw domain_error("Invalid int Lvl");
	}

	_tag = "enemy";

	setMaxVit(10 * lvl);
	setMaxStm(10 * lvl);
	resetStats();

	setAtk((2 + type) * lvl);
	setDef((3 - type) * lvl);

	switch (lvl)
	{
	case 1:	_name += "Trifling";	break;
	case 2:	_name += "Mutilated";	break;
	case 3:	_name += "Ravenous";	break;
	case 4:	_name += "Colossal";	break;
	}

	if (type == 0)
	{
		setAud(10 * lvl * lvl * lvl * lvl);
		_name += " Automation";
	}
	else
	{
		setAmd(10 * lvl * lvl * lvl * lvl);
		_name += " Animation";
	}

	//Moveset: a = attack, b = guard, c = evade, d = stance, e = strafe
	switch (lvl)
	{
	case 4:
		_moveset.push_back("eedaaa");
	case 3:
		_moveset.push_back("becda");
	case 2:
		_moveset.push_back("ecda");
		_moveset.push_back("bbda");
	case 1:
		_moveset.push_back("eba");
		_moveset.push_back("bbb");
		_moveset.push_back("cda");
	}
}


Enemy::~Enemy()
{
}

string Enemy::getMoveset(int selection)
{
	if (selection < 0 || selection >= _moveset.size())
	{
		throw domain_error("Invalid int selection");
	}
		
	return _moveset[selection];
}
