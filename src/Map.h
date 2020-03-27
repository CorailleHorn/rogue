#ifndef Map_H
#define Map_H

using namespace std;
#include "Room.h"
#include <vector>

class Map {
public:

    Map(int const size, int const nb, int const room_max_size,
        int const room_min_size, int const radius);
    ~Map();

    void initGeneration();

    void genInCircle(Room& R);
    void genInMap(Room& R);

    void genRooms();
    void eclatement();
    void chooseRooms();
    void initCenterRooms();
    void initLinks();

    void choisirRoomLink(unsigned int const ID);

    bool const allRoomsCollisions(unsigned int const ID);
    bool const roomCollision(Room A, Room B);

    void ajouterRooms();
    void updateRooms();

    void viderMap();
    void afficherMap();

private:

    int **ptr_map;
    vector<Room> list_room;

    int map_size;
    int nbrooms;
    int radius;
    int room_max_size;
    int room_min_size;
};


#endif /* Map_H */
