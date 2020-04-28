#ifndef _JEU_H_
#define _JEU_H_

#include "Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


void Boucle(Hero *h);
void Detruit(Map *m);
int ajoutTexture(Sprite* tab[100][100]);

#endif
