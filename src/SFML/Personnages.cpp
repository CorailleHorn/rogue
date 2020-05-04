#include "Personnages.h"
#include <iostream>
#include <unistd.h>
#include <math.h>

using namespace std;
using namespace sf;

	Personnage::Personnage() {
		atk = def = pv = pvmax = lv = x = y = 1;
		sprites = new AnimPerso;
		currentSprite = new Animation;
		barrePV = new Sprite;
		currentPV = new Sprite;
	}

	Personnage::~Personnage() {
		delete barrePV;
		delete currentPV;
	}

	int Personnage::combat(Personnage* p) {
		bool degat = false;
		if(p->getX() == x+1 && p->getY() == y) {
			currentSprite = &sprites->atkD;
			degat = true;
		}
		if((p->getX() == x-1 && p->getY() == y)
		|| (p->getX() == x && (p->getY() == y-1 || p->getY() == y+1))) {
			currentSprite = &sprites->atkG;
			degat = true;
		}
		if(degat) {
			p->degat(atk);
			return 1;
		}
		return 0;
	}

	int Personnage::degat(const int &atkA, bool gauche) {
		int d = (((rand() % atkA) - (def/2)) + 1);
		if(d > 0) {
			if(pv - d < 0) {
				currentSprite = &sprites->mortG;
				pv = 0;
			}
			else {
				currentSprite = &sprites->degatD;
				pv -= d;
			}
			pvUpdate();
		}
		return 0;
	}

	void Personnage::pvUpdate() {
		currentPV->setScale((float)pv/pvmax,1.f);
	}

	int Personnage::idle() {
		currentSprite = &sprites->idleD;
		return 0;
	}

	int Personnage::haut() {
		currentSprite = &sprites->walkD;
		y--;
		return 0;
	}

	int Personnage::bas() {
		currentSprite = &sprites->walkD;
		y++;
		return 0;
	}

	int Personnage::gauche() {
		currentSprite = &sprites->walkG;
		x--;
		return 0;
	}

	int Personnage::droite() {
		currentSprite = &sprites->walkD;
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


	int Personnage::setSprites(AnimPerso* s_template, sf::Texture *barre_pv, sf::Texture *texturePV) {
		sprites = s_template;
		barrePV->setTexture(*barre_pv);
		currentPV->setTexture(*texturePV);
		currentSprite = &sprites->idleD;
		return 0;
	}

	int Personnage::PvPos() {
		Vector2f pos = Vector2f((x*32)-16,(y*32)-16);
		barrePV->setPosition(pos);
		currentPV->setPosition(Vector2f((pos.x + 14.f), pos.y));
		return 0;
	}

	int Personnage::movePv(Vector2f pos) {
		barrePV->move(pos);
		currentPV->move(pos);
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

	Sprite Personnage::getPvBarre() const {
		return *barrePV;
	}

	Sprite Personnage::getCurrentPV() const {
		return *currentPV;
	}

	Animation Personnage::getSprite() const {
		return *currentSprite;
	}

	Hero::Hero() { //Constructeur du héro
		atk = def = pv = pvmax = 10;
		lv = x = y = 1;
    name = "";
		currentSprite = new Animation;
	}

	Hero::Hero(string sname) {
		atk = def = pv = 10;
		lv = x = y = 1;
		name = sname;
		currentSprite = new Animation;
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
		pvmax = pv;
		x = 1;
		y = 2;
		currentSprite = new Animation;
	}

	sf::Vector2f Ennemi::update(int h, int b, int g, int d, Personnage* hero) {
		combat(hero);
		if (h == 2 && hero->getY() < y && (hero->getY() != y-1 || hero->getX() != x)) {
			haut();
			return Vector2f(0,-1);
		}
		else if (b == 2 && hero->getY() > y && (hero->getY() != y+1 || hero->getX() != x)) {
			bas();
			return Vector2f(0,1);
		}
		else if(g == 2 && hero->getX() < x && (hero->getX() != x-1 || hero->getY() != y)) {
			gauche();
			return Vector2f(-1,0);
		}
		else if (d == 2 && hero->getX() > x && (hero->getX() != x+1 || hero->getY() != y)) {
			droite();
			return Vector2f(1,0);
		}
		return Vector2f(0,0);
	}

	Ennemi::~Ennemi() {}
