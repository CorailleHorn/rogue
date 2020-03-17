#include "Personnages.h"

	Personnage::Personnage() {}

	Personnage::~Personnage() {}

	void Personnage::combat() {

	}

	void Personnage::affichage() {

	}

	void Personnage::setAtk(int x) {
		atk = x;
	}

	void Personnage::setDef(int x) {
		def = x;
	}

	void Personnage::setPv(int x) {
		pv = x;
	}

	int Personnage::getAtk() const {
		return atk;
	}

	int Personnage::getDef() const {
		return def;
	}

	int Personnage::getPv() const {
		return pv;
	}

	int Personnage::getLv() const {
		return lv;
	}


	Hero::Hero() {
		atk = def = pv = lv = 0;
		x = y = 0;
		sprite = "a";
    name = "";
	}

	Hero::~Hero() {}

	void Hero::lvUp() {

	}

	void Hero::deplacement() {

	}

	void Hero::setName(string sname) {
			name = sname;
	}


	Ennemi::Ennemi(int leveling) {
		int stat = 30;
		int randstat;
		int randomiser = rand(1,4);
		switch (randomiser) {
			case 1:
				atk = rand(1,stat-2);
				stat -= atk;
				def = rand(1,stat-1);
				stat -= def;
				pv = stat;
				break;
			case 2:
				def = rand(1,stat-2);
				stat -= def;
				pv = rand(1,stat-1);
				stat -= pv;
				atk = stat;
				break;
			case 3:
				pv = rand(1,stat-2);
				stat -= pv;
				atk = rand(1,stat-1);
				stat -= atk;
				def = stat;
				break;
		}
		sprite = "e";
	}

	Ennemi::~Ennemi() {

	}

	void Ennemi::deplacement() {

	}
