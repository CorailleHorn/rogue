#ifndef _JEU_H_
#define _JEU_H_

#include "Map.h"
#include "Contents.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


void Boucle(Hero *h);
void Detruit(Map *m);
void ajoutTexture(Contents* content, Map* m, sf::Sprite tab[90][90]);

#endif
