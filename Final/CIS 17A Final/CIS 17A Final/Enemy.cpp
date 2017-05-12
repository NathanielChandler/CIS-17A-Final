#include "Enemy.h"


//lvl(1-4) dictates movesets, stats, and currency payouts
//type(0-1) dictates type of currency paid out (0 = AUD, 1 = AMD) and certain stats
Enemy::Enemy(int lvl, int type)
{
	setMaxVit(10 * lvl);
	setMaxStm(10 * lvl);
	resetStats();

	setAtk((2 + type) * lvl);
	setDef((3 - type) * lvl);

	if (type == 0)
	{
		setAud(10 * lvl * lvl * lvl * lvl);
	}
	else
	{
		setAmd(10 * lvl * lvl * lvl * lvl);
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
	default:;// insert exception thrown
	}
}


Enemy::~Enemy()
{
}

string Enemy::getMoveset(int selection)
{
	if()
	return _moveset[selection--];
}
