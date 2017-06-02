#include"Square.h"
/*This is also bad buuuuut...  ¯\_(*v*)_/¯ */
#include <iostream>
using namespace std;

void Square::GenerateDescription()
{
	cout << endl << "This room has... " << endl;
	if (isChasm == true)
	{
		cout << "     - an endless chasm" << endl;
	}
	if (isAltar)
	{
		cout << "     - a beautiful altar" << endl;
	}
	if (canMoveNorth)
		cout << "     - a path to the north" << endl;

	if (canMoveSouth)
		cout << "     - a path to the south" << endl;

	if (canMoveWest)
		cout << "     - a path to the west" << endl;;

	if (canMoveEast)
		cout << "     - a path to the east" << endl;

	cout << endl;
}

void Square::setOccupant(int type)
{
	if (level > 0 && level < 5)
	{

		occupant = std::make_shared<Enemy> (level, type);

	}
}

void Square::setOccupant(Boss boss)
{
	occupant = std::make_shared<Boss> (boss);
}
