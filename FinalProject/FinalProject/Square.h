#pragma once
#include "Combatant.h"
#include "Enemy.h"
#include "Boss.h"
#include <string>
#include <memory>

class Square
{
	private:
		std::string information = "";
		std::shared_ptr<Combatant> occupant;
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
		void setOccupant(int type);
		void setOccupant(Boss boss);
		void setLevel(int _level) { level = _level; }
		void setNorth() { canMoveNorth = true; }
		void setSouth() { canMoveSouth = true; }
		void setWest() { canMoveWest = true; }
		void setEast() { canMoveEast = true; }
		void setAltar() { isAltar = true; }
		void setChasm() { isChasm = true; }
		std::shared_ptr<Combatant> getOccupant() { return occupant; }
		bool getNorth() { return canMoveNorth; }
		bool getSouth() { return canMoveSouth; }
		bool getWest() { return canMoveWest;}
		bool getEast() { return canMoveEast; }
		bool getAltar() { return isAltar; }
		bool getChasm() { return isChasm; }
};