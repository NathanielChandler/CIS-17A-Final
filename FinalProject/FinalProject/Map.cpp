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
	//Locations based on enemy types(didn't want to mess with reading in another file at the time)
	int Aud[] = {4,5,6,9,14,15,18,21,22,26,31,32,35,42,55,64,74,76,77,83,84,86,87,88,92,95,97};
	int audSelect = 0;
	int Amd[] = {0,1,10,11,12,29,30,37,38,39,40,47,48,50,52,54,57,59,61,62,68,69,71,79};
	int amdSelect = 0;
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
		//Putting in enemy
		if (i == Aud[audSelect])
		{
			_map[i].setOccupant(0);
			audSelect++;
		}
		else if (i == Amd[amdSelect])
		{
			_map[i].setOccupant(1);
			amdSelect++;
		}
		else
		{
			switch (i) 
			{
			case 2: _map[i].setOccupant(Boss(1)); break;
			case 8: _map[i].setOccupant(Boss(4)); break;
			case 45: _map[i].setOccupant(Boss(2)); break;
			case 78: _map[i].setOccupant(Boss(3)); break;
			}
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
			if (currentLocation->getNorth() == true && index >= 0)
			{
				currentLocation = &_map[index];
			}
			break;
		case SOUTH:
			index += 10;
			if (currentLocation->getSouth() == true && index <= 99)
			{
				currentLocation = &_map[index];
			}
			break;
		case WEST:
			index -= 1;
			if (currentLocation->getWest() == true && index >= 0)
			{
				currentLocation = &_map[index];
			}
			break;
		case EAST:
			index += 1;
			if (currentLocation->getEast() == true && index <= 99)
			{
				currentLocation = &_map[index];
			}
			break;
	}
}

void Map::resetRooms()
{
	for (auto room : _map)
	{
		if (room.getOccupant() != nullptr)
		{
			if (room.getOccupant()->isDead() && room.getOccupant()->getTag() == "enemy")
				room.getOccupant()->resetStats();
		}
	}
}