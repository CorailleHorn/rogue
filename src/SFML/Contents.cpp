#include "Contents.h"

using namespace std;
using namespace sf;

Contents::Contents() {

      //New
  tJeu = new Texture;
  for (int i = 0; i < 3; i++)
    tHero[i] = new Texture;
  for (int i = 0; i < 12; i++)
    tEnnemi[i] = new Texture;
  for (int i = 0; i < 8; i++)
    sJeu[i] = new SoundBuffer;
  font = new Font;
  anim_Joueur = new AnimPerso;
  anim_Ennemie = new AnimPerso;

      //Image
  if (!tJeu->loadFromFile("../data/img/Dungeon_Tileset.png"))
    cerr << "Erreur dans le chargement de la texture du donjon" << '\n';
  if (!tHero[0]->loadFromFile("../data/img/Adventurer_Sprite_Sheet.png"))
    cerr << "Erreur dans le chargement de la texture du hero" << '\n';
  if (!tHero[1]->loadFromFile("../data/img/health_bar/health_bar_decoration.png"))
    cerr << "Erreur dans le chargement de la barre de vie du hero" << '\n';
  if (!tHero[2]->loadFromFile("../data/img/health_bar/health_bar.png"))
    cerr << "Erreur dans le chargement du contenu de la barre de vie du hero" << '\n';
  if (!tEnnemi[0]->loadFromFile("../data/img/Skeleton/Skeleton_Idle.png"))
    cerr << "Erreur dans le chargement de la texture immobile des ennemis" << '\n';
  if (!tEnnemi[1]->loadFromFile("../data/img/Skeleton/Skeleton_Walk.png"))
    cerr << "Erreur dans le chargement de la texture d'avancement des ennemis" << '\n';
  if (!tEnnemi[2]->loadFromFile("../data/img/Skeleton/Skeleton_Attack.png"))
    cerr << "Erreur dans le chargement de la texture d'attaque des ennemis" << '\n';
  if (!tEnnemi[3]->loadFromFile("../data/img/Skeleton/Skeleton_Hit.png"))
    cerr << "Erreur dans le chargement de la texture de degats des ennemis" << '\n';
  if (!tEnnemi[4]->loadFromFile("../data/img/Skeleton/Skeleton_Dead.png"))
    cerr << "Erreur dans le chargement de la texture de mort des ennemis" << '\n';
  if (!tEnnemi[5]->loadFromFile("../data/img/Skeleton/Skeleton_IdleD.png"))
    cerr << "Erreur dans le chargement de la texture immobile des ennemis" << '\n';
  if (!tEnnemi[6]->loadFromFile("../data/img/Skeleton/Skeleton_WalkD.png"))
    cerr << "Erreur dans le chargement de la texture d'avancement des ennemis" << '\n';
  if (!tEnnemi[7]->loadFromFile("../data/img/Skeleton/Skeleton_AttackD.png"))
    cerr << "Erreur dans le chargement de la texture d'attaque des ennemis" << '\n';
  if (!tEnnemi[8]->loadFromFile("../data/img/Skeleton/Skeleton_HitD.png"))
    cerr << "Erreur dans le chargement de la texture de degats des ennemis" << '\n';
  if (!tEnnemi[9]->loadFromFile("../data/img/Skeleton/Skeleton_DeadD.png"))
    cerr << "Erreur dans le chargement de la texture de mort des ennemis" << '\n';
  if (!tEnnemi[10]->loadFromFile("../data/img/health_bar/health_bar_decoration.png"))
    cerr << "Erreur dans le chargement de la texture de la barre de vie des ennemis" << '\n';
  if (!tEnnemi[11]->loadFromFile("../data/img/health_bar/health_bar.png"))
    cerr << "Erreur dans le chargement de la texture du contenu de la barre de vie des ennemis" << '\n';

      //Son

  if (!sJeu[0]->loadFromFile("../data/sounds/Cancel.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[1]->loadFromFile("../data/sounds/Select.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[2]->loadFromFile("../data/sounds/Confirm.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[3]->loadFromFile("../data/sounds/Text.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[4]->loadFromFile("../data/sounds/Hit.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[5]->loadFromFile("../data/sounds/point.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[6]->loadFromFile("../data/sounds/lvUp.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';
  if (!sJeu[7]->loadFromFile("../data/sounds/death.wav"))
    cerr << "Erreur lors du chargement d'un son" << '\n';

      //Font

  if (!font->loadFromFile("../data/ttf/Silver.ttf"))
    cerr << "Erreur lors du chargement du font" << '\n';

      //Animation Joueur Gauche
  anim_Joueur->idleD.setSpriteSheet(tHero[0]);
  anim_Joueur->idleD.addFrame(sf::IntRect(2*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(3*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(4*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(5*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(6*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(7*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(8*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(9*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(10*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(11*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(12*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(0*32, 0, 32, 32));
  anim_Joueur->idleD.addFrame(sf::IntRect(1*32, 0, 32, 32));

  anim_Joueur->walkD.setSpriteSheet(tHero[0]);
  anim_Joueur->walkD.addFrame(sf::IntRect(0*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(1*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(2*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(3*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(4*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(5*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(6*32, 1*32, 32, 32));
  anim_Joueur->walkD.addFrame(sf::IntRect(7*32, 1*32, 32, 32));

  anim_Joueur->atkD.setSpriteSheet(tHero[0]);
  anim_Joueur->atkD.addFrame(sf::IntRect(0*32, 4*32, 32, 32));
  anim_Joueur->atkD.addFrame(sf::IntRect(1*32, 4*32, 32, 32));
  anim_Joueur->atkD.addFrame(sf::IntRect(2*32, 4*32, 32, 32));

  anim_Joueur->degatD.setSpriteSheet(tHero[0]);
  anim_Joueur->degatD.addFrame(sf::IntRect(1*32, 6*32, 32, 32));
  anim_Joueur->degatD.addFrame(sf::IntRect(2*32, 6*32, 32, 32));
  anim_Joueur->degatD.addFrame(sf::IntRect(3*32, 6*32, 32, 32));
  anim_Joueur->degatD.addFrame(sf::IntRect(0*32, 6*32, 32, 32));

  anim_Joueur->mortD.setSpriteSheet(tHero[0]);
  anim_Joueur->mortD.addFrame(sf::IntRect(1*32, 7*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(2*32, 7*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(3*32, 7*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(4*32, 7*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(5*32, 7*32, 32, 32));
  anim_Joueur->mortD.addFrame(sf::IntRect(6*32, 7*32, 32, 32));

    //Animation Joueur Gauche
  anim_Joueur->idleG.setSpriteSheet(tHero[0]);
  anim_Joueur->idleG.addFrame(sf::IntRect(2*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(3*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(4*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(5*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(6*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(7*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(8*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(9*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(10*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(11*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(12*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(0*32, 8*32, 32, 32));
  anim_Joueur->idleG.addFrame(sf::IntRect(1*32, 8*32, 32, 32));

  anim_Joueur->walkG.setSpriteSheet(tHero[0]);
  anim_Joueur->walkG.addFrame(sf::IntRect(0*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(1*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(2*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(3*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(4*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(5*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(6*32, 9*32, 32, 32));
  anim_Joueur->walkG.addFrame(sf::IntRect(7*32, 9*32, 32, 32));

  anim_Joueur->atkG.setSpriteSheet(tHero[0]);
  anim_Joueur->atkG.addFrame(sf::IntRect(0*32, 12*32, 32, 32));
  anim_Joueur->atkG.addFrame(sf::IntRect(1*32, 12*32, 32, 32));
  anim_Joueur->atkG.addFrame(sf::IntRect(2*32, 12*32, 32, 32));

  anim_Joueur->degatG.setSpriteSheet(tHero[0]);
  anim_Joueur->degatG.addFrame(sf::IntRect(1*32, 14*32, 32, 32));
  anim_Joueur->degatG.addFrame(sf::IntRect(2*32, 14*32, 32, 32));
  anim_Joueur->degatG.addFrame(sf::IntRect(3*32, 14*32, 32, 32));
  anim_Joueur->degatG.addFrame(sf::IntRect(0*32, 14*32, 32, 32));

  anim_Joueur->mortG.setSpriteSheet(tHero[0]);
  anim_Joueur->mortG.addFrame(sf::IntRect(1*32, 15*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(2*32, 15*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(3*32, 15*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(4*32, 15*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(5*32, 15*32, 32, 32));
  anim_Joueur->mortG.addFrame(sf::IntRect(6*32, 15*32, 32, 32));

    //Animation Ennemi
  anim_Ennemie->idleD.setSpriteSheet(tEnnemi[0]);
  anim_Ennemie->idleD.addFrame(sf::IntRect(0*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(1*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(2*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(3*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(4*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(5*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(6*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(7*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(8*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(9*24, 0, 24, 32));
  anim_Ennemie->idleD.addFrame(sf::IntRect(10*24, 0, 24, 32));

  anim_Ennemie->walkD.setSpriteSheet(tEnnemi[1]);
  anim_Ennemie->walkD.addFrame(sf::IntRect(0*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(1*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(2*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(3*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(4*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(5*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(6*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(7*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(8*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(9*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(10*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(11*22, 0, 22, 32));
  anim_Ennemie->walkD.addFrame(sf::IntRect(12*22, 0, 22, 32));

  anim_Ennemie->atkD.setSpriteSheet(tEnnemi[2]);
  anim_Ennemie->atkD.addFrame(sf::IntRect(4*40, 0, 40, 37));
  anim_Ennemie->atkD.addFrame(sf::IntRect(5*40, 0, 40, 37));
  anim_Ennemie->atkD.addFrame(sf::IntRect(6*40, 0, 40, 37));
  anim_Ennemie->atkD.addFrame(sf::IntRect(7*40, 0, 64, 37));

  anim_Ennemie->degatD.setSpriteSheet(tEnnemi[3]);
  anim_Ennemie->degatD.addFrame(sf::IntRect(1*30, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect(2*30, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect(3*30, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect(4*30, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect((5*30)+2, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect((6*30)+2, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect((7*30)+2, 0, 28, 32));
  anim_Ennemie->degatD.addFrame(sf::IntRect(0*30, 0, 28, 32));

  anim_Ennemie->mortD.setSpriteSheet(tEnnemi[4]);
  anim_Ennemie->mortD.addFrame(sf::IntRect(7*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(8*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(9*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(10*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(11*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(12*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(13*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(14*33, 0, 33, 32));

  anim_Ennemie->idleG.setSpriteSheet(tEnnemi[5]);
  anim_Ennemie->idleG.addFrame(sf::IntRect(10*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(9*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(8*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(7*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(6*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(5*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(4*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(3*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(2*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(1*24, 0, 24, 32));
  anim_Ennemie->idleG.addFrame(sf::IntRect(0*24, 0, 24, 32));

  anim_Ennemie->walkG.setSpriteSheet(tEnnemi[6]);
  anim_Ennemie->walkG.addFrame(sf::IntRect(12*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(11*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(10*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(9*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(8*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(7*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(6*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(5*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(4*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(3*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(2*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(1*22, 0, 22, 32));
  anim_Ennemie->walkG.addFrame(sf::IntRect(0*22, 0, 22, 32));


  anim_Ennemie->atkG.setSpriteSheet(tEnnemi[7]);
  anim_Ennemie->atkG.addFrame(sf::IntRect(574, 0, 40, 37));
  anim_Ennemie->atkG.addFrame(sf::IntRect(574-40, 0, 40, 37));
  anim_Ennemie->atkG.addFrame(sf::IntRect(574-80, 0, 40, 37));
  anim_Ennemie->atkG.addFrame(sf::IntRect(430, 0, 40, 37));

  anim_Ennemie->degatG.setSpriteSheet(tEnnemi[8]);
  anim_Ennemie->degatG.addFrame(sf::IntRect(0*30, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect((7*30)+2, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect((6*30)+2, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect((5*30)+2, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(4*30, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(3*30, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(2*30, 0, 28, 32));
  anim_Ennemie->degatG.addFrame(sf::IntRect(1*30, 0, 28, 32));

  anim_Ennemie->mortG.setSpriteSheet(tEnnemi[9]);
  anim_Ennemie->mortG.addFrame(sf::IntRect(7*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(6*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(5*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(4*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(3*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(2*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(1*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(0*33, 0, 33, 32));
}

  Contents::~Contents() {
  delete tJeu;
  for (int i = 0; i < 3; i++)
    delete tHero[i];
  for (int i = 0; i < 12; i++)
    delete tEnnemi[i];
  for (int i = 0; i < 8; i++)
    delete sJeu[i];
  delete font;
  delete anim_Joueur;
  delete anim_Ennemie;
}
