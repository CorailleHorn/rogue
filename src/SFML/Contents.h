#ifndef _CONTENTS_H_
#define _CONTENTS_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimatedSprite.h"

struct AnimPerso {
  Animation idleG;
  Animation walkG;
  Animation atkG;
  Animation degatG;
  Animation mortG;
  Animation idleD;
  Animation walkD;
  Animation atkD;
  Animation degatD;
  Animation mortD;
};

class Contents {
  public:
    Contents(); //Constructeur de Contents, charge toutes les data (sons, textures, font)
    ~Contents(); //Destructeur de Contents, detruit toutes les data

    sf::Texture* tJeu;
    sf::Texture* tHero[3];
    sf::Texture* tEnnemi[12];
    sf::SoundBuffer* sJeu[8];
    sf::Font* font;
    AnimPerso* anim_Joueur;
    AnimPerso* anim_Ennemie;
};

#endif
