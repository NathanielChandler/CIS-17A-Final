#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SaveSystem.h" 
#include "Combatant.h"

Player SaveSystem::retrieveSaveData(std::string name, Map dungeon)
{
	Player _player(name);
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

	//_player.isDead = false;
	_player.setMaxVit(data[0]);
	_player.setMaxStm(data[1]);
	_player.setAtk(data[2]);
	_player.setDef(data[3]);
	_player.setAmd(data[4]);
	_player.setAud(data[5]);
	_player.resetStats();
	dungeon.setCurrentLocation(data[7]);

	return _player;
}

std::vector<std::string> SaveSystem::getfilenames(std::vector<std::string>fileName)
{
	return fileName;
}

void SaveSystem::addNewSaveFile(Combatant player, std::string name, std::vector<std::string> files, Map _dungeon)
{
	ofstream newFile;
	name = name + ".txt";	
	newFile.open(name);
	newFile << name << endl;
	newFile << player.getCurrentVit() << endl;
	newFile << player.getMaxVit() << endl;
	newFile << player.getCurrentStm() << endl;
	newFile << player.getMaxStm() << endl;
	newFile << player.getAtk() << endl;
	newFile << player.getDef() << endl;
	newFile << player.getAmd() << endl;
	newFile << player.getAud() << endl;
	newFile << _dungeon.getCurrentLocationIndex();
	files.push_back(name);
	newFile.close();
}