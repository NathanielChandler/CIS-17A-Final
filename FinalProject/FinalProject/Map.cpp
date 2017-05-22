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
		for (int j = 0; j < moveNorth.size(); j++)
		{
			if (i == moveNorth[j])
				_map[i]->setNorth();
		}
		for (int j = 0; j < moveSouth.size(); j++)
		{
			if (i == moveSouth[j])
				_map[i]->setSouth();
		}
		for (int j = 0; j < moveWest.size(); j++)
		{
			if (i == moveWest[j])
				_map[i]->setWest();
		}
		for (int j = 0; j < moveEast.size(); j++)
		{
			if (i == moveEast[j])
				_map[i]->setEast();
		}
		for (int j = 0; j < altar.size(); j++)
		{
			if (i == altar[j])
				_map[i]->setAltar();
		}
		for (int j = 0; j < chasm.size(); j++)
		{
			if (i == chasm[j])
				_map[i]->setChasm();
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

void Map::move(string dir)
{
	
}
