#include "Personnages.h"

	Personnage::Personnage() {
		atk = 0;
		def = 0;
		pv = 0;
		lv = 0;
	}

	Personnage::~Personnage() {

	}

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

	}

	Hero::~Hero() {

	}

	void Hero::lvUp() {

	}

	void Hero::deplacement() {

	}

	void Hero::setName() {

	}


	Ennemi::Ennemi() {

	}

	Ennemi::~Ennemi() {

	}

	Ennemi::lvUp() {

	}

	Ennemi::deplacement() {

	}
