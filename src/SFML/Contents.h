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
    Contents();
    ~Contents();

    Animation* getJ_anim(AnimPerso d);
    Animation* getE_anim(AnimPerso d);


    sf::Texture* tJeu;
    sf::Texture* tHero[3];
    sf::Texture* tEnnemi[12];
    sf::SoundBuffer* sJeu[8];
    sf::Font* font;
    AnimPerso* anim_Joueur;
    AnimPerso* anim_Ennemie;
};

#endif
