#include "Personnages.h"

using namespace std;

int main(){
  ok = 0;
  Hero h;
  assert(ok == h.lvUp());
  assert(ok == Bas());
  assert(ok == Haut());
  assert(ok == Gauche());
  assert(ok == Droite());
  assert(ok == h.deplacement());
  assert(ok == h.combat());
  assert(ok == h.setName("player1"));
  Ennemi(5);
  Ennemi e;
  e.deplacement(h);
  e.combat(h);
  ~Personnage();
  ~Ennemi();
  ~Hero();

  return 0;
}
