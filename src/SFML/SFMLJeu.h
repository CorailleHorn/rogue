#ifndef _JEU_H_
#define _JEU_H_

#include "Map.h"
#include "Contents.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void Init(Hero* h, Contents* content, Map* m, std::vector<Ennemi*> ennemis, std::vector<AnimatedSprite> tEnnemis, std::vector<sf::Vector2f> movementE);
void Boucle(Hero *h);
void Detruit(Contents* content, Map* m, std::vector<Ennemi*> ennemis, std::vector<AnimatedSprite> tEnnemis, std::vector<sf::Vector2f> movementE);
void ajoutTexture(Contents* content, Map* m, sf::Sprite tab[90][90]);

#endif
