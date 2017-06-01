#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iterator>
using namespace std;

Map::Map() {}
Map::~Map() {}
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

	/*Filling the array with rooms.*/
	Square temp;
	for (int i = 0; i < 100; i++)
	{
		_map[i] = temp;
	}

	/*Setting room variables based off of the arrays.*/
	for (int i = 0; i < 100; i++)
	{
		/*Setting the level.*/
		_map[i].setLevel(levels[i]);
		if (moveNorth[i] == 1)
		{
			_map[i].setNorth();
		}
		if (moveSouth[i] == 1)
		{
			_map[i].setSouth();
		}
		if (moveWest[i] == 1)
		{
			_map[i].setWest();
		}
		if (moveEast[i] == 1)
		{
			_map[i].setEast();
		}
		if (altar[i] == 1)
		{
			_map[i].setAltar();
		}
		if (chasm[i] == 1)
		{
			_map[i].setChasm();
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

void Map::move(Directions dir)
{
	switch (dir)
	{
		case NORTH:
			index -= 10;
			if (currentLocation.getNorth() == true && index >= 0)
			{
				currentLocation = _map[index];
			}
			break;
		case SOUTH:
			index += 10;
			if (currentLocation.getSouth() == true && index <= 99)
			{
				currentLocation = _map[index];
			}
			break;
		case WEST:
			index -= 1;
			if (currentLocation.getWest() == true && index >= 0)
			{
				currentLocation = _map[index];
			}
			break;
		case EAST:
			index -= 1;
			if (currentLocation.getEast() == true && index <= 99)
			{
				currentLocation = _map[index];
			}
			break;
	}
}