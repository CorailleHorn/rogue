#ifndef ROOM_H
#define ROOM_H

class Room {
public:

	float x0, x1, y0, y1; //float pour les calculs
	int X0, X1, Y0, Y1; //arrondi en int pour les affichages
	int X, Y;  //coordonnees du centre de la room
	int H, L; //hauteur et largeur

	int IDlinked; // ID de la room lié

	void arrondValRoom();
	const bool isRoomIn(int const& size);

	void genInCircle(int const& map_size, int const& radius, int const& room_max_size, int const& room_min_size);
};


#endif
