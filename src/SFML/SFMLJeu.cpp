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
    Vector2i screenDimensions(720, 720);
    RenderWindow window(VideoMode(screenDimensions.x, screenDimensions.y), "Rogue");
    window.setFramerateLimit(60);
    View view(sf::Vector2f(350.f, 350.f), sf::Vector2f(720.f, 720.f));
    window.setView(view);
    Sprite tab[taille][taille];
    for (int x = 1; x < taille-1; x++){
      std::cout << '\n';
        for (int y = 1; y < taille-1; y++){
            int type = m->getValueMap(x, y);
            std::cout << type;
            tab[x][y].setTexture(*(content->tJeu));
/*
            else if (type == 1){ // Mur / Coin
                tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
            }
                //tab[x][y].setTextureRect(IntRect(0, 32, 32, 32));

                if (m->getValueMap(x, y-1) == 1){ // Mur gauche
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 2){
                                tab[x][y].setTextureRect(IntRect(0, 32, 32, 32));
                            }
                        }
                    }
                }
                else if (m->getValueMap(x, y-1) == 0){ // Mur du haut
                    if (m->getValueMap(x, y+1) == 2){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 1){
                                tab[x][y].setTextureRect(IntRect(32, 0, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){ // Mur droit
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 2){
                            if (m->getValueMap(x+1, y) == 0){
                                tab[x][y].setTextureRect(IntRect(64, 32, 32, 32));
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 2){ // Mur du bas
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 1){
                                tab[x][y].setTextureRect(IntRect(32, 64, 32, 32));
                            }
                        }
                    }
                }
                else {
                    tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
                }
            }

                else if (m->getValueMap(x, y-1) == 0){ // Coin haut gauche ok
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 1){
                                //if (m->getValueMap(x+1, y-1) == 0){
                                    //if (m->getValueMap(x-1, y-1) == 0){
                                        //if (m->getValueMap(x-1, y+1) == 0){
                                            //if (m->getValueMap(x+1, y+1) == 2){
                                                tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
                                            //}
                                        //}
                                    //}
                                //}
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 0){ // Coin haut droit ok
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 0){
                                //if (m->getValueMap(x-1, y-1) == 0){
                                    //if (m->getValueMap(x+1, y-1) == 0){
                                        //if (m->getValueMap(x+1, y+1) == 0){
                                            //if (m->getValueMap(x-1, y+1) == 2){
                                                tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
                                            //}
                                        //}
                                    //}
                                //}
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){ // Coin bas droit ok
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 0){
                                //if (m->getValueMap(x+1, y-1) == 0){
                                    //if (m->getValueMap(x+1, y+1) == 0){
                                        //if (m->getValueMap(x-1, y-1) == 2){
                                            //if (m->getValueMap(x-1, y+1) == 0){
                                                tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
                                            //}
                                        //}
                                    //}
                                //}
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){ // Coin bas gauche ok
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 1){
                                //if (m->getValueMap(x+1, y+1) == 0){
                                    //if (m->getValueMap(x+1, y-1) == 2){
                                        //if (m->getValueMap(x-1, y-1) == 0){
                                            //if (m->getValueMap(x-1, y+1) == 0){
                                                tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
                                            //}
                                        //}
                                    //}
                                //}
                            }
                        }
                    }
                }*/

            if (type == 2){ //Intérieur
                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
            }
            else{
                tab[x][y].setTextureRect(IntRect(0, 0, 0, 0));
            }
            tab[x][y].setPosition(x*32, y*32);
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
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            view.move(0.f, -32.f);
            std::cout << "\nmouvement Up Good";
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            view.move(0.f, 32.f);
            std::cout << "\nmouvement Down Good";

        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            view.move(-32.f, 0.f);
            std::cout << "\nmouvement Left Good";

        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            view.move(32.f, 0.f);
            std::cout << "\nmouvement Right Good";

        }
        window.setView(view);
        // draw
        window.clear();
        for (int x = 0; x < taille; x++)
            for (int y = 0; y < taille; y++)
              window.draw(tab[x][y]);
        window.display();
    }
    system("clear");
    delete m;
    delete content;
    return 0;
}
