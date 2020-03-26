#ifndef _PERSONNAGES_H_
#define _PERSONNAGES_H_

#include <iostream>
#include <unistd.h>
#include <math.h>
#include "Room.h"

class Personnage {
	public:
		Personnage();
		virtual ~Personnage();
		virtual void deplacement() = 0;
		virtual void combat() = 0;
		void degat(Personnage* p);
		void affichage();
		bool positionValide(int x, int y);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int getX() const;
		int getY() const;
	protected:
		int atk, def, pv, lv, x, y;
		char sprite;
		Room *r;
};


class Hero: public Personnage {
	public:
		Hero();
		virtual ~Hero();
		void lvUp();
		virtual void deplacement();
		virtual void combat(Ennemi* e);
		void setName(std::string sname);
		void Haut();
		void Droite();
		void Gauche();
		void Bas();
	protected:
		std::string name;
};


class Ennemi: public Personnage {
	public:
		Ennemi(const int &leveling);
		virtual ~Ennemi();
		virtual void deplacement(const Hero* h);
		virtual void combat(Hero* h);
};

#endif
