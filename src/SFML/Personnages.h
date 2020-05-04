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
		Personnage(); //Constructeur pour un personnage, initialise tous les champs
		virtual ~Personnage(); //Destructeur de personnage
		int combat(Personnage* p); //Affecte les points de degats a p si il est à proximité et appele la fonction degat de p si c'est le cas
		int degat(const int &atkA, bool gauche = true); //Inflige les degats au personnage
		void pvUpdate(); //Mets a jour la barre de vie
		int idle(); //Définit la sprite si le personnage ne bouge pas
		int haut(); //Fonction de déplacement du personnage, et affecte la sprite associée
		int bas(); //Fonction de déplacement du personnage, et affecte la sprite associée
		int gauche(); //Fonction de déplacement du personnage, et affecte la sprite associée
		int droite(); //Fonction de déplacement du personnage, et affecte la sprite associée
		int setX(const int &sx); //Mutateur pour fixer le x du personnage
		int setY(const int &sy); //Mutateur pour fixer le y du personnage
		int setSprites(AnimPerso* s_template, sf::Texture *barre_pv, sf::Texture *texturePV); //Fixe les sprites initiales
		int PvPos(); //Definition de la barre de vie au dessus des personnages
		int movePv(sf::Vector2f pos); //Permets le deplacement de la barre de vie pour les personnages
		int getAtk() const; //Accesseur
		int getDef() const; //Accesseur
		int getPv() const; //Accesseur
		int getLv() const; //Accesseur
		int getX() const; //Accesseur
		int getY() const; //Accesseur
		sf::Sprite getPvBarre() const; //Accesseur
		sf::Sprite getCurrentPV() const; //Accesseur
		Animation getSprite() const; //Accesseur
	protected:
		int atk, def, pv, pvmax, lv, x, y;
		AnimPerso* sprites;
		Animation* currentSprite;
		sf::Sprite *currentPV, *barrePV;
};


class Hero : public Personnage {
	public:
		Hero(); //Constructeur du hero
		Hero(std::string sname); //Constructeur du hero avec le nom du hero en parametres
		~Hero(); //Destructeur du hero (appelant simplement le Destructeur de Personnage)
		int lvUp(); //Permets l'augmentation du niveau du joueur ainsi que des ces points d'attaque, de défense et pvs
		int setName(std::string sname); //Mutateur pour le nom du hero
		std::string getName() const; //Accesseur
	protected:
		std::string name;
};


class Ennemi : public Personnage {
	public:
		Ennemi(); //Constructeur par defaut (Niveau 1)
		Ennemi(const int &leveling); //Constructeur par niveau de l'ennemi, en passant le niveau en parametres
		sf::Vector2f update(int h, int b, int g, int d, Personnage* hero); // """" IA de l'ennemi """" lui permettant de chercher hero et de l'attaquer
		~Ennemi(); //Destructeur de l'ennemi (appelant simplement le Destructeur de Personnage)
};

#endif
