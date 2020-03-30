#ifndef _PERSONNAGES_H_
#define _PERSONNAGES_H_

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <assert.h>
#include "Room.h"

class Personnage {
	public:
		Personnage();
		virtual ~Personnage();
		//virtual int deplacement();
		int combat(Personnage* p);
		int degat(const int &atkA);
		int affichage();
		//bool positionValide(int x, int y);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int getX() const;
		int getY() const;
	protected:
		int atk, def, pv, lv, x, y;
		char sprite;
};


class Hero : public Personnage {
	public:
		Hero();
		Hero(std::string sname);
		~Hero();
		int lvUp();
		//int deplacement();
		int setName(std::string sname);
		std::string getName() const;
		//int Haut();
		//int Droite();
		//int Gauche();
		//int Bas();
	protected:
		std::string name;
};


class Ennemi : public Personnage {
	public:
		Ennemi();
		Ennemi(const int &leveling);
		~Ennemi();
		//int deplacement(const Hero* h);
};

#endif
