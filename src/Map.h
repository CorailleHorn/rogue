#ifndef Map_H
#define Map_H

#include <vector>
#include "Room.h"
#include "Personnages.h"

struct Corridor {
    int x0,y0,X,Y,x1,y1;
};

class Map {
public:
    Map(int const& size, int const& nb, int const& radius, int const& room_max_size,
        int const& room_min_size);
    Map();
    ~Map();

    void initGeneration();
    void initGenerationDebug();
    void testRegression();

    void genRooms();
    void eclatement();
    void chooseRooms();
    void initLinks();

    void choisirRoomLink(int const ID);
	bool const isRoomLinked(int ID1, int ID2);
	void ajouterLinks();

	void genCorridors();
	void ajouterCorridors();
	bool const isPointIn(int const X, int const Y, int const ID);

    bool const allRoomsCollisions(unsigned int const ID);
    float* moyenneRooms(float mean[]);

    void ajouterRooms();
    void updateRooms();

    void viderMap();
    void afficherMap();

private:

    int **ptr_map;
    std::vector<Room> list_room;
    std::vector<Corridor> list_corridor;

    int map_size, nbrooms, radius, room_max_size, room_min_size;
    //Hero hero;
    //std::vector<Ennemi> ennemis;
};



#endif /* Map_H */
