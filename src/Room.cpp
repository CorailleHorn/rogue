#include <iostream>
#include <cmath>
#include "Room.h"

using namespace std;

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
