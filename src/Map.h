#ifndef Map_H
#define Map_H

#include <vector>
#include <utility>
#include <string>
#include "Room.h"
#include "Personnages.h"

struct Corridor {
  std::vector<std::pair<int,int>> layer;
};

class Map {
public:
  Map(int const& size, int const& nb, int const& radius, int const& room_max_size,
      int const& room_min_size);
  Map(Hero *h);
  Map();
  ~Map();

  void initGeneration();
  void initGenerationDebug();
  void testRegression();

  void genRooms();
  void eclatement();
  void chooseRooms();

  void initLinks();
  int priorite(std::vector<std::pair<bool, float>> prio);

  void choisirRoomLink(int const ID);
  bool const isRoomLinked(int ID1, int ID2);
  void ajouterLinks();

  void genCorridors();
  void ajouterCorridorsTXT();
  void ajouterCorridorsSimpleSFML();
  void ajouterCorridorsSFML();
  bool const isPointInCorridor(int const &X, int const &Y, int const &ID);
  bool const isPointInRoom(int const &X, int const &Y, std::string param);

  bool const allRoomsCollisions(unsigned int const ID);
  float* moyenneRooms(float mean[]);

  void ajouterRoomsTXT();
  void ajouterRoomsSFML();
  void updateRooms();

  int newPosHero();
  int update();
  bool position_valide(const int &x, const int &y);



  void viderMap();
  void afficherMapTXT();
  void afficherMapSFML();

  void afficherTout();
private:

  int **ptr_map;
  std::vector<Room> list_room;
  std::vector<Corridor> list_corridor;

  int map_size, nbrooms, radius, room_max_size, room_min_size, nb_ennemie;
  int hxm1, hym1;
  int nb_corridors;
  //Hero *hero;
  //std::vector<Ennemi*> ennemis;
};



#endif /* Map_H */
