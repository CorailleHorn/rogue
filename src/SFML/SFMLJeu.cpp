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
                sprite.setTextureRect(intRect(0, 0, 0, 0));
            else if (type == 1)
                if (position_valide(x, y-1) == 1)
                    if (position_valide(x, y+1) == 1)
                        if (position_valide(x-1, y) == 0)
                            if (position_valide(x+1, y) == 2)
                                sprite.setTextureRect(intRect(0, 32, 32, 64));

                else if (position_valide(x, y-1) == 0)
                    if (position_valide(x, y+1) == 2)
                        if (position_valide(x-1, y) == 1)
                            if (position_valide(x+1, y) == 1)
                                sprite.setTextureRect(intRect(130, 0, 162, 32));

                else if (position_valide(x, y-1) == 1)
                    if (position_valide(x, y+1) == 1)
                        if (position_valide(x-1, y) == 2)
                            if (position_valide(x+1, y) == 0)
                                sprite.setTextureRect(intRect(64, 32, 96, 64));

                else if (position_valide(x, y-1) == 2)
                    if (position_valide(x, y+1) == 0)
                        if (position_valide(x-1, y) == 1)
                            if (position_valide(x+1, y) == 1)
                                sprite.setTextureRect(intRect(32, 64, 64, 96));

                else if (position_valide(x, y-1) == 0)
                    if (position_valide(x, y+1) == 1)
                        if (position_valide(x-1, y) == 0)
                            if (position_valide(x+1, y) == 1)
                                sprite.setTextureRect(intRect(96, 0, 128, 32));

                else if (position_valide(x, y-1) == 0)
                    if (position_valide(x, y+1) == 1)
                        if (position_valide(x-1, y) == 1)
                            if (position_valide(x+1, y) == 0)
                                sprite.setTextureRect(intRect(160, 0, 192, 32));

                else if (position_valide(x, y-1) == 1)
                    if (position_valide(x, y+1) == 0)
                        if (position_valide(x-1, y) == 1)
                            if (position_valide(x+1, y) == 0)
                                sprite.setTextureRect(intRect(64, 64, 96, 96));

                else if (position_valide(x, y-1) == 1)
                    if (position_valide(x, y+1) == 0)
                        if (position_valide(x-1, y) == 0)
                            if (position_valide(x+1, y) == 1)
                                sprite.setTextureRect(intRect(0, 64, 32, 96));

            else if (type == 2)
                sprite.setTextureRect(intRect(160, 304, 192, 336));
        }
    }
    return 0;
}
