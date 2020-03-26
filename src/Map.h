#ifndef Map_H
#define Map_H

using namespace std;
#include "Room.h"
#include <vector>

class Map {
public:

    Map();
    Map(int const size, int const nb);
    ~Map();

    int const getSize();
    int const getNbRooms();

    void viderMap();
    void ajouterRooms(Room list_room[]);
    void afficherMap();
private:
    int map_size;
    int **ptr_map;
    int nbrooms;
};


#endif /* Map_H */
