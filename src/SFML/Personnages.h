#ifndef _PERSONNAGES_H_
#define _PERSONNAGES_H_

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Contents.h"


class Personnage {
	public:
		Personnage();
		virtual ~Personnage();
		int combat(Personnage* p);
		int degat(const int &atkA);
		int idle();
		int haut();
		int bas();
		int gauche();
		int droite();
		int setX(const int &sx);
		int setY(const int &sy);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int getX() const;
		int getY() const;
		void setSprites(AnimPerso* s_template);
		Animation* getSprite() const;
	protected:
		int atk, def, pv, lv, x, y;
		AnimPerso* sprites;
		Animation* currentSprite;
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
