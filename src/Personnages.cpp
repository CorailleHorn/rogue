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
		int randomiser = rand(1,3);
		switch (randomiser) {
			case 1:

				break;
			case 2:
				break;
			case 3:
				break;
		}
		sprite = "a";
	}

	Ennemi::~Ennemi() {

	}

	void Ennemi::deplacement() {

	}
