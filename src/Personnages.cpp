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
		int choix1, choix2;
		cout<<"Vous disposez de 3 points pour augmenter vos statistiques.
		Que décidez vous de faire: "<<endl<<"Mettre 1 point par attribut (tapez 1)
		ou "<<endl<<"Mettre les 3 points dans un attribut unique ? (tapez 2)"<<endl;

		cin>>choix1;

		switch (choix1) {
			case 1:
				cout<<"L'attaque, la défense et les PV ont été augmentés de 1 !"<<endl;
				atk++;
				def++;
				pv++;
			break;

			case 2:
				cout<<"Quel attribut voulez-vous augmenter ? (1=attaque, 2=défense, 3=PV)"<<endl;
				cin>>choix2;
				switch (choix2) {
					case 1:
						cout<<"Votre attaque a été augmenté de 3 !"<<endl;
						atk+=3;
					break;

					case 2:
					cout<<"Votre défense a été augmenté de 3 !"<<endl;
					def+=3;
					break;

					case 3:
					cout<<"Vos PV ont été augmenté de 3 !"<<endl;
						PV+=3;
					break;
					default: cout<<"Pas de choix possibles disponibles pour cette option, réessayez !"<<endl;

				}
			break;

			default:
				cout<<"Pas de choix disponibles pour cette option, réessayez !"<<endl;
		}
	}


	void Hero::deplacement() {

	}

	void Hero::setName(string sname) {
			name = sname;
	}


	Ennemi::Ennemi(int leveling) {
		int stat = 30;
		int randstat;
		int randomiser = rand(1,3);
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
		sprite = "a";
	}

	Ennemi::~Ennemi() {

	}

	void Ennemi::deplacement() {

	}
