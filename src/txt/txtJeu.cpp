#include "txtJeu.h"

using namespace std;

void txtBoucle (Hero *h) {
  bool jeu = true;
  char touche;
  Map *m = new Map;
  std::vector<Ennemi*> ennemis;
  m->initGeneration();
  m->positionnement(h, ennemis);
  m->setValueMap(h->getX(), h->getY(), 20);
  for(unsigned int i = 0; i < ennemis.size(); i++)
    m->setValueMap(ennemis[i]->getX(), ennemis[i]->getY(), 30);
  while(jeu){
    m->afficherMapTXT();
    m->setValueMap(h->getX(), h->getY());
    cin >> touche;
    switch (touche) {
      case 'z':
        if(m->getValueMap(h->getX(),(h->getY() + 1)))
          h->Haut();
        break;
      case 's':
        if(m->getValueMap(h->getX(),(h->getY() - 1)))
          h->Bas();
        break;
      case 'q':
        if(m->getValueMap((h->getX() - 1),h->getY()))
          h->Gauche();
        break;
      case 'd':
        if(m->getValueMap((h->getX() + 1),h->getY()))
          h->Droite();
        break;
      case 'a':
        jeu = false;
        break;
    }
    unsigned int idE = 0;
    while(idE < ennemis.size() && !(h->combat(ennemis[idE])))
      idE++;
    m->setValueMap(h->getX(), h->getY(), 20);
    for(unsigned int i = 0; i < ennemis.size(); i++) {
      m->setValueMap(ennemis[i]->getX(), ennemis[i]->getY());
      if(ennemis[i]->getPv() > 0) {
        ennemis[i]->update(m->getValueMap(ennemis[i]->getX(),(ennemis[i]->getY() - 1)),
          m->getValueMap(ennemis[i]->getX(),(ennemis[i]->getY() + 1)),
          m->getValueMap((ennemis[i]->getX() - 1),ennemis[i]->getY()),
          m->getValueMap((ennemis[i]->getX() + 1),ennemis[i]->getY()), h);
          m->setValueMap(ennemis[i]->getX(), ennemis[i]->getY(), 30);
      }
      else {
        ennemis.erase(ennemis.begin()+i);
        i--;
      }
    }
    system("clear");
  }
  txtDetruit(m);
}

void txtDetruit(Map *m){
    delete m;
    m = NULL;
}
