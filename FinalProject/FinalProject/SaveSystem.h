#pragma once 
#include <vector> 
#include <fstream> 
#include "Combatant.h"
#include "Player.h"
#include "Map.h"

class SaveSystem
{
	private:
		std::vector<std::string>_fileName;
	
	public:
		std::ifstream saveFiles;
		Player retrieveSaveData(std::string name, Map dungeon);
		std::vector<std::string> getfilenames(std::vector<std::string> fileName); //to retrieve save file vector 
		void addNewSaveFile(Combatant x, std::string filename, std::vector<std::string> files, Map _dungeon);
		SaveSystem() {};
		~SaveSystem() {};
};