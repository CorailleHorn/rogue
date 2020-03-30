#include "txtJeu.h"

using namespace std;

void txtBoucle (Hero *h) {
  Map *m = new Map(h);
  m.initGeneration();

  while(){

    system("clear");
  }
  txtDetruit(m);
}

void txtDetruit(Map *m){
    delete m;
    m = NULL;
}


/*int getPtr();
int Map::getPtr(){
    return ptr_map;
}*/
