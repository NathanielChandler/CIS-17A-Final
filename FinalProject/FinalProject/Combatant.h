#pragma once
#include <string>
using namespace std;

class Combatant
{
private:
	int _currentVit; // vit = vitality
	int _maxVit;
	int _currentStm; // stm = stamina
	int _maxStm;
	int _atk;
	int _def;
	int _amd; // animation dregs, the currency to lvl up vit and stamina
	int _aud; // automation dregs, the currency to lvl up attack and defense
	int _mapIndex;
	bool _isDead;

protected:
	string _name;
	string _tag;
public:
	Combatant();
	~Combatant();
	string getTag() { return _tag; };
	string getName() { return _name; };

	void resetStats() { _currentVit = _maxVit; _currentStm = _maxStm; };

	void setCurrentVit(int vit) { _currentVit = vit; };
	void setMaxVit(int vit) { _maxVit = vit; };
	void setCurrentStm(int stm) { _currentStm = stm; };
	void setMaxStm(int stm) { _maxStm = stm; };
	void setAtk(int atk) { _atk = atk; };
	void setDef(int def) { _def = def; };
	void setAmd(int amd) { _amd = amd; };
	void setAud(int aud) { _aud = aud; };
	void setMapPosition(int mapIndex) { _mapIndex = mapIndex; };

	int getCurrentVit() { return _currentVit; };
	int getMaxVit() { return _maxVit; };
	int getCurrentStm() { return _currentStm; };
	int getMaxStm() { return _maxStm; };
	int getAtk() { return _atk; };
	int getDef() { return _def; };
	int getAmd() { return _amd; };
	int getAud() { return _aud; };
	int getMapPosition() { return _mapIndex; }; 
	
	virtual string getMoveset(int meh) { return "null"; };
	virtual int getMovesetSize() { return 1; };
	bool isDead();
};

