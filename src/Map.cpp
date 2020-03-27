#include <iostream>
#include <cmath>
#include <vector>
#include "Map.h"
#include "Room.h"

using namespace std;

long double const PI = 3.1415926535897932384626433832795028841968;

double genRandomDouble() {
    return ((double)rand() / (RAND_MAX));
}

float dist2Points(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}


Map::Map(int const size, int const nb, int const max, int const min, int const rad) :
    map_size(size), nbrooms(nb), room_max_size(max), room_min_size(min), radius(rad) {

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



void Map::initGeneration() {
    genRooms();

    eclatement();
    updateRooms();

    chooseRooms();

    ajouterRooms();
    afficherMap();
    viderMap();
}


void Map::genInCircle(Room& R) {
    //on genere des tailles aléatoire
    R.H = (rand() % (room_max_size - room_min_size)) + room_min_size;//hauteur
    R.L = (rand() % (room_max_size - room_min_size)) + room_min_size;//largeur

    //on genere des points aléatoires dans un cercle
    float t = 2 * PI * genRandomDouble();
    float u = genRandomDouble() + genRandomDouble();
    float r;
    if (u > 1) r = (2 - u);
    else r = u;

    R.x0 = (radius * r * cos(t)) + (map_size/2);
    R.y0 = (radius * r * sin(t)) + (map_size/2);
    R.x1 = R.x0 + R.L - 1;
    R.y1 = R.y0 + R.H - 1;
}

void Map::genInMap(Room& R) {
    R.H = (rand() % (room_max_size - room_min_size)) + room_min_size;//hauteur
    R.L = (rand() % (room_max_size - room_min_size)) + room_min_size;//largeur
    R.x0 = rand() % (map_size - R.L); //x0 en évitant de sortir de la map : gen entre 0 - largeur
    R.y0 = rand() % (map_size - R.H); //y0
    R.x1 = R.x0 + R.L - 1; //x1
    R.y1 = R.y0 + R.H - 1; //y1
}


void Map::genRooms()  {
    for (int i = 0; i < nbrooms; i++) {
        //Tech1 on gen les rooms sur la map alea
        //genInMap();
        //Tech2 on gen les rooms dans un cercle, puis on "éclate" les particules
        genInCircle(list_room[i]);
    }
}

void Map::eclatement() {
    //on "éclate" les rooms
    //pour chaque room on la déplace suivant un angle variant sur le cercle tant qu'elle est en collision avec une des rooms de la map

    for (unsigned int i = 0; i < list_room.size(); i++) {
        while (allRoomsCollisions(i)) {

            list_room[i].x0 += (cos(((i + 1.0) * PI) / (nbrooms / 2)));
            list_room[i].y0 += (sin(((i + 1.0) * PI) / (nbrooms / 2)));
            list_room[i].x1 = list_room[i].x0 + list_room[i].L - 1;
            list_room[i].y1 = list_room[i].y0 + list_room[i].H - 1;
        }
    }
}

void Map::chooseRooms() {
    //on choisis les rooms en fonction des parametres voulus
    //NOTE: on ne met pas de unsigned int pour i car cette valeur peut prendre-1
    for (int i = 0; i < (int)list_room.size(); i++) {
        if ((list_room[i].H < 7) || (list_room[i].L < 7)) {
            list_room.erase(list_room.begin() + i);
            i--;
        }
    }
}

void Map::initCenterRooms() {
    //on place les centres des rooms
    for (unsigned int i = 0; i < list_room.size() ; i++) {
        if ((list_room[i].L % 2) == 0)
            list_room[i].X = list_room[i].X0 + list_room[i].L / 2 -(rand() % 2);
        else
            list_room[i].X = list_room[i].X0 + (int)(list_room[i].L / 2) - 1;

        if ((list_room[i].H % 2) == 0)
            list_room[i].Y = list_room[i].Y0 + list_room[i].H / 2 -(rand() % 2);
        else
            list_room[i].Y = list_room[i].Y0 + (int)(list_room[i].H / 2) - 1;
    }
}
/*
void Map::initLinks() {
    for (unsigned int i = 0; i < list_room.size(); i++) {
        choisirRoomLink(i);
    }
}

void Map::choisirRoomLink(unsigned int const ID) {
    //on initialise chaque liens dans un tableau et on en choisis un
    int tablinks[2][list_room.size() - 1];
    for (unsigned int i = 0; i < list_room.size(); i++) {
        tablinks[0][i] = i;
        if (i != ID)
            tablinks[1][i] = dist2Points(list_room[ID].X, list_room[ID].Y,list_room[i].X, list_room[i].Y);
        else
            tablinks[1][i] = -1;
    }
    sort(tablinks[1], tablinks[1] + list_room.size() - 2);

}
*/

bool const Map::allRoomsCollisions(unsigned int const ID) {
    //vérifie si la room au rang ID entre en collision avec toutes les autres rooms
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on test avec roomCollision pour toutes les autres rooms
        if (i != ID) {
            if (roomCollision(list_room[i], list_room[ID])) {
                return true;
            }
        }
    }
    return false;
}

bool const Map::roomCollision(Room A, Room B) {

    //detecte si B entre en collision avec A
    if((B.x0 >= A.x0 + A.L)      // trop à droite
	|| (B.x0 + B.L <= A.x0) // trop à gauche
	|| (B.y0 >= A.y0 + A.H) // trop en bas
 	|| (B.y0 + B.H <= A.y0))  // trop en haut
        return false;
    else return true;
}


void Map::ajouterRooms() {
    //ajouter l'affichage des rooms dans la map
    //on arrondi d'abord les valeurs
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on ajoute la largeur des rooms
        // j parcourant la largeur de la room
        for (int j = 0; j < list_room[i].L; j++) {
            ptr_map[list_room[i].X0 + j][list_room[i].Y0] = 1;
            ptr_map[list_room[i].X0 + j][list_room[i].Y1] = 1;
        }
        //on ajoute la hauteur des rooms
        // k parcourant la hauteur de la room
        for (int k = 0; k < list_room[i].H; k++) {
            ptr_map[list_room[i].X0][list_room[i].Y0 + k] = 1;
            ptr_map[list_room[i].X1][list_room[i].Y0 + k] = 1;
        }
        //on affiche le num de la room
        initCenterRooms();
        ptr_map[list_room[i].X][list_room[i].Y] = i;
    }
}

void Map::updateRooms() {
    //cette methode s'assure que les rooms soit affichables dans la map
    for(int i = 0; i < (int)list_room.size(); i++) {
        //on arrondis les valeurs des coordonnees des rooms
        list_room[i].arrondValRoom();
        //et on verifie que les rooms sont dans la map
        if(list_room[i].isRoomIn(map_size)) {
            cout << "room " << i << " : " << list_room[i].H << ";" << list_room[i].L
            << " - " << list_room[i].X0 << ";" << list_room[i].Y0 << endl;
        }
        else {
            //sinon on les supprime du tableau dynamique
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
