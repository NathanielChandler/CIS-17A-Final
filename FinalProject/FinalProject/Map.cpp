#include "Map.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void Map::InitMap()
{
	string value;
	/* These arrays hold the index of cells that have a specific attribute. */
	int enemyCount[100];
	//int level[];
	//int moveNorth[];
	//int moveSouth[];


	cellValues.open("CellData.txt");


	if (!cellValues.eof())
	{
		if (!getline(cellValues, value,':'))
		{
			//error
		}
		else
		{
			if (value == "ENEMYCOUNT")
			{
				SetCellValues(enemyCount, 1);
			}
		}
	}
	while (!cellValues.eof())
	{
		getline(cellValues, value);
		int num = atoi(value.c_str());

		cout << num;
	}
	cellValues.close();
	system("pause");


}

void Map::SetCellValues(int values[], int attribute)
{
	switch (attribute)
	{
		case 1: //Enemy Count
			break;
		case "LEVEL":
			break;
		case "MOVENORTH":
			break;
		case "MOVESOUTH":
			break;
		case "MOVEWEST":
			break;
		case "MOVEEAST":
			break;

	}
	
}