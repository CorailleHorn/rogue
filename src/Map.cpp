#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
#include "Map.h"
#include "Room.h"

using namespace std;

long double const PI = 3.1415926535897932384626433832795028841968;

float dist2Points(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}


Map::Map(int const size, int const nb, int const rad, int const max, int const min) :
    map_size(size), nbrooms(nb), radius(rad), room_max_size(max), room_min_size(min) {

    ptr_map = new int*[map_size];
    //on initialise les pointeurs sur des valeurs nulles
    for (int i = 0; i < map_size; i++) {
      ptr_map[i] = nullptr;
    }

    //on affecte a chaque pointeur du tableau un tableau alloué dynamiquement
    for (int i = 0; i < map_size; i++) {
      ptr_map[i] = new int[map_size];
    }
    //on fabrique la map : 0:vide 1:plein
    viderMap();
    list_room.resize(nbrooms);
}

Map::Map() : //param par defaut
    map_size(90), nbrooms(100), radius(5), room_max_size(20), room_min_size(5) {

    ptr_map = new int*[map_size];
    //on initialise les pointeurs sur des valeurs nulles
    for (int i = 0; i < map_size; i++) {
      ptr_map[i] = nullptr;
    }

    //on affecte a chaque pointeur du tableau un tableau alloué dynamiquement
    for (int i = 0; i < map_size; i++) {
      ptr_map[i] = new int[map_size];
    }
    //on fabrique la map : 0:vide 1:plein
    viderMap();
    list_room.resize(nbrooms);
}

Map::~Map() {
  //on libère la mémoire du tableau 2D map
  for (int i = 0; i < map_size; i++) {
      delete[] ptr_map[i];
  }
  delete[] ptr_map;

}


void Map::initGeneration() { //on lance la generation complete
    genRooms(); //on genere les rooms dans un cercle
    eclatement();//on procede a l'eclatement des rooms en leur donnant une physique (et donc un vecteur de deplacement)
    updateRooms();//on "met a jour" les rooms affichables (a l'interieur de map)
    chooseRooms();//on selectionne les rooms avec un aspect jouable

    ajouterRooms();//on ajoute les rooms dans la map physiquement

    initLinks(); //on initialise les liens pour pouvoir ensuite gen les couloirs

    genCorridors();

    ajouterCorridors();
    afficherMap();
    viderMap();
}

void Map::initGenerationDebug() { //on lance la generation avec affichage des étapes pour corriger les bugs
    genRooms(); //on genere les rooms dans un cercle
    updateRooms();//on "met a jour" les rooms affichables (a l'interieur de map)

    ajouterRooms();//on ajoute les rooms dans la map physiquement
    afficherMap(); //on affiche la map
    viderMap();

    eclatement();//on procede a l'eclatement des rooms en leur donnant une physique (et donc un vecteur de deplacement)
    updateRooms();//on "met a jour" les rooms affichables (a l'interieur de map)

    ajouterRooms();//on ajoute les rooms dans la map physiquement
    afficherMap(); //on affiche la map
    viderMap();

    updateRooms();//on "met a jour" les rooms affichables (a l'interieur de map)

    ajouterRooms();//on ajoute les rooms dans la map physiquement
    afficherMap(); //on affiche la map
    viderMap();

    chooseRooms();//on selectionne les rooms avec un aspect jouable

    ajouterRooms();//on ajoute les rooms dans la map physiquement
    afficherMap(); //on affiche la map

    initLinks(); //on initialise les liens pour pouvoir ensuite gen les couloirs
    ajouterLinks(); //DECOMMENTER CETTE LIGNE POUR ENLEVER L'AFFICHAGE DES LIENS
    afficherMap();
    viderMap();


    genCorridors();

    ajouterRooms();
    ajouterCorridors();
    afficherMap();
    viderMap();
}

void Map::testRegression() { //on lance le test de regression
    Map* M = new Map;
    assert(M->map_size == 90);
    assert(M->nbrooms == 100);
    assert(M->radius == 5);
    assert(M->room_max_size == 20 && M->room_min_size == 5);
    for (int i = 0; i < M->map_size; i++) {
        for (int j = 0; j < M->map_size; j++) {
          assert(M->ptr_map[i][j] == 0);
        }
    }
    assert((int)M->list_room.size() == M->nbrooms);
    delete M;
    M = NULL;
    assert(M == NULL);

    Map M2(90,100,5,20,5);
    assert(M2.map_size == 90);
    assert(M2.nbrooms == 100);
    assert(M2.radius == 5);
    assert(M2.room_max_size == 20 && M2.room_min_size == 5);
    for(int i = 0; i < M2.map_size; i++) {
        for (int j = 0; j < M2.map_size; j++) {
          assert(M2.ptr_map[i][j] == 0);
        }
    }
    assert((int)M2.list_room.size() == M2.nbrooms);
    for(int i = 0; i < M2.nbrooms; i++) {
        assert(M2.list_room[i].getx0() == 0);
        assert(M2.list_room[i].gety0() == 0);
        assert(M2.list_room[i].getx1() == 0);
        assert(M2.list_room[i].gety1() == 0);
        assert(M2.list_room[i].getX0() == 0);
        assert(M2.list_room[i].getY0() == 0);
        assert(M2.list_room[i].getX1() == 0);
        assert(M2.list_room[i].getY1() == 0);
        assert(M2.list_room[i].getX() == 0);
        assert(M2.list_room[i].getY() == 0);
        assert(M2.list_room[i].getIDlinked() == 0);
    }
    M2.genRooms();
    for(int i = 0; i < M2.nbrooms; i++) {
        assert(M2.list_room[i].getx0() > 0);
        assert(M2.list_room[i].gety0() > 0);
        assert(M2.list_room[i].getx1() > 0);
        assert(M2.list_room[i].gety1() > 0);
        assert(M2.list_room[i].getIDlinked() == -1);
    }
    M2.eclatement();
    //assert((int)M2.list_room.size() < M2.nbrooms);
    for(int i = 0; i < (int)M2.list_room.size(); i++) {

    }



}


void Map::genRooms()  {
    for (int i = 0; i < nbrooms; i++) {

        //on gen les rooms dans un cercle, puis on "éclate" les particules
        list_room[i].genInCircle(map_size, radius, room_max_size, room_min_size);
        list_room[i].setIDlinked(-1);
    }
}

void Map::eclatement() {
    //on "éclate" les rooms
    //pour chaque room on la déplace suivant un angle variant sur le cercle tant qu'elle est en collision avec une des rooms de la map

    for (unsigned int i = 0; i < list_room.size(); i++) {
        while (allRoomsCollisions(i)) {

            list_room[i].setx0(list_room[i].getx0() +  (cos(((i + 1.0) * PI) / (nbrooms / 2))));
            list_room[i].sety0(list_room[i].gety0() + (sin(((i + 1.0) * PI) / (nbrooms / 2))));
            list_room[i].setx1(list_room[i].getx0() + list_room[i].getL() - 1);
            list_room[i].sety1(list_room[i].gety0() + list_room[i].getH() - 1);
        }
    }
}

void Map::chooseRooms() {
    //on choisis toutes les rooms plus grande que 1.25 * la moyenne de toute les
    //rooms affichées
    float mean[2] = {0,0};
    moyenneRooms(mean);
    //mean[0] *= 0.75;
    //mean[1] *= 0.75;
    //NOTE: on ne met pas de unsigned int pour i car cette valeur peut prendre-1
    for (int i = 0; i < (int)list_room.size(); i++) {
        if ((list_room[i].getH() < mean[0]) || (list_room[i].getL() < mean[1])) {
            list_room.erase(list_room.begin() + i);
            i--;
        }
    }
}



void Map::initLinks() {
    for (int i = 0; i < (int)list_room.size(); i++) {
        choisirRoomLink(i);
    }
}


void Map::choisirRoomLink(int const ID) {
    //on initialise chaque liens dans un tableau et on en choisis un
    float distmin = 100000; //on donne juste un distance max de depart assez grande
    int IDmin;
    int idist;
    for (int i = 0; i < (int)list_room.size(); i++) {
        if (!isRoomLinked(ID,i) && !(i == ID)) {
            idist = dist2Points(list_room[ID].getX(), list_room[ID].getY(),list_room[i].getX(), list_room[i].getY());
            if(idist < distmin) {
                distmin = idist;
                IDmin = i;
            }
        }
    }
    list_room[ID].setIDlinked(IDmin);
    //ligne pour afficher les liens de manière condensé
    //cout << ID  << " -> " <<list_room[ID].IDlinked <<endl;;
}

bool const Map::isRoomLinked(int id1, int id2) {
    return (id1 == list_room[id2].getIDlinked());
}

void Map::ajouterLinks(){
    //on ajoute les liens sur la map pour mieux visualiser si la gen est correct
    int r, x0, y0, x1, y1, diffX, diffY;

    for(int i = 0; i < (int)list_room.size(); i++) {
        //ces variables "de transition" ne sont pas necessaire, elle sont
        //seulement là pour plus de lisibilité du code
        x0 = list_room[i].getX();
        y0 = list_room[i].getY();
        r = list_room[i].getIDlinked();
        x1 = list_room[r].getX();
        y1 = list_room[r].getY();
        diffX = x0 - x1;
        diffY = y0 - y1;

        if( diffX <= 0) {
            for (int j = 0; j < abs(diffX); j++) {
                ptr_map[x0 + j][y0] = -1;
            }
        }
        else{
            for (int j = 0; j < diffX; j++) {
                ptr_map[x0 - j][y0] = -1;
            }
        }
        if( diffY <= 0) {
            for (int j = 0; j < abs(diffY); j++) {
                ptr_map[x1][y0 + j] = -1;
            }
        }
        else{
            for (int j = 0; j < diffY; j++) {
                ptr_map[x1][y0 - j] = -1;
            }
        }
    }
}


void Map::genCorridors() {
    int id2;
    list_corridor.resize(list_room.size());
    for(int i = 0; i < (int)list_corridor.size(); i++) {
        list_corridor[i].x0 = list_room[i].getX();
        list_corridor[i].y0 = list_room[i].getY();

        id2 = list_room[i].getIDlinked();

        list_corridor[i].x1 = list_room[id2].getX();
        list_corridor[i].y1 = list_room[id2].getY();

        list_corridor[i].X = list_room[id2].getX();
        list_corridor[i].Y = list_room[i].getY();
    }
}

void Map::ajouterCorridors() {

    for(int i = 0; i < (int)list_corridor.size(); i++) {

        if(list_corridor[i].X >= list_corridor[i].x0) {

            for(int j = list_corridor[i].x0; j <= list_corridor[i].X; j++) {
                if(!isPointIn(j,list_corridor[i].Y, i)) {
                    ptr_map[j][list_corridor[i].Y - 1] = 1;
                    ptr_map[j][list_corridor[i].Y] = 0;
                    ptr_map[j][list_corridor[i].Y + 1] = 1;
                }
                else ptr_map[j][list_corridor[i].Y] = 0;
            }
            if(!isPointIn(list_corridor[i].X + 1,list_corridor[i].Y, i)) {
                ptr_map[list_corridor[i].X + 1][list_corridor[i].Y - 1] = 1;
                ptr_map[list_corridor[i].X + 1][list_corridor[i].Y] = 1;
                ptr_map[list_corridor[i].X + 1][list_corridor[i].Y + 1] = 1;
            }
            else ptr_map[list_corridor[i].X + 1][list_corridor[i].Y] = 0;
        }
        else {

            for(int j = list_corridor[i].x0; j >= list_corridor[i].X; j--) {
                if(!isPointIn(j,list_corridor[i].Y, i)) {
                    ptr_map[j][list_corridor[i].Y - 1] = 1;
                    ptr_map[j][list_corridor[i].Y] = 0;
                    ptr_map[j][list_corridor[i].Y + 1] = 1;
                }
                else ptr_map[j][list_corridor[i].Y] = 0;
            }
            if(!isPointIn(list_corridor[i].X - 1,list_corridor[i].Y, i)) {
                ptr_map[list_corridor[i].X - 1][list_corridor[i].Y - 1] = 1;
                ptr_map[list_corridor[i].X - 1][list_corridor[i].Y] = 1;
                ptr_map[list_corridor[i].X - 1][list_corridor[i].Y + 1] = 1;
            }
            else ptr_map[list_corridor[i].X - 1][list_corridor[i].Y] = 0;
        }

        if(list_corridor[i].y1 >= list_corridor[i].Y) {

            for(int j = list_corridor[i].Y + 1; j < list_corridor[i].y1; j++) {
                if(!isPointIn(list_corridor[i].X,j, i)) {
                    ptr_map[list_corridor[i].X - 1][j] = 1;
                    ptr_map[list_corridor[i].X][j] = 0;
                    ptr_map[list_corridor[i].X + 1][j] = 1;
                }
                else ptr_map[list_corridor[i].X][j] = 0;
            }
        }
        else {

            for(int j = list_corridor[i].Y - 1; j > list_corridor[i].y1; j--) {
                if(!isPointIn(list_corridor[i].X,j, i)) {
                    ptr_map[list_corridor[i].X - 1][j] = 1;
                    ptr_map[list_corridor[i].X][j] = 0;
                    ptr_map[list_corridor[i].X + 1][j] = 1;
                }
                else ptr_map[list_corridor[i].X][j] = 0;
            }
        }
    }
}

bool const Map::isPointIn(int const X, int const Y, int const ID) {
    //test si le point du couloir traverse un couloir ou une room
    bool is = false;

    //test si point est dans un couloir
    for(int i = 0; i < (int)list_corridor.size(); i++) {
        if(i != ID) {
            if(((X >= list_corridor[i].x0)
            &&  (X <= list_corridor[i].X)
            &&  (Y == list_corridor[i].Y))
            || ((Y >= list_corridor[i].y0)
            &&  (Y <= list_corridor[i].Y)
            &&  (X == list_corridor[i].X)))
                is = true;
        }
    }
    //test si point est dans une room
    for(int i = 0; i < (int)list_room.size(); i++) {
        if((X > list_room[i].getx0())
        &&  (X < list_room[i].getx1())
        &&  (Y > list_room[i].gety0())
        &&  (Y < list_room[i].gety1()))
            is = true;
    }
    return is;
}

bool const Map::allRoomsCollisions(unsigned int const ID) {
    //vérifie si la room au rang ID entre en collision avec toutes les autres rooms
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on test avec roomCollision pour toutes les autres rooms
        if (i != ID) {
            if (list_room[i].roomCollision(list_room[ID])) {
                return true;
            }
        }
    }
    return false;
}

float* Map::moyenneRooms(float mean[]) {

    for(unsigned int i = 0; i < list_room.size(); i++) {
        mean[0] += list_room[i].getH();
        mean[1] += list_room[i].getL();
    }
    mean[0] /= list_room.size();
    mean[1] /= list_room.size();
    return mean;
}


void Map::ajouterRooms() {
    //ajouter l'affichage des rooms dans la map
    //on arrondi d'abord les valeurs
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on ajoute la largeur des rooms
        // j parcourant la largeur de la room
        for (int j = 0; j < list_room[i].getL(); j++) {
            ptr_map[list_room[i].getX0() + j][list_room[i].getY0()] = 1;
            ptr_map[list_room[i].getX0() + j][list_room[i].getY1()] = 1;
        }
        //on ajoute la hauteur des rooms
        // k parcourant la hauteur de la room
        for (int k = 0; k < list_room[i].getH(); k++) {
            ptr_map[list_room[i].getX0()][list_room[i].getY0() + k] = 1;
            ptr_map[list_room[i].getX1()][list_room[i].getY0() + k] = 1;
        }
        //on affiche le num de la room
        list_room[i].initCenterRooms();
        //ligne pour l'affichage des numéros des rooms
        //ptr_map[list_room[i].getX()][list_room[i].getY()] = i;
        //lignes pour l'affichage des données des rooms
        //cout << "room " << i << " : " << list_room[i].getH() << ";" << list_room[i].getL()
        //<< " - " << list_room[i].getX0() << ";" << list_room[i].getY0() << endl;
    }
}

void Map::updateRooms() {
    //cette methode s'assure que les rooms soit affichables dans la map
    for(int i = 0; i < (int)list_room.size(); i++) {
        //on arrondis les valeurs des coordonnees des rooms
        list_room[i].arrondValRoom();
        //et on verifie que les rooms ne sont pas dans la map
        if(!list_room[i].isRoomIn(map_size)) {
            //et on les supprime du tableau dynamique
            list_room.erase(list_room.begin() + i);
            i--;
        }
    }
}



void Map::viderMap() {
    //on fabrique la map : 0:vide 1:plein
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            ptr_map[i][j] = 0;
        }
    }
}

void Map::afficherMap() {
    //on affiche dans le terminal lignes par lignes
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {

            if (ptr_map[j][i] == 0) cout << "  ";
            else if (ptr_map[j][i] == 1) cout << "##";
            else if (ptr_map[j][i] == -1) cout << "XX";
            else if (ptr_map[j][i] < 10) cout << " " << ptr_map[j][i]; //petite modif pour afficher les num des rooms
            else cout << ptr_map[j][i];
        }
        cout << endl;
    }
    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;
}
