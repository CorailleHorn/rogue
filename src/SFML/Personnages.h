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
		int degat(const int &atkA, bool gauche = true);
		void pvUpdate();
		int idle();
		int haut();
		int bas();
		int gauche();
		int droite();
		int setX(const int &sx);
		int setY(const int &sy);
		int setSprites(AnimPerso* s_template, sf::Texture *barre_pv, sf::Texture *texturePV);
		int PvPos();
		int movePv(sf::Vector2f pos);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int getX() const;
		int getY() const;
		sf::Sprite getPvBarre() const;
		sf::Sprite getCurrentPV() const;
		Animation getSprite() const;
	protected:
		int atk, def, pv, pvmax, lv, x, y;
		AnimPerso* sprites;
		Animation* currentSprite;
		sf::Sprite *currentPV, *barrePV;
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
		sf::Vector2f update(int h, int b, int g, int d, Personnage* hero);
		~Ennemi();
};

#endif
