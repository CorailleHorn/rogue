#ifndef _CONTENTS_H_
#define _CONTENTS_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Contents {
  sf::Texture *tJeu;
  sf::Texture *tHero[3];
  sf::Texture *tEnnemi[6];
  sf::SoundBuffer *sJeu[8];
  sf::Font *font;
};

int InitContents(Contents* c);
int DeleteContents(Contents* c);

#endif
