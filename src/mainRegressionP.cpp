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
  Ennemi e;
  assert(ok == e.deplacement(h));
  assert(ok == e.combat(h));
  ~Ennemi();
  ~Hero();

  return 0;
}
