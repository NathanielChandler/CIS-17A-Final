#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Square.h"

class Map
{
	private:
		const int TOTAL = 7;
		Square* _map[100];
		Square currentLocation;
		std::ifstream cellValues;
		std::vector<int> levels;
		std::vector<int> moveNorth;
		std::vector<int> moveSouth;
		std::vector<int> moveWest;
		std::vector<int> moveEast;
		std::vector<int> altar;
		std::vector<int> chasm;
		std::vector<string> lines;

	public:
		void InitMap();
		std::vector<int> Map::ConfigValues(std::string s);
		void move();
};
