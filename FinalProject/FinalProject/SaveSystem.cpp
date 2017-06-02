#include "SaveSystem.h" 
#include "Combatant.h"
#include <vector>
#include <iostream>	
#include <string>
#include <fstream>

Player SaveSystem::retrieveSaveData(std::string name)
{
	Player _player();
	std::string filename = name + ".txt";

	std::ifstream saveFiles;
	saveFiles.open(filename);
	std::vector<string> lines;

	std::string l;
	while(!saveFiles.eof())
	{
		for (int i = 0; i < 7; i++)
		{
			std::getline(saveFiles, l);
			lines.push_back(l);
		}
	}

	std::vector<int> data;
	for (int i = 1; i < 7; i++)
	{
		data.push_back(std::stoi(lines[i]));
	}

	saveFiles.close();

	_player.setMaxVit(data[0]);
	_player.setMaxStm(data[1]);
	_player.setAtk(data[2]);
	_player.setDef(data[3]);
	_player.setAmd(data[4]);
	_player.setAud(data[5]);
	_player.resetStats();

	return name;
}

std::vector<std::string> SaveSystem::getfilenames(std::vector<std::string>fileName)
{
	return fileName;
}

void SaveSystem::addNewSaveFile(Combatant player, std::string name, std::vector<std::string> files)
{
	/*Take in file and add it to saveFile vector.*/
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
	files.push_back(name);
	newFile.close();
}