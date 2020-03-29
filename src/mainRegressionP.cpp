#include "Personnages.h"

using namespace std;

int main(){
  srand(time(NULL));
  int ok = 0;
  Hero* h = new Hero("Dominique Strauss Kahn");
  Ennemi* e = new Ennemi(4);
  cout << "Hero : " << h->getName() << endl
    << "x : " << h->getX() << endl
    << "y : " << h->getY() << endl
    << "pv : " << h->getPv() << endl
    << "lv : " << h->getLv() << endl
    << "atk : " << h->getAtk() << endl
    << "def : " << h->getDef() << "\n\n"
    << "Ennemi :" << endl
    << "x : " << e->getX() << endl
    << "y : " << e->getY() << endl
    << "pv : " << e->getPv() << endl
    << "lv : " << e->getLv() << endl
    << "atk : " << e->getAtk() << endl
    << "def : " << e->getDef() << "\n\n";
  assert(ok == h->lvUp());
  cout << "lv : "  << h->getLv() << endl
    << "atk : " << h->getAtk() << endl
    << "def : " << h->getDef() << endl;
  /*assert(ok == h->Bas());
  assert(ok == h->Haut());
  assert(ok == h->Gauche());
  assert(ok == h->Droite());
  assert(ok == h->deplacement());*/
  assert(ok == h->combat(e));
  cout << "pv : " << e->getPv() << endl;
  assert(ok == h->setName("player1"));
  //assert(ok == e->deplacement(h));
  assert(ok == e->combat(h));
  cout << "pv : " << h->getPv();
  delete e;
  delete h;

  return 0;
}
