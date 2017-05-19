#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

void Map::InitMap()
{
	/*Reading in the lines and storing them into an vectors.*/
	cellValues.open("CellData.txt");
	while (!cellValues.eof())
	{
		string l;
		for (int i = 0; i < TOTAL; i++)
		{
			getline(cellValues, l, '\n');
			lines.push_back(l);
		}
	}
	cellValues.close();

	/*Parsing the lines and storing them into their respective vectors.*/
	levels = ConfigValues(lines[0]);
	moveNorth = ConfigValues(lines[1]);
	moveSouth = ConfigValues(lines[2]);
	moveWest = ConfigValues(lines[3]);
	moveEast = ConfigValues(lines[4]);
	altar = ConfigValues(lines[5]);
	chasm = ConfigValues(lines[6]);

	/*Creating the rooms and setting their variables based off of the arrays.*/
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < moveNorth.size(); i++)
		{
			if (i == moveNorth[j])
				_map[i]->canMoveNorth = true;
		}
		for (int j = 0; j < moveSouth.size(); i++)
		{
			if (i == moveSouth[j])
				_map[i]->canMoveSouth = true;
		}
		for (int j = 0; j < moveWest.size(); i++)
		{
			if (i == moveWest[j])
				_map[i]->canMoveWest = true;
		}
		for (int j = 0; j < moveEast.size(); i++)
		{
			if (i == moveEast[j])
				_map[i]->canMoveEast = true;
		}
	}
}

vector<int> Map::ConfigValues(std::string s)
{
	vector<int> temp;
	stringstream strStream(s);
	string token;

	while (getline(strStream, token, ','))
	{
		int num = atoi(token.c_str());
		temp.push_back(num);
	}

	return temp;
}