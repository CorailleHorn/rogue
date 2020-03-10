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
		void setAtk(int x);
		void setDef(int x);
		void setPv(int x);
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;

	protected:
		int atk, def, pv, lv, x, y;
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
