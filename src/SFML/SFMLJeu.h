#ifndef _JEU_H_
#define _JEU_H_

#include "Map.h"
#include "Contents.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void Init(Hero* h, Contents* content, Map* m, std::vector<Ennemi*> &ennemis, std::vector<AnimatedSprite> &tEnnemis, std::vector<sf::Vector2f> &movementE);
//initialisation de toutes les variables nécessaires pour lancer le jeu

void Boucle(Hero *h);
//Boucle de jeu qui récupere les actions claviers de l'utilisateur pour qu'il puisse jouer, modifie la position et update des variables initialisées juste avant

void Detruit(Contents* content, Map* m, std::vector<Ennemi*> &ennemis, std::vector<AnimatedSprite> &tEnnemis, std::vector<sf::Vector2f> &movementE);
//Destructeur de content qui est appelé a la fin de la boucle pour recommencer l'affichage

void ajoutTexture(Contents* content, Map* m, sf::Sprite tab[90][90]);
//Affiche le sprite a partir de la texture en fonction du numéro sur la map(0: extérieur de la map, 1: les murs, 2: intérieur de la map)

#endif
