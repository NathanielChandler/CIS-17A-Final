#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Square.h"

class Map
{
	private:
		Square _map[100];
		std::ifstream cellValues;
	

	public:
		void InitMap();
		std::vector<int> Map::ConfigValues(std::string s);
};
