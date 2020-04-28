#ifndef _PERSONNAGES_H_
#define _PERSONNAGES_H_

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimationSprite.h"


class Personnage {
	public:
		Personnage();
		virtual ~Personnage();
		int combat(Personnage* p);
		int degat(const int &atkA);
		int Haut();
		int Bas();
		int Gauche();
		int Droite();
		int setX(const int &sx);
		int setY(const int &sy);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int getX() const;
		int getY() const;
		AnimationSprite *getSprite() const;
	protected:
		int atk, def, pv, lv, x, y;
		AnimationSprite* sprite;
};


class Hero : public Personnage {
	public:
		Hero();
		Hero(std::string sname);
		~Hero();
		int lvUp();
		int setName(std::string sname);
		std::string getName() const;
	protected:
		std::string name;
};


class Ennemi : public Personnage {
	public:
		Ennemi();
		Ennemi(const int &leveling);
		~Ennemi();
};

#endif
