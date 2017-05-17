#pragma once 
#include <vector> 
#include <fstream> 
class SaveSystem
{
private:

	std::vector<std::string>_fileName;
	std::ifstream saveFiles;

public:

	std::string retrieveSaveData(std::string name);
	void addNewSaveFile(std::string name);
	SaveSystem();
	~SaveSystem();
};