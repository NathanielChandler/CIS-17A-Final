#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Square.h"

/*I know this terrible buuuut...*/
enum Directions { NORTH, SOUTH, WEST, EAST };

class Map
{
	private:
		const int TOTAL = 7;
		Square _map[100];
		Square currentLocation = _map[0];
		int index = 0;
		std::ifstream cellValues;
		std::vector<int> levels;
		std::vector<int> moveNorth;
		std::vector<int> moveSouth;
		std::vector<int> moveWest;
		std::vector<int> moveEast;
		std::vector<int> altar;
		std::vector<int> chasm;
		std::vector<std::string> lines;

	public:
		Map();
		~Map();
		Square* getCurrentLocation() { return currentLocation; }
		void InitMap();
		std::vector<int> Map::ConfigValues(std::string s);
		void move(Directions dir);
};