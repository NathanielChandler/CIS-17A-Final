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
		Square() {};
		~Square() {};
		void GenerateDescription();
		std::string getInfo();
		void setLevel(int _level) { level = _level; }
		void setNorth() { canMoveNorth = true; }
		void setSouth() { canMoveSouth = true; }
		void setWest() { canMoveWest = true; }
		void setEast() { canMoveEast = true; }
		void setAltar() { isAltar = true; }
		void setChasm() { isChasm = true; }
		bool getNorth() { return canMoveNorth; }
		bool getSouth() { return canMoveSouth; }
		bool getWest() { return canMoveWest;}
		bool getEast() { return canMoveEast; }
		bool getAltar() { return isAltar; }
		bool getChasm() { return isChasm; }
};