#ifndef _CONTENTS_H_
#define _CONTENTS_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimationSprite.h"

class Contents {
  public:
    Contents();
    ~Contents();

    AnimationSprite* getJ_anim(char d);
    AnimationSprite* getE_anim(char d);

  private:
    sf::Texture* tJeu;
    sf::Texture* tHero[3];
    sf::Texture* tEnnemi[6];
    sf::SoundBuffer* sJeu[8];
    sf::Font* font;
    AnimPerso* anim_Joueur;
    AnimPerso* anim_Ennemie;
};

struct AnimPerso {
  AnimationSprite idle;
  AnimationSprite haut;
  AnimationSprite bas;
  AnimationSprite gauche;
  AnimationSprite droite;
}

#endif
