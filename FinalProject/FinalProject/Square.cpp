#include"Square.h"
using namespace std;

string Square::GenerateDescription()
{
	string output = "This room has a";
	if (isChasm)
	{
		output += "n endless chasm.";
	}
	else if (isAltar)
	{
		output += " beautiful  altar with " + '\n';
	}
	else
	{
		if (canMoveNorth)
			output += "a path to the north" + '\n';
		if (canMoveSouth)
			output += "a path to the south" + '\n';
		if (canMoveWest)
			output += "a path to the west" + '\n';
		if (canMoveEast)
			output += "a path to the east" + '\n';
	}
}
