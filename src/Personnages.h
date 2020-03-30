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
		int combat(Personnage* p);
		int degat(const int &atkA);
		int setX(const int &sx);
		int setY(const int &sy);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int getX() const;
		int getY() const;
		char getSprite() const;
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
		int setName(std::string sname);
		std::string getName() const;
		int Haut();
		int Bas();
		int Gauche();
		int Droite();
	protected:
		std::string name;
		char touche;
};


class Ennemi : public Personnage {
	public:
		Ennemi();
		Ennemi(const int &leveling);
		~Ennemi();
		int deplacement(const Hero* h);
};

#endif
