#include "Jeu.h"

using namespace std;

void Boucle (Hero *h) {
  bool jeu = true;
  char touche;
  Map *m = new Map(h);
  m->initGeneration();
  while(jeu){
    m->update();
    m->afficherTout();
    touche = fgetc(stdin);
    switch (touche) {
      case 'z':
        if(m->position_valide(h->getX(),(h->getY() + 1)))
          h->Haut();
        break;
      case 's':
        if(m->position_valide(h->getX(),(h->getY() - 1)))
          h->Bas();
        break;
      case 'q':
        if(m->position_valide((h->getX() - 1),h->getY()))
          h->Gauche();
        break;
      case 'd':
        if(m->position_valide((h->getX() + 1),h->getY()))
          h->Droite();
        break;
      case 'a':
        jeu = false;
        break;
    }
    system("clear");
  }
  Detruit(m);
}

void Detruit(Map *m){
    delete m;
    m = NULL;
}
