#include "Personnages.h"
#include <iostream>
#include <unistd.h>
#include <math.h>

using namespace std;

	Personnage::Personnage() { //Constructeur pour un personnage
		atk = def = pv = lv = x = y = 1;
	}

	Personnage::~Personnage() {}//Destructeur de personnage

	int Personnage::combat(Personnage* p) {//
		if((p->getX() == x-1) || (p->getX() == x+1)
		|| (p->getY() == y-1) || (p->getY() == y+1))
			p->degat(atk);
		return 0;
	}

	int Personnage::degat(const int &atkA) { //permets de définir le nombre de dégats que l'on va mettre au joueur
		int d = ((atkA - def) + 1);
		if(d >= 0)
			pv -= d;
		return 0;
	}

	int Personnage::Haut() {//Déplacement des personnages
		y--;
		return 0;
	}

	int Personnage::Bas() {//Déplacement des personnages
		y++;
		return 0;
	}

	int Personnage::Gauche() {//Déplacement des personnages
		x--;
		return 0;
	}

	int Personnage::Droite() {//Déplacement des personnages
		x++;
		return 0;
	}

	int Personnage::setX(const int &sx) {
		x = sx;
		return 0;
	}

	int Personnage::setY(const int &sy) {
		y = sy;
		return 0;
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

	int Personnage::getX() const {
		return x;
	}

	int Personnage::getY() const {
		return y;
	}

	char Personnage::getSprite() const {
		return sprite;
	}

	Hero::Hero() { //Constructeur du héro
		atk = def = pv = 10;
		lv = x = y = 1;
		sprite = 'H';
    name = "";
	}

	Hero::Hero(string sname) { //Constructeur avec le nom du héro
		atk = def = pv = 10;
		lv = x = y = 1;
		sprite = 'H';
		name = sname;
	}

	Hero::~Hero() {} //Destructeur du héro

	int Hero::lvUp() { //Permets l'augmentation du niveau du joueur ainsi que des ces points d'attaque, de défense et pvs
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
												cout << "Pas de choix possibles disponibles pour cette option, toutes vo stats ont été augmentés de 1 !" << endl;
												atk++;
												def++;
												pv++;
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
																		cout << "Pas de choix disponibles pour cette option, toutes vos stats ont été augmentés de 1 !" << endl;
																		atk++;
																		def++;
																		pv++;
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
																		cout << "Pas de choix disponibles pour cette option, toutes vo stats ont été augmentés de 1 !" << endl;
																		atk++;
																		def++;
																		pv++;
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
																		cout << "Pas de choix disponibles pour cette option, toutes vo stats ont été augmentés de 1 !" << endl;
																		atk++;
																		def++;
																		pv++;
													}
													break;
								default:
													cout << "Pas de choix possibles disponibles pour cette option, toutes vo stats ont été augmentés de 1 !" << endl;
													atk++;
													def++;
													pv++;
								}
								break;
			default:
								cout << "Pas de choix disponibles pour cette option, toutes vo stats ont été augmentés de 1 !" << endl;
								atk++;
								def++;
								pv++;
			}
			lv++;
			return 0;
		}

	int Hero::setName(string sname) {//Définir le nom du joueur
			name = sname;
			return 0;
	}

	string Hero::getName() const {
		return name;
	}

	Ennemi::Ennemi() : Ennemi(1) {} //Constructeur par defaut (Niveau 1)

	Ennemi::Ennemi(const int &leveling) { //Constructeur par niveau de l'ennemi
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

	int Ennemi::update(int h, int b, int g, int d, Personnage* hero) {
		combat(hero);
		if (h == 2 && hero->getY() < y && (hero->getY() != y-1 || hero->getX() != x)) {
			Haut();
			return 1;
		}
		else if (b == 2 && hero->getY() > y && (hero->getY() != y+1 || hero->getX() != x)) {
			Bas();
			return 1;
		}
		else if(g == 2 && hero->getX() < x && (hero->getX() != x-1 || hero->getY() != y)) {
			Gauche();
			return 1;
		}
		else if (d == 2 && hero->getX() > x && (hero->getX() != x+1 || hero->getY() != y)) {
			Droite();
			return 1;
		}
		return 0;
	}
