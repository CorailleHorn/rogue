#include "Personnages.h"

using namespace std;

int main(){
  srand(time(NULL));
  int ok = 0;
  Hero* h = new Hero("Player");
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
  assert(ok == h->combat(e));
  cout << "Ennemie - pv : " << e->getPv() << endl;
  assert(ok == h->setName("Terrine"));
  assert(ok == e->combat(h));
  cout << h->getName() << " - pv : " << h->getPv();
  delete e;
  delete h;

  return 0;
}
