#include "SaveSystem.h"



std::string SaveSystem::retrieveSaveData(std::string name)
{
	std::string filename = name + ".txt";
	
	std::ifstream saveFiles(filename);

	while (!saveFiles.eof())
	{
		//find filename here 
	}
	return std::string();
}

void SaveSystem::addNewSaveFile(std::string name)
{
}

SaveSystem::SaveSystem()
{
}


SaveSystem::~SaveSystem()
{
}
