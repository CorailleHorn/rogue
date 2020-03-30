#include "Personnages.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include "Room.h"

using namespace std;

	Personnage::Personnage() {
		atk = def = pv = lv = x = y = 1;
	}

	Personnage::~Personnage() {}

	int Personnage::combat(Personnage* p) {
		if((p->getX() == x-1) || (p->getX() == x+1)
		|| (p->getY() == y-1) || (p->getY() == y+1))
			p->degat(atk);
		return 0;
	}

	int Personnage::degat(const int &atkA) {
		int d = ((atkA - def) + 1);
		if(d >= 0)
			pv -= d;
		return 0;
	}

	int Personnage::affichage() {
		cout << sprite << endl;
		return 0;
	}
/*
	bool Personnage::positionValide (int x, int y) {
		return ((x>r->getX0()) && (x<r->getX1()) && (y>r->getY0()) && (y<r->getY1()));
	}
*/
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

	int Personnage::getX() const {
		return x;
	}

	int Personnage::getY() const {
		return y;
	}

	Hero::Hero() {
		atk = def = pv = 10;
		lv = x = y = 1;
		sprite = 'H';
    name = "";
	}

	Hero::Hero(string sname) {
		atk = def = pv = 10;
		lv = x = y = 1;
		sprite = 'H';
		name = sname;
	}

	Hero::~Hero() {}

	int Hero::lvUp() {
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
												lv--;
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
																		lv--;
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
																		lv--;
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
																		lv--;
													}
													break;
								default:
													cout << "Pas de choix possibles disponibles pour cette option, réessayez !" << endl;
													lvUp();
													lv--;
								}
								break;
			default:
								cout << "Pas de choix disponibles pour cette option, réessayez !" << endl;
								lvUp();
								lv--;
			}
			lv++;
			return 0;
		}
/*
	int Hero::Haut() {
		if (positionValide(x, (y+1)))
			y++;
		return 0;
	}


	int Hero::Bas() {
		if (positionValide(x, (y-1)))
			y--;
		return 0;
	}

	int Hero::Gauche() {
		if (positionValide((x-1), y))
			x--;
		return 0;
	}

	int Hero::Droite() {
		if (positionValide((x+1), y))
			x++;
		return 0;
	}

	int Hero::deplacement() {
		char touche;
		if (kbhit())
			touche = getch();
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
		return 0;
	}
*/

	int Hero::setName(string sname) {
			name = sname;
			return 0;
	}

	string Hero::getName() const {
		return name;
	}

	Ennemi::Ennemi() : Ennemi(1) {}

	Ennemi::Ennemi(const int &leveling) {
		lv = leveling;
		int stat = 3 * lv;
		int randomiser = rand() % 3 + 1;
		switch (randomiser) {
			case 1:
				atk = rand() % stat + 5;
				stat -= atk - 5;
				def = rand() % stat + 5;
				stat -= def - 5;
				pv = stat + 5;
				break;
			case 2:
				def = rand() % stat + 5;
				stat -= def - 5;
				pv = rand() % stat + 5;
				stat -= pv - 5;
				atk = stat + 5;
				break;
			case 3:
				pv = rand() % stat + 5;
				stat -= pv - 5;
				atk = rand() % stat + 5;
				stat -= atk - 5;
				def = stat + 5;
				break;
		}
		x = 1;
		y = 2;
		sprite = 'E';
	}

	Ennemi::~Ennemi() {}
/*
	int Ennemi::deplacement(const Hero* h) {
		if(h->getX() < x && positionValide((x+1), y))
			x++;
		if(h->getX() > x && positionValide((x-1), y))
			x--;
		if(h->getY() < y && positionValide(x, (y+1)))
			y++;
		if(h->getY() > y && positionValide(x, (y-1)))
			y--;
		return 0;
	}
*/
	int Ennemi::combat(Hero* h) {
		if((h->getX() == x-1) || (h->getX() == x+1)
		|| (h->getY() == y-1) || (h->getY() == y+1))
			h->degat(atk);
		return 0;
	}
