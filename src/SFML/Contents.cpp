#include "Contents.h"

using namespace std;
using namespace sf;

  Contents::Contents() {

      //New
  tJeu = new Texture;
  for (int i = 0; i < 3; i++)
    tHero[i] = new Texture;
  for (int i = 0; i < 6; i++)
    tEnnemi[i] = new Texture;
  for (int i = 0; i < 8; i++)
    sJeu[i] = new SoundBuffer;
  font = new Font;
  anim_Joueur = new AnimPerso;
  anim_Ennemie = new AnimPerso;

      //Image
  if (!tJeu->loadFromFile("../data/img/Dungeon_Tileset.png"))
    cerr << "Ton image charges pas batard" << '\n';

  if (!tHero[0]->loadFromFile("../data/img/Adventurer_Sprite_Sheet.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tHero[1]->loadFromFile("../data/img/health_bar/health_bar_decoration.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tHero[2]->loadFromFile("../data/img/health_bar/health_bar.png"))
    cerr << "Ton image charges pas batard" << '\n';

  if (!tEnnemi[0]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Idle.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[1]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Walk.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[2]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Attack.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[3]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Hit.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[4]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Dead.png"))
    cerr << "Ton image charges pas batard" << '\n';

      //Son

  if (!sJeu[0]->loadFromFile("../data/sounds/Cancel.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[1]->loadFromFile("../data/sounds/Select.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[2]->loadFromFile("../data/sounds/Confirm.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[3]->loadFromFile("../data/sounds/Text.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[4]->loadFromFile("../data/sounds/Hit.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[5]->loadFromFile("../data/sounds/point.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[6]->loadFromFile("../data/sounds/lvUp.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!sJeu[7]->loadFromFile("../data/sounds/death.wav"))
    cerr << "Ton son charges pas batard" << '\n';

      //Font

  if (!font->loadFromFile("../data/ttf/Silver.ttf"))
    cerr << "Ton font charges pas batard" << '\n';

      //Animation Joueur Gauche
  anim_Joueur->idleG.setSpriteSheet(*tHero[0]);
  anim_Joueur->idleG.addFrame(sf::IntRect(2*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(3*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(4*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(5*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(6*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(7*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(8*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(9*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(10*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(11*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(12*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(0*32, 0, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(1*32, 0, 32, 32));

  anim_Joueur->walkG.setSpriteSheet(*tHero[0]);
  anim_Joueur->walkG.addFrame(sf::IntRect(0*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(1*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(2*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(3*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(4*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(5*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(6*32, 1*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(7*32, 1*32, 32, 32));

  anim_Joueur->atkG.setSpriteSheet(*tHero[0]);
  anim_Joueur->atkG.addFrame(sf::IntRect(0*32, 4*32, 32, 32));
  anim_Joueur->atkG.addFrame(sf::IntRect(1*32, 4*32, 32, 32));
  anim_Joueur->atkG.addFrame(sf::IntRect(2*32, 4*32, 32, 32));

  anim_Joueur->degatG.setSpriteSheet(*tHero[0]);
  anim_Joueur->degatG.addFrame(sf::IntRect(1*32, 6*32, 32, 32));
  anim_Joueur->degatG.addFrame(sf::IntRect(2*32, 6*32, 32, 32));
  anim_Joueur->degatG.addFrame(sf::IntRect(3*32, 6*32, 32, 32));
  anim_Joueur->degatG.addFrame(sf::IntRect(0*32, 6*32, 32, 32));

  anim_Joueur->mortG.setSpriteSheet(*tHero[0]);
  anim_Joueur->mortG.addFrame(sf::IntRect(1*32, 7*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(2*32, 7*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(3*32, 7*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(4*32, 7*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(5*32, 7*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(6*32, 7*32, 32, 32));

    //Animation Joueur Droit
  anim_Joueur->idleD.setSpriteSheet(*tHero[0]);
  anim_Joueur->idleD.addFrame(sf::IntRect(2*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(3*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(4*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(5*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(6*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(7*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(8*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(9*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(10*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(11*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(12*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(0*32, 8*32, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(1*32, 8*32, 32, 32));

  anim_Joueur->walkD.setSpriteSheet(*tHero[0]);
  anim_Joueur->walkD.addFrame(sf::IntRect(0*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(1*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(2*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(3*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(4*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(5*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(6*32, 9*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(7*32, 9*32, 32, 32));

  anim_Joueur->atkD.setSpriteSheet(*tHero[0]);
  anim_Joueur->atkD.addFrame(sf::IntRect(0*32, 12*32, 32, 32));
  anim_Joueur->atkD.addFrame(sf::IntRect(1*32, 12*32, 32, 32));
  anim_Joueur->atkD.addFrame(sf::IntRect(2*32, 12*32, 32, 32));

  anim_Joueur->degatD.setSpriteSheet(*tHero[0]);
  anim_Joueur->degatD.addFrame(sf::IntRect(1*32, 14*32, 32, 32));
  anim_Joueur->degatD.addFrame(sf::IntRect(2*32, 14*32, 32, 32));
  anim_Joueur->degatD.addFrame(sf::IntRect(3*32, 14*32, 32, 32));
  anim_Joueur->degatD.addFrame(sf::IntRect(0*32, 14*32, 32, 32));

  anim_Joueur->mortD.setSpriteSheet(*tHero[0]);
  anim_Joueur->mortD.addFrame(sf::IntRect(1*32, 15*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(2*32, 15*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(3*32, 15*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(4*32, 15*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(5*32, 15*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(6*32, 15*32, 32, 32));

    //Animation Ennemi
  anim_Ennemie->idleG.setSpriteSheet(*tEnnemi[0]);
  anim_Ennemie->idleG.addFrame(sf::IntRect(0*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(1*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(2*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(3*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(4*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(5*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(6*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(7*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(8*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(9*32, 0, 22, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(10*32, 0, 22, 32));

  anim_Ennemie->walkG.setSpriteSheet(*tEnnemi[1]);
  anim_Ennemie->walkG.addFrame(sf::IntRect(0*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(1*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(2*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(3*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(4*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(5*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(6*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(7*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(8*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(9*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(10*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(11*32, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(12*32, 0, 22, 32));

  anim_Ennemie->atkG.setSpriteSheet(*tEnnemi[2]);
  anim_Ennemie->atkG.addFrame(sf::IntRect(4*32, 0, 40, 37));
  anim_Ennemie->atkG.addFrame(sf::IntRect(5*32, 0, 40, 37));
  anim_Ennemie->atkG.addFrame(sf::IntRect(6*32, 0, 40, 37));
  anim_Ennemie->atkG.addFrame(sf::IntRect(7*32, 0, 40, 37));

  anim_Ennemie->degatG.setSpriteSheet(*tEnnemi[3]);
  anim_Ennemie->degatG.addFrame(sf::IntRect(1*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(2*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(3*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(4*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(5*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(6*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(7*32, 0, 32, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(0*32, 0, 32, 32));

  anim_Ennemie->mortG.setSpriteSheet(*tEnnemi[4]);
  anim_Ennemie->mortG.addFrame(sf::IntRect(0*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(1*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(2*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(3*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(4*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(5*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(6*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(7*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(8*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(9*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(10*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(11*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(12*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(13*32, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(14*32, 0, 33, 32));
}

  Contents::~Contents() {
  delete tJeu;
  for (int i = 0; i < 3; i++)
    delete tHero[i];
  for (int i = 0; i < 6; i++)
    delete tEnnemi[i];
  for (int i = 0; i < 8; i++)
    delete sJeu[i];
  delete font;
  delete anim_Joueur;
  delete anim_Ennemie;
}
