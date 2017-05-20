#pragma once
#include <string>

class Square
{
	public:
		std::string information = "";
		int level = 0;
		bool canMoveNorth = false;
		bool canMoveEast = false;
		bool canMoveSouth = false;
		bool canMoveWest = false;
		bool isAltar = false;
		bool isChasm = false;
		std::string GenerateDescription();
	




};
