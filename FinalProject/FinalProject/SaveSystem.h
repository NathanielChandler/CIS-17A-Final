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
		std::vector<std::string> retrieveSaveData(std::string name);
		std::vector<std::string> getfilenames(std::vector<std::string> fileName); //to retrieve save file vector 
		void addNewSaveFile(shared_ptr<Player> player, std::string filename, std::vector<std::string> files, int mapIndex);
		SaveSystem() {};
		~SaveSystem() {};
};