#include <iostream>
#include <cmath>
#include "Room.h"

using namespace std;

long double const PI = 3.1415926535897932384626433832795028841968;

double genRandomDouble() {
    return ((double)rand() / (RAND_MAX));
}

void Room::arrondValRoom() {
    //on arrondi les valeurs des rooms
    X0 = round(x0);
    X1 = round(x1);
	Y0 = round(y0);
    Y1 = round(y1);
}

const bool Room::isRoomIn(int map_size) {
    //vérifie si la room est dans la map
    if ((X0 >= 0) && (Y0 >= 0) && (X1 < map_size) && (Y1 < map_size)) return true;
    else return false;
}


void Room::genInCircle(int const map_size, int const radius, int const room_max_size, int const room_min_size) {
    //on genere des tailles aléatoire
    H = (rand() % (room_max_size - room_min_size)) + room_min_size;//hauteur
    L = (rand() % (room_max_size - room_min_size)) + room_min_size;//largeur

    //on genere des points aléatoires dans un cercle
    float t = 2 * PI * genRandomDouble();
    float u = genRandomDouble() + genRandomDouble();
    float r;
    if (u > 1) r = (2 - u);
    else r = u;

    x0 = (radius * r * cos(t)) + (map_size/2);
    y0 = (radius * r * sin(t)) + (map_size/2);
    x1 = x0 + L - 1;
    y1 = y0 + H - 1;
}
