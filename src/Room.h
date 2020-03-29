#ifndef ROOM_H
#define ROOM_H

class Room {
public:

	//accesseur
	int getIDlinked();
	//mutateur
	void setIDlinked(int const& val);


	void arrondValRoom();
	bool const isRoomIn(int const& size);

	void genInCircle(int const& map_size, int const& radius, int const& room_max_size, int const& room_min_size);
	bool const roomCollision(Room& A);

    void initCenterRooms();

	float x0, x1, y0, y1; //float pour les calculs
	int X0, X1, Y0, Y1; //arrondi en int pour les affichages
	int X, Y;  //coordonnees du centre de la room
	int H, L; //hauteur et largeur
	
private:
	int IDlinked; // ID de la room lié

};


#endif
