#ifndef PERSONNAGES_H
#define PERSONNAGES_H

#include <iostream>

class Personnage {
	public:
		Personnage();
		virtual ~Personnage();
		virtual void lvUp() = 0;
		virtual void deplacement() = 0;
		virtual void combat();
		void affichage();
		void setAtk();
		void setDef();
		void setPv();
		int getAtk();
		int getDef();
		int getPv();
		int getLv();

	protected:
		int atk, def, pv, lv;
		char sprite;
};


class Hero: public Personnage {
	public:
		Hero();
		virtual ~Hero();
		virtual void lvUp();
		virtual void deplacement();
		void setName();
	protected:
		std::string name;
};


class Ennemi: public Personnage {
	public:
		Ennemi();
		virtual ~Ennemi();
		virtual void lvUp();
		virtual void deplacement();
};

#endif
