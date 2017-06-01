#include <iostream>
#include "SaveSystem.h"
#include "Combatant.h"
#include "Player.h"
#include <string>
#include <vector>

using namespace std; 
int main() // DONT ADD TO MAIN, KEEP IN SAVESYSTEM BRANCH
{
	
	string name; // files name 
	cout << "Enter your save file name" << endl;
	cin >> name;
	Player newPlayer(name);
	newPlayer.setAtk(150);
	newPlayer.setDef(50);
	newPlayer.setMaxVit(100);
	newPlayer.setCurrentVit(50);
	newPlayer.setMaxStm(500);
	newPlayer.setCurrentStm(20);
	newPlayer.setAmd(50);
	newPlayer.setAud(100);

	vector<string> saveFiles;
	saveFiles.push_back(name);
	SaveSystem save;

	save.addNewSaveFile(newPlayer, name, saveFiles);

	newPlayer.setAtk(50);
	newPlayer.setDef(100);
	save.retrieveSaveData(newPlayer);
	
	cout << newPlayer.getAtk() << endl;

	return 0;
}