#include "Personnages.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include "Room.h"

using namespace std;

	Personnage::Personnage() {}

	Personnage::~Personnage() {
		delete r;
	}

	void Personnage::combat() {}

	void Personnage::affichage() {}

	bool Personnage::positionValide (int x, int y) {
		return ((r->slc) && (x>r->X0) && (x<r->X1) && (y>r->Y0) && (y<r->Y1));
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
		atk = def = pv = lv = x = y = 0;
		sprite = 'H';
    name = "";
	}

	Hero::~Hero() {}

	void Hero::lvUp() {
		int choix[4];

		cout << "Vous disposez de 3 points pour augmenter vos statistiques." <<	endl
			<< "Que décidez vous de faire: " << endl
			<< "Mettre 1 point par attribut (tapez 1)" << endl
			<< "ou" << endl
			<< "Mettre les 3 points dans un attribut unique (tapez 2)" << endl
			<< "ou" << endl
			<< "Mettre 2 points dans un attribut et 1 point dans un autre ? (tapez 3)" << endl;
		cin >> choix[0];
		switch(choix[0]) {
			case 1:
							cout << "L'attaque, la défense et les PV ont été augmentés de 1 !" << endl;
							atk++;
							def++;
							pv++;
							break;
			case 2:
							cout << "Quel attribut voulez-vous augmenter ? (1=attaque, 2=défense, 3=PV)" << endl;
							cin >> choix[1];
							switch(choix[1]) {
								case 1:
												cout << "Votre attaque a été augmenté de 3 !" << endl;
												atk += 3;
												break;
								case 2:
												cout << "Votre défense a été augmenté de 3 !" << endl;
												def += 3;
												break;
								case 3:
												cout << "Vos PV ont été augmenté de 3 !" << endl;
												pv += 3;
												break;
								default:
												cout << "Pas de choix possibles disponibles pour cette option, réessayez !" << endl;
												lvUp();
							}
							break;
			case 3:
							cout << "Quel attribut voulez-vous augmenter de 2 ? (1=attaque, 2=défense, 3=PV)" << endl;
							cin >> choix[2];
							switch(choix[2]) {
								case 1:
													cout << "Votre attaque a été augmenté de 2 !" << endl;
													atk += 2;
													cout << "Quel attribut voulez-vous augmenter de 1 ? (1=défense, 2=PV)" << endl;
													cin >> choix[3];
													switch (choix[3]) {
														case 1:
																		cout << "Votre défense a été augmenté de 1 !" << endl;
																		def++;
																		break;
														case 2:
																		cout << "Vos PV ont été augmentés de 1 !" << endl;
																		pv++;
																		break;
														default:
																		cout << "Pas de choix disponibles pour cette option, réessayez !" << endl;
																		lvUp();
													}
													break;
								case 2:
													cout << "Votre défense a été augmenté de 2 !" << endl;
													def += 2;
													cout << "Quel attribut voulez-vous augmenter de 1 ? (1=attaque, 2=PV)" << endl;
													cin >> choix[3];
													switch (choix[3]) {
														case 1:
																		cout << "Votre attaque a été augmenté de 1 !" << endl;
																		atk++;
																		break;
														case 2:
																		cout << "Vos PV ont été augmentés de 1 !" << endl;
																		pv++;
																		break;
														default:
																		cout << "Pas de choix disponibles pour cette option, réessayez !" << endl;
																		lvUp();
													}
													break;
								case 3:
													cout << "Vos PV ont été augmenté de 2 !" << endl;
													pv += 2;
													cout << "Quel attribut voulez-vous augmenter de 1 ? (1=attaque, 2=défense)" << endl;
													cin >> choix[3];
													switch (choix[3]) {
														case 1:
																		cout << "Votre attaque a été augmenté de 1 !" << endl;
																		atk++;
																		break;
														case 2:
																		cout << "Votre défense a été augmenté de 1 !" << endl;
																		def++;
																		break;
														default:
																		cout << "Pas de choix disponibles pour cette option, réessayez !" << endl;
																		lvUp();
													}
													break;
								default:
													cout << "Pas de choix possibles disponibles pour cette option, réessayez !" << endl;
													lvUp();
								}
								break;
			default:
								cout << "Pas de choix disponibles pour cette option, réessayez !" << endl;
								lvUp();
			}
		}

	void Hero::Haut(){
		if (positionValide(x, ++y))
			y++;
	}


	void Hero::Bas(){
		if (positionValide(x, --y))
			--y;
	}

	void Hero::Gauche(){
		if (positionValide(--x, y))
			--x;
	}

	void Hero::Droite(){
		if (positionValide(++x, y))
			++x;
	}

	void Hero::deplacement() {
		char touche;
		cin>>touche;
		switch (touche) {
			case 'z':
						Haut();
						break;
			case 's':
						Bas();
						break;
			case 'q':
						Gauche();
						break;
			case 'd':
						Droite();
						break;
		}
	}

	void Hero::setName(string sname) {
			name = sname;
	}


	Ennemi::Ennemi(const int &leveling) {
		int stat = 30 * leveling;
		int randomiser = rand() % 4 + 1;
		switch (randomiser) {
			case 1:
				atk = rand() % stat-2 + 1;
				stat -= atk;
				def = rand() % stat-1 + 1;
				stat -= def;
				pv = stat;
				break;
			case 2:
				def = rand() % stat-2 + 1;
				stat -= def;
				pv = rand() % stat-1 + 1;
				stat -= pv;
				atk = stat;
				break;
			case 3:
				pv = rand() % stat-2 + 1;
				stat -= pv;
				atk = rand() % stat-1 + 1;
				stat -= atk;
				def = stat;
				break;
		}
		sprite = 'E';
	}

	Ennemi::~Ennemi() {}

	void Ennemi::deplacement(Hero h) {
		/*if(h.getX() < x && positionValide(--x, y))
		if(h.getX() > x && positionValide(++x, y))
		if(h.getY() < y && positionValide(x, --y))
		if(h.getY() > y && positionValide(x, ++y))*/
	}
