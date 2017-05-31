#include "SaveSystem.h" 
#include "Combatant.h"
#include <vector>
#include <iostream>	
#include <string>
#include <fstream>





Player SaveSystem::retrieveSaveData(Player name)
{
	
	std::string filename = name.getName();
	filename += ".txt";

	std::ifstream saveFiles(filename);
	saveFiles.open(filename);
	std::vector<string> lines;

	while (!saveFiles.eof())
	{
	
		string l;
		for (int i = 0; i < 7; i++)
		{
			lines.push_back(l);
		}
		

	}
	std::vector<int> data;

	for (int i = 1; i < 7; i++)
	{

		data.push_back(std::stoi(lines[i]));
		

	}
	saveFiles.close();

	/*Parsing the lines and storing them into their respective vectors.*/
	name.setMaxVit(data[0]);
	name.setMaxStm(data[1]);
	name.setAtk(data[2]);
	name.setDef(data[3]);
	name.setAmd(data[4]);
	name.setAud(data[5]);
	name.resetStats();

	return name;
}

void SaveSystem::addNewSaveFile(Combatant name, std::string filename, std::vector<std::string> files)
{
	//take in save file name 
	// add to vector 

	filename = filename + ".txt";
	ofstream newFile;
	newFile.open(filename);
	newFile << filename << endl;
	newFile << name.getCurrentVit() << endl;
	newFile << name.getMaxVit() << endl;
	newFile << name.getCurrentStm() << endl;
	newFile << name.getMaxStm() << endl;
	newFile << name.getAtk() << endl;
	newFile << name.getDef() << endl;
	newFile << name.getAmd() << endl;
	newFile << name.getAud() << endl;

	files.push_back(filename);
	newFile.close();
}

SaveSystem::SaveSystem()
{
}


SaveSystem::~SaveSystem()
{
}