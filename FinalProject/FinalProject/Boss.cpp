#include "Boss.h"



Boss::Boss(int selection)
{
	//boss list: 1 - Pontiff Void, 2 - Sentinal Viaduct, 3 - Great Belfry Daemon, 4 - Mog
	/*unique moves:      g, h, i, j - Windups
						 k - Rise into air
						 l - Slams into the earth

	move structure: intro - verse - chorus - verse - chours - intro - chorus
	*/
	if(selection < 1 || selection > 4) throw domain_error("Invalid int Selection");

	int mod;
	string intro, verse, chorus;
	switch (selection)
	{
	case 1: 
		_name = "Pontiff Void";
		mod = 5;
		intro = "gaeeg";
		verse = "ageeg";
		chorus = "agaga";
	case 2:
		_name = "Sentinal Viaduct";
		mod = 10;
		intro = "eebha";
		verse = "behas";
		chorus = "baaas";
	case 3:
		_name = "Great Belfry Daemon";
		mod = 15;
		intro = "iaekl";
		verse = "eiaei";
		chorus = "eklkl";
	case 4:
		_name = "Mog";
		mod = 20;
		intro = "ejkla";
		verse = "ebeja";
		chorus = "ebjkla";
	}
	_moveset = intro + verse + chorus + verse + chorus + intro + chorus;

	setMaxVit(15 * mod);
	setMaxStm(100 * mod);
	resetStats();
	setAtk(3 * mod);
	setDef(5 * mod);
	setAmd(80 * mod * mod);
	setAud(80 * mod * mod);
}


Boss::~Boss()
{
}
