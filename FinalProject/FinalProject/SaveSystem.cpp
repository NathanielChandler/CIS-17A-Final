#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SaveSystem.h" 
#include "Combatant.h"

std::vector<std::string> SaveSystem::retrieveSaveData(std::string name)
{
	//std::vector<std::string> _player;
	std::string filename = name + ".txt";

	std::ifstream saveFiles;
	saveFiles.open(filename);
	std::vector<string> lines;

	std::string l;
	while(!saveFiles.eof())
	{
		for (int i = 0; i < 8; i++)
		{
			std::getline(saveFiles, l);
			lines.push_back(l);
		}
	}

	std::vector<int> data;
	for (int i = 1; i < 8; i++)
	{
		data.push_back(std::stoi(lines[i]));
	}

	saveFiles.close();

	return lines;
}

std::vector<std::string> SaveSystem::getfilenames(std::vector<std::string>fileName)
{
	return fileName;
}

void SaveSystem::addNewSaveFile(shared_ptr<Player> player, std::string name, std::vector<std::string> files, int mapIndex)
{
	Map dungeon;
	ofstream newFile;
	std::string  saveName= name + ".txt";	
	newFile.open(saveName);
	newFile << name << endl;
	//newFile << player->getCurrentVit() << endl;
	newFile << player->getMaxVit() << endl;
	//newFile << player->getCurrentStm() << endl;
	newFile << player->getMaxStm() << endl;
	newFile << player->getAtk() << endl;
	newFile << player->getDef() << endl;
	newFile << player->getAmd() << endl;
	newFile << player->getAud() << endl;
	newFile << mapIndex;
	files.push_back(saveName);
	newFile.close();
}