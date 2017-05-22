#pragma once
#include <string>

class Square
{
	private:
		std::string information = "";
		int level = 0;
		bool canMoveNorth = false;
		bool canMoveEast = false;
		bool canMoveSouth = false;
		bool canMoveWest = false;
		bool isAltar = false;
		bool isChasm = false;
	public:
		std::string GenerateDescription();
		void setNorth() { canMoveNorth = true; }
		void setSouth() { canMoveSouth = true; }
		void setWest() { canMoveWest = true; }
		void setEast() { canMoveEast = true; }
		void setAltar() { isAltar = true; }
		void setChasm() { isChasm = true; }
	




};
