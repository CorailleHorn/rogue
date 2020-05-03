#include "Contents.h"

using namespace std;
using namespace sf;

  Contents::Contents() {

      //New
  tJeu = new Texture;
  for (int i = 0; i < 3; i++)
    tHero[i] = new Texture;
  for (int i = 0; i < 10; i++)
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

  if (!tEnnemi[0]->loadFromFile("../data/img/Skeleton/Skeleton_Idle.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[1]->loadFromFile("../data/img/Skeleton/Skeleton_Walk.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[2]->loadFromFile("../data/img/Skeleton/Skeleton_Attack.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[3]->loadFromFile("../data/img/Skeleton/Skeleton_Hit.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[4]->loadFromFile("../data/img/Skeleton/Skeleton_Dead.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[5]->loadFromFile("../data/img/Skeleton/Skeleton_IdleD.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[6]->loadFromFile("../data/img/Skeleton/Skeleton_WalkD.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[7]->loadFromFile("../data/img/Skeleton/Skeleton_AttackD.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[8]->loadFromFile("../data/img/Skeleton/Skeleton_HitD.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[9]->loadFromFile("../data/img/Skeleton/Skeleton_DeadD.png"))
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
  anim_Ennemie->mortD.addFrame(sf::IntRect(0*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(1*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(2*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(3*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(4*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(5*33, 0, 33, 32));
  anim_Ennemie->mortD.addFrame(sf::IntRect(6*33, 0, 33, 32));
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
  anim_Ennemie->mortG.addFrame(sf::IntRect(14*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(13*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(12*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(11*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(10*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(9*33, 0, 33, 32));
  anim_Ennemie->mortG.addFrame(sf::IntRect(8*33, 0, 33, 32));
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
  for (int i = 0; i < 5; i++)
    delete tEnnemi[i];
  for (int i = 0; i < 8; i++)
    delete sJeu[i];
  delete font;
  delete anim_Joueur;
  delete anim_Ennemie;
}
/*
int main()
{
    // setup window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(60);

    Contents* c = new Contents;

    Animation* currentAnimation = &(c->anim_Ennemie->idleD);

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.2), true);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));
    sf::Clock frameClock;

    float speed = 80.f;
    bool noKeyWasPressed = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();

        // if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentAnimation = &(c->anim_Ennemie->walkD);
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            currentAnimation = &(c->anim_Ennemie->atkD);
            movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            currentAnimation = &(c->anim_Ennemie->degatD);
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentAnimation = &(c->anim_Ennemie->mortD);
            movement.x += speed;
            noKeyWasPressed = false;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            currentAnimation = &(c->anim_Ennemie->idleD);
        }
        noKeyWasPressed = true;

        // update AnimatedSprite
        animatedSprite.update(frameTime);

        // draw
        window.clear();
        window.draw(animatedSprite);
        window.display();
    }
    delete c;
    return 0;
}
*/
