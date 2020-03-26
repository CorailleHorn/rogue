#include <iostream>
#include <cmath>
#include <vector>
#include "Map.h"
#include "Room.h"

using namespace std;


Map::Map() : map_size(100), nbrooms(50) {

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
}

Map::Map(int const size, int const nb) : map_size(size), nbrooms(nb) {

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
}

Map::~Map() {
  //on libère la mémoire du tableau 2D map
  for (int i = 0; i < map_size; i++) {
      delete[] ptr_map[i];
  }
  delete[] ptr_map;
}

int const Map::getSize() {
    return map_size;
}

int const Map::getNbRooms() {
    return nbrooms;
}

void Map::viderMap() {
    //on fabrique la map : 0:vide 1:plein
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            ptr_map[i][j] = 0;
        }
    }
}

void Map::ajouterRooms(Room list_room[]) {
    //ajouter l'affichage des rooms dans la map
    //on arrondi d'abord les valeurs
    for (int i = 0; i < nbrooms; i++) {
        if (list_room[i].slc) {
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
            //ptr_map[list_room[i].X0 + (int)round(list_room[i].L / 2)][list_room[i].Y0 + (int)round(list_room[i].H / 2)] = i;

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
