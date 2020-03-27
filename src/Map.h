#ifndef Map_H
#define Map_H

#include <vector>
#include "Room.h"



class Map {
public:
	struct Link {
		int n;//numero de la room adjacente lié
		float dist; //distance à cette rooms
	};

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

    void choisirRoomLink(int const ID);
	bool const isRoomLinked(int ID1, int ID2);
	void ajouterLinks();

    bool const allRoomsCollisions(unsigned int const ID);
    bool const roomCollision(Room A, Room B);
    float* moyenneRooms(float mean[]);

    void ajouterRooms();
    void updateRooms();

    void viderMap();
    void afficherMap();

private:

    int **ptr_map;
    std::vector<Room> list_room;

    int map_size;
    int nbrooms;
    int radius;
    int room_max_size;
    int room_min_size;
};



#endif /* Map_H */
