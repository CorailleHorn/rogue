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

    for (int i = 0; i < 100; i++){

        for (int j = 0; < 100; j++){

            int type = position_valide(i, j);

            if (type == 0){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 1){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 2){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 3){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 4){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 5){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 6){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 7){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 8){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
            else if (type == 9){
                tab[i][j] = new Sprite;
                sprite.setTexture(content->tJeu);
                sprite.setTextureRect(intRect(sprite.x*32, sprite.y*32, 32, 32));
            }
        }
    }
    return 0;
}
