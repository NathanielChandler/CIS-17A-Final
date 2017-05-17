#pragma once
#include <map>
#include <string>
#include <fstream>
#include "Square.h"

class Map
{
	private:
		std::map<std::string, Square> map;
		Square _map[100];
		std::ifstream cellValues;
	

	public:
		void CreateMap();
};
