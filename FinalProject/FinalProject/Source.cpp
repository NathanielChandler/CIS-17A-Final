#include <iostream>
#include "SaveSystem.h"
#include "Combatant.h"
#include <string>
#include <vector>

using namespace std; 
int main() // DONT ADD TO MAIN, KEEP IN SAVESYSTEM BRANCH
{
	Combatant newPlayer;
	string name; // files name 

	cout << "Enter your save file name";
	cin >> name;
	newPlayer.setAtk(150);
	newPlayer.setDef(50);
	newPlayer.setMaxVit(100);
	newPlayer.setCurrentVit(50);
	newPlayer.setMaxStm(500);
	newPlayer.setCurrentStm(20);
	vector<string> saveFiles;
	SaveSystem save;

	save.addNewSaveFile(newPlayer, name, saveFiles);
	save.retrieveSaveData(name);

	return 0;
}