#pragma once 
#include <vector> 
#include <fstream> 
#include "Combatant.h"
#include "Player.h"
class SaveSystem
{
private:

	std::vector<std::string>_fileName;
	

public:

	std::ifstream saveFiles;
	Player retrieveSaveData(Player name);
	std::vector<std::string> getfilenames; //to retrieve save file vector 

	void addNewSaveFile(Combatant x, std::string filename, std::vector<std::string>);
	SaveSystem();
	~SaveSystem();
};