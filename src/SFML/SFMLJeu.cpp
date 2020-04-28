#include "SFMLJeu.h"
#include "Contents.h"

using namespace sf;

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

int ajoutTexture(Sprite* tab[100][100]){

    Contents* content = new Contents;

    for (int x = 0; x < 100; x++){

        for (int y = 0; y < 100; y++){

            int type = position_valide(x, y);
            tab[x][y] = new Sprite;
            sprite.setTexture(content->tJeu);
            if (type == 0)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 1)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 2)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 3)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 4)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 5)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 6)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 7)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 8)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 9)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
            else if (type == 10)
                sprite.setTextureRect(intRect(32, 32, 32, 32));
        }
    }
    return 0;
}
