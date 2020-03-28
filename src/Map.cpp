#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
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



void Map::initGeneration() { //on lance la generation complete
    genRooms(); //on genere les rooms dans un cercle
    eclatement();//on procede a l'eclatement des rooms en leur donnant une physique (et donc un vecteur de deplacement)
    updateRooms();//on "met a jour" les rooms affichables (a l'interieur de map)
    chooseRooms();//on selectionne les rooms avec un aspect jouable

    ajouterRooms();//on ajoute les rooms dans la map physiquement
    afficherMap(); //on affiche la map

    initLinks(); //on initialise les liens pour pouvoir ensuite gen les couloirs
    ajouterLinks(); //DECOMMENTER CETTE LIGNE POUR ENLEVER L'AFFICHAGE DES LIENS

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
        list_room[i].IDlinked = -1;
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
    //on choisis toutes les rooms plus grande que 1.25 * la moyenne de toute les
    //rooms affichées
    float mean[2] = {0,0};
    moyenneRooms(mean);
    //mean[0] *= 0.75;
    //mean[1] *= 0.75;
    //NOTE: on ne met pas de unsigned int pour i car cette valeur peut prendre-1
    for (int i = 0; i < (int)list_room.size(); i++) {
        if ((list_room[i].H < mean[0]) || (list_room[i].L < mean[1])) {
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

void Map::initLinks() {
    for (int i = 0; i < (int)list_room.size(); i++) {
        choisirRoomLink(i);
    }
}


void Map::choisirRoomLink(int const ID) {
    //on initialise chaque liens dans un tableau et on en choisis un
    float distmin = 100000;
    int IDmin;
    int idist;
    for (int i = 0; i < (int)list_room.size(); i++) {
        if (!isRoomLinked(ID,i) && !(i == ID)) {
            idist = dist2Points(list_room[ID].X, list_room[ID].Y,list_room[i].X, list_room[i].Y);
            if(idist < distmin) {
                distmin = idist;
                IDmin = i;
            }
        }
    }
    list_room[ID].IDlinked = IDmin;
    cout << ID  << " -> " <<list_room[ID].IDlinked <<endl;;
}

bool const Map::isRoomLinked(int id1, int id2) {
    return (id1 == list_room[id2].IDlinked);
}

void Map::ajouterLinks(){
    int r, x0, y0, x1, y1, diffX, diffY;

    for(int i = 0; i < (int)list_room.size(); i++) {
        //ces variables "de transition" ne sont pas necessaire, elle sont
        //seulement là pour plus de lisibilité du code
        x0 = list_room[i].X;
        y0 = list_room[i].Y;
        r = list_room[i].IDlinked;
        x1 = list_room[r].X;
        y1 = list_room[r].Y;
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

float* Map::moyenneRooms(float mean[]) {

    for(unsigned int i = 0; i < list_room.size(); i++) {
        mean[0] += list_room[i].H;
        mean[1] += list_room[i].L;
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
        cout << "room " << i << " : " << list_room[i].H << ";" << list_room[i].L
        << " - " << list_room[i].X0 << ";" << list_room[i].Y0 << endl;
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
