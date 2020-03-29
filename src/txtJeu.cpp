#include "txtJeu.h"

using namespace std;

void txtAff(const Map &m) {
    int ptr_m = m.getPtr();

        for (int i = 0; i < m.map_size; i++) {
            for (int j = 0; j < m.map_size; j++) {

                if (ptr_m[j][i] == 0) cout << "  ";
                else if (ptr_m[j][i] == 1) cout << "##";
                else if (ptr_m[j][i] == -1) cout << "XX";
                else if (ptr_m[j][i] < 10) cout << " " << ptr_m[j][i];
                else if (ptr_m[j][i] == 2) cout << "8";
                else cout << ptr_m[j][i];
            }
            cout << endl;
        }
        for (int i = 0; i < map_size; i++) {
            cout << "**";
        }
        cout << endl;
    }
}

void txtBoucle (Map &m) {
    while(){

    }

}

void txtInit(){
    Map m;
    m.initGeneration();
}

void txtDetruit(){
    delete m;
}


/*int getPtr();
int Map::getPtr(){
    return ptr_map;
}*/
