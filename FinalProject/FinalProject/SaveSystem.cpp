#include "SaveSystem.h" 
#include "Combatant.h"
#include <vector>
#include <iostream>	
#include <string>





std::string SaveSystem::retrieveSaveData(std::string name)
{
	std::string filename = name + ".txt";

	std::ifstream saveFiles(filename);
	saveFiles.open(filename);


	while (!saveFiles.eof())
	{
		//find filename here 
		std::string fileData;
		saveFiles >> fileData;
		cout << fileData << endl;
	}
	return std::string();
}

void SaveSystem::addNewSaveFile(Combatant name, std::string filename, std::vector<std::string> files)
{
	//take in save file name 
	// add to vector 

	filename = filename + ".txt";
	ofstream newFile;
	newFile.open(filename);
	newFile << "Name: " + filename << endl;
	newFile << "Vitality: " << name.getCurrentVit() << "/" << name.getMaxVit() << endl;
	newFile << "Stamina: " <<name.getCurrentStm() << "/" << name.getMaxStm() << endl;
	newFile << "Attack: " << name.getAtk() << endl;
	newFile << "Defense: " << name.getDef() << endl;

	files.push_back(filename);

}

SaveSystem::SaveSystem()
{
}


SaveSystem::~SaveSystem()
{
}