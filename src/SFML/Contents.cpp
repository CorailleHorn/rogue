#include "Contents.h"
#include "SFMLJeu.h"

using namespace std;
using namespace sf;

  Contents() {

  tJeu = new Texture;
  for (int i = 0; i < 3; i++)
    tHero[i] = new Texture;
  for (int i = 0; i < 6; i++)
    tEnnemi[i] = new Texture;
  for (int i = 0; i < 8; i++)
    sJeu[i] = new SoundBuffer;
  font = new Font;

      //Image
  if (!tJeu->loadFromFile("../data/img/Dungeon_Tileset.png"))
    cerr << "Ton image charges pas batard" << '\n';

  if (!tHero[0]->loadFromFile("../data/img/Adventurer_Sprite_Sheet.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tHero[1]->loadFromFile("../data/img/health_bar/health_bar_decoration.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tHero[2]->loadFromFile("../data/img/health_bar/health_bar.png"))
    cerr << "Ton image charges pas batard" << '\n';

  if (!tEnnemi[0]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_React.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[1]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Idle.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[2]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Walk.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[3]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Attack.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[4]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Hit.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!tEnnemi[5]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Dead.png"))
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

  return 1;
}

  ~Contents() {
  delete tJeu;
  for (int i = 0; i < 3; i++)
    delete tHero[i];
  for (int i = 0; i < 6; i++)
    delete tEnnemi[i];
  for (int i = 0; i < 8; i++)
    delete sJeu[i];
  delete font;
  return 1;
}



int main(int argc, char const *argv[]) {
  Contents *c = new Contents;
  int ok = 1;

  Texture perso;
  Sprite sprite_hero;
  Sprite sprite_room;
  Sprite sprite_corridor;
  Sprite sprite_ennemi;
  Sprite sprite_room;
  Window window;
  Font font;

  sprite_perso.setTexture(perso);

  window.create(VideoMode(1000, 1000), "Rogue");
  window.setFramerateLimit(60);

  while(window.isOpen()){
      Event event;
      while(window.pollEvent(event)){

          if(event.type == Event::Closed){
              window.close();
          }

          if(Keyboard::isKeyPressed(Keyboard::Z){

          }

          if(Keyboard::isKeyPressed(Keyboard::Q){

          }

          if(Keyboard::isKeyPressed(Keyboard::S){

          }

          if(Keyboard::isKeyPressed(Keyboard::D){

          }

      }
      window.draw(sprite_hero);
      window.display();
      window.clear();
  }


  delete c;
  c = NULL;

  return 0;
}
