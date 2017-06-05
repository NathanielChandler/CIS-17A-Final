#include"Square.h"
/*This is also bad buuuuut...  ¯\_(*v*)_/¯ */
//#include <iostream>
// NEIN! No IOSTREAM!
using namespace std;

string Square::GenerateDescription()
{
	string toReturn;
	toReturn += "This room has... \n";
	if (isChasm == true)
	{
		toReturn += "     - an endless chasm\n";
	}
	if (isAltar)
	{
		toReturn += "     - a beautiful altar\n";
	}
	if (canMoveNorth)
		toReturn += "     - a path to the north\n";

	if (canMoveSouth)
		toReturn += "     - a path to the south\n";

	if (canMoveWest)
		toReturn += "     - a path to the west\n";

	if (canMoveEast)
		toReturn += "     - a path to the east\n";

	return toReturn;
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
