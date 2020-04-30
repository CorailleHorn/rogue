#include "SFMLJeu.h"

using namespace sf;

/*void Boucle (Hero *h) {
  bool jeu = true;
  char touche;
  Map *m = new Map();
  m->initGeneration();
  while(jeu){
    m->update();
    m->afficherTout();
    touche = fgetc(stdin);
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
    system("clear");
  }
  Detruit(m);
}

void Detruit(Map *m){
    delete m;
    m = NULL;
}*/

int ajoutTexture(){ // Affiche les sprites en verifiant les cases autour pour les cas particuliers (coins)
    Contents* content = new Contents;
    Map* m = new Map;
    m->initGeneration();
    int taille = m->size();
    Vector2i screenDimensions(taille*32, taille*32);
    RenderWindow window(VideoMode(screenDimensions.x, screenDimensions.y), "Rogue");
    window.setFramerateLimit(60);
    Sprite tab[taille][taille];
    for (int x = 0; x < taille; x++){
      std::cout << '\n';
        for (int y = 0; y < taille; y++){
            int type = m->getValueMap(x, y);
            std::cout << type;
            tab[x][y].setTexture(*(content->tJeu));
            tab[x][y].setPosition(x*32, y*32);

            if (type == 0){
                tab[x][y].setTextureRect(IntRect(0, 0, 0, 0));
            }

            else if (type == 1){
                if (m->getValueMap(x, y-1) == 1){
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 2){
                                tab[x][y].setTextureRect(IntRect(0, 32, 32, 32));
                            }
                        }
                    }
                }
            }

                else if (m->getValueMap(x, y-1) == 0){
                    if (m->getValueMap(x, y+1) == 2){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 1){
                                tab[x][y].setTextureRect(IntRect(130, 0, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 2){
                            if (m->getValueMap(x+1, y) == 0){
                                tab[x][y].setTextureRect(IntRect(64, 32, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 2){
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 1){
                                tab[x][y].setTextureRect(IntRect(32, 64, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 0){
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 1){
                                tab[x][y].setTextureRect(IntRect(96, 0, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 0){
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 0){
                                tab[x][y].setTextureRect(IntRect(160, 0, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 0){
                                tab[x][y].setTextureRect(IntRect(64, 64, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 1){
                                tab[x][y].setTextureRect(IntRect(0, 64, 32, 32));
                            }
                        }
                    }
                }

            else if (type == 2){
                tab[x][y].setTextureRect(IntRect(160, 304, 32, 32));
            }
        }
    }
    Clock frameClock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // draw
        window.clear();
        for (int x = 0; x < taille; x++)
            for (int y = 0; y < taille; y++)
              window.draw(tab[x][y]);
        window.display();
    }
    //delete m;
    delete content;
    return 0;
}
