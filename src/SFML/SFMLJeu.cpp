#include "SFMLJeu.h"

using namespace sf;

void Boucle (Hero *h) {
  Vector2i screenDimensions(720, 720);
  RenderWindow window(VideoMode(screenDimensions.x, screenDimensions.y), "Rogue");
  window.setFramerateLimit(60);
  Contents* content = new Contents;
  Map* m = new Map;
  m->initGeneration();
  m->positionnement(h);
  h->setSprites(content->anim_Joueur);
  int taille = m->size();
  Sprite tab[90][90];
  ajoutTexture(content, m, tab);
  View view(Vector2f(h->getX(), h->getY()), Vector2f(screenDimensions/2));
  window.setView(view);
  AnimatedSprite hero(sf::seconds(0.2), true);
  hero.setPosition(sf::Vector2f(h->getX(), h->getY()));
  sf::Clock frameClock;
  float speed = 1.f;
  bool noKeyWasPressed = true;
  sf::Vector2f movement(0.f, 0.f);
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
      sf::Time frameTime = frameClock.restart();
      if (Keyboard::isKeyPressed(Keyboard::Up))
      {
          h->haut();
          movement.y = -speed;
          view.setCenter(sf::Vector2f(h->getX(), h->getY()));
          std::cout << "\nmouvement Up Good";
          noKeyWasPressed = false;
      }
      if (Keyboard::isKeyPressed(Keyboard::Down))
      {
          h->bas();
          movement.y = speed;
          view.setCenter(sf::Vector2f(h->getX(), h->getY()));
          std::cout << "\nmouvement Down Good";
          noKeyWasPressed = false;
      }
      if(Keyboard::isKeyPressed(Keyboard::Left))
      {
          h->gauche();
          movement.x = -speed;
          view.setCenter(sf::Vector2f(h->getX(), h->getY()));
          std::cout << "\nmouvement Left Good";
          noKeyWasPressed = false;
      }
      if (Keyboard::isKeyPressed(Keyboard::Right))
      {
          h->droite();
          movement.x = speed;
          view.setCenter(sf::Vector2f(h->getX(), h->getY()));
          std::cout << "\nmouvement Right Good";
          noKeyWasPressed = false;
      }
      hero.play(*h->getSprite());
      hero.move(movement * frameTime.asSeconds());
      hero.update(frameTime);
      window.setView(view);
      if (noKeyWasPressed)
      {
          movement = Vector2f(0, 0);
      }
      noKeyWasPressed = true;
      // draw
      window.clear();
      for (int x = 0; x < taille; x++)
          for (int y = 0; y < taille; y++)
            window.draw(tab[x][y]);
      window.draw(hero);
      window.display();
  }
  system("clear");
  Detruit(m);
  delete content;
}

void Detruit(Map *m){
    delete m;
    m = NULL;
}


void ajoutTexture(Contents* content, Map* m, Sprite tab[90][90]) {
  int taille = m->size();
  for (int x = 1; x < taille-1; x++){
    std::cout << '\n';
      for (int y = 1; y < taille-1; y++){
          int type = m->getValueMap(x, y);
          std::cout << type;
          tab[x][y].setTexture(*(content->tJeu));
          if (type == 0){
              tab[x][y].setTextureRect(IntRect(0, 0, 0, 0));
          }
          if (type == 1){
              tab[x][y].setTextureRect(IntRect(320, 256, 32, 32));
          }
          if (type == 2){ //Intérieur
              tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
          }
          else{
              tab[x][y].setTextureRect(IntRect(0, 0, 0, 0));
          }
          tab[x][y].setPosition(x*32, y*32);
      }
  }
}

/*int ajoutTexture(){ // Affiche les sprites en verifiant les cases autour pour les cas particuliers (coins)
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

            if (type == 0){
                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
            }

            if (type == 1){ // Mur / Coin

                if (m->getValueMap(x, y-1) == 1){ // Mur gauche
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 2){
                                if (m->getValueMap(x+1, y+1) == 2){
                                    if (m->getValueMap(x+1, y-1) == 2){
                                        if (m->getValueMap(x-1, y+1) == 0){
                                            if (m->getValueMap(x-1, y-1) == 0){
                                                std::cout <<  "ok1 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 0){ // Mur du haut
                    if (m->getValueMap(x, y+1) == 2){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 1){
                                if (m->getValueMap(x+1, y+1) == 2){
                                    if (m->getValueMap(x+1, y-1) == 0){
                                        if (m->getValueMap(x-1, y+1) == 2){
                                            if (m->getValueMap(x-1, y-1) == 0){
                                                std::cout <<  "ok2 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){ // Mur droit
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 2){
                            if (m->getValueMap(x+1, y) == 0){
                                if (m->getValueMap(x+1, y+1) == 0){
                                    if (m->getValueMap(x+1, y-1) == 0){
                                        if (m->getValueMap(x-1, y+1) == 2){
                                            if (m->getValueMap(x-1, y-1) == 2){
                                                std::cout <<  "ok3 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 2){ // Mur du bas
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 1){
                                if (m->getValueMap(x+1, y+1) == 0){
                                    if (m->getValueMap(x+1, y-1) == 2){
                                        if (m->getValueMap(x-1, y+1) == 0){
                                            if (m->getValueMap(x-1, y-1) == 2){
                                                std::cout <<  "ok4 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 0){ // Coin haut gauche ok
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 1){
                                if (m->getValueMap(x+1, y-1) == 0){
                                    if (m->getValueMap(x-1, y-1) == 0){
                                        if (m->getValueMap(x-1, y+1) == 0){
                                            if (m->getValueMap(x+1, y+1) == 2){
                                                std::cout <<  "ok5 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 0){ // Coin haut droit ok
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 0){
                                if (m->getValueMap(x-1, y-1) == 0){
                                    if (m->getValueMap(x+1, y-1) == 0){
                                        if (m->getValueMap(x+1, y+1) == 0){
                                            if (m->getValueMap(x-1, y+1) == 2){
                                                std::cout <<  "ok6 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){ // Coin bas droit ok
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 0){
                                if (m->getValueMap(x+1, y-1) == 0){
                                    if (m->getValueMap(x+1, y+1) == 0){
                                        if (m->getValueMap(x-1, y-1) == 2){
                                            if (m->getValueMap(x-1, y+1) == 0){
                                                std::cout <<  "ok7 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                else if (m->getValueMap(x, y-1) == 1){ // Coin bas gauche ok
                    if (m->getValueMap(x, y+1) == 0){
                        if (m->getValueMap(x-1, y) == 0){
                            if (m->getValueMap(x+1, y) == 1){
                                if (m->getValueMap(x+1, y+1) == 0){
                                    if (m->getValueMap(x+1, y-1) == 2){
                                        if (m->getValueMap(x-1, y-1) == 0){
                                            if (m->getValueMap(x-1, y+1) == 0){
                                                std::cout <<  "ok8 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (m->getValueMap(x, y-1) == 1){ // Coin bas gauche 2
                    if (m->getValueMap(x, y+1) == 2){
                        if (m->getValueMap(x-1, y) == 2){
                            if (m->getValueMap(x+1, y) == 1){
                                if (m->getValueMap(x+1, y+1) == 2){
                                    if (m->getValueMap(x+1, y-1) == 0){
                                        if (m->getValueMap(x-1, y-1) == 2){
                                            if (m->getValueMap(x-1, y+1) == 2){
                                                std::cout <<  "ok9 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (m->getValueMap(x, y-1) == 1){ // Coin bas droit 2
                    if (m->getValueMap(x, y+1) == 2){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 2){
                                if (m->getValueMap(x+1, y+1) == 2){
                                    if (m->getValueMap(x+1, y-1) == 2){
                                        if (m->getValueMap(x-1, y-1) == 0){
                                            if (m->getValueMap(x-1, y+1) == 2){
                                                std::cout <<  "ok10 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (m->getValueMap(x, y-1) == 2){ // Coin haut gauche 2
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 2){
                            if (m->getValueMap(x+1, y) == 1){
                                if (m->getValueMap(x+1, y+1) == 0){
                                    if (m->getValueMap(x+1, y-1) == 2){
                                        if (m->getValueMap(x-1, y-1) == 2){
                                            if (m->getValueMap(x-1, y+1) == 2){
                                                std::cout <<  "ok11 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (m->getValueMap(x, y-1) == 2){ // Coin haut droit 2
                    if (m->getValueMap(x, y+1) == 1){
                        if (m->getValueMap(x-1, y) == 1){
                            if (m->getValueMap(x+1, y) == 2){
                                if (m->getValueMap(x+1, y+1) == 2){
                                    if (m->getValueMap(x+1, y-1) == 2){
                                        if (m->getValueMap(x-1, y-1) == 2){
                                            if (m->getValueMap(x-1, y+1) == 0){
                                                std::cout <<  "ok12 ";
                                                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (type == 2){ //Intérieur
                tab[x][y].setTextureRect(IntRect(192, 256, 32, 32));
            }
            else{
                tab[x][y].setTextureRect(IntRect(224, 224, 32, 32));
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
}*/
