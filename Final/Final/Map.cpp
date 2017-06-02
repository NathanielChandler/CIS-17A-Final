#include "Map.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void Map::CreateMap()
{
	string value;
	cellValues.open("CellData.txt");
	while (!cellValues.eof())
	{
		getline(cellValues, value, ',');
		int num = atoi(value.c_str()); //value = 45 
		_map[num].level = 1;

		//cout << value << endl; // Prints our STRING.
	}
	cellValues.close();
	system("pause");


}
