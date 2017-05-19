#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

void Map::InitMap()
{
	/*In the text doc, line 1 = level data
	  line 2 = move north data, etc.*/
	vector<int> levels;
	vector<int> moveNorth;
	vector<int> moveSouth;
	vector<int> moveWest;
	vector<int> moveEast;
	vector<int> altar;
	vector<int> chasm;
	vector<string> lines;

	cellValues.open("CellData.txt");
	while (!cellValues.eof())
	{
		string l;
		for (int i = 0; i < 7; i++)
		{
			getline(cellValues, l, '\n');
			lines.push_back(l);
		}
	}

	cellValues.close();

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