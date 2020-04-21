#include "Contents.h"

using namespace std;
using namespace sf;

int InitContents(Contents* c) {

  c->tJeu = new Texture;
  for (int i = 0; i < 3; i++)
    c->tHero[i] = new Texture;
  for (int i = 0; i < 6; i++)
    c->tEnnemi[i] = new Texture;
  for (int i = 0; i < 8; i++)
    c->sJeu[i] = new SoundBuffer;
  c->font = new Font;

      //Image
  if (!c->tJeu->loadFromFile("../data/img/Dungeon_Tileset.png"))
    cerr << "Ton image charges pas batard" << '\n';

  if (!c->tHero[0]->loadFromFile("../data/img/Adventurer_Sprite_Sheet.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tHero[1]->loadFromFile("../data/img/health_bar/health_bar_decoration.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tHero[2]->loadFromFile("../data/img/health_bar/health_bar.png"))
    cerr << "Ton image charges pas batard" << '\n';

  if (!c->tEnnemi[0]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_React.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tEnnemi[1]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Idle.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tEnnemi[2]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Walk.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tEnnemi[3]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Attack.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tEnnemi[4]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Hit.png"))
    cerr << "Ton image charges pas batard" << '\n';
  if (!c->tEnnemi[5]->loadFromFile("../data/img/Skeleton/Sprite_Sheets/Skeleton_Dead.png"))
    cerr << "Ton image charges pas batard" << '\n';

      //Son

  if (!c->sJeu[0]->loadFromFile("../data/sounds/Cancel.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[1]->loadFromFile("../data/sounds/Select.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[2]->loadFromFile("../data/sounds/Confirm.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[3]->loadFromFile("../data/sounds/Text.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[4]->loadFromFile("../data/sounds/Hit.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[5]->loadFromFile("../data/sounds/point.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[6]->loadFromFile("../data/sounds/lvUp.wav"))
    cerr << "Ton son charges pas batard" << '\n';
  if (!c->sJeu[7]->loadFromFile("../data/sounds/death.wav"))
    cerr << "Ton son charges pas batard" << '\n';

      //Font

  if (!c->font->loadFromFile("../data/ttf/Silver.ttf"))
    cerr << "Ton font charges pas batard" << '\n';

  return 1;
}

int DeleteContents(Contents* c) {
  delete c->tJeu;
  for (int i = 0; i < 3; i++)
    delete c->tHero[i];
  for (int i = 0; i < 6; i++)
    delete c->tEnnemi[i];
  for (int i = 0; i < 8; i++)
    delete c->sJeu[i];
  delete c->font;
  return 1;
}

int main(int argc, char const *argv[]) {
  Contents *c = new Contents;
  int ok = 1;
  ok = InitContents(c);
  ok = DeleteContents(c);
  delete c;
  c =NULL;
  return 0;
}
