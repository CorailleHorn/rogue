#ifndef ROOM_H
#define ROOM_H

class Room {
public:

	//accesseur
	int getIDlinked();

	float getx0();
	float getx1();
	float gety0();
	float gety1();

	int getX0();
	int getX1();
	int getY0();
	int getY1();

	int getX();
	int getY();
	int getH();
	int getL();

	//mutateur
	void setIDlinked(int const& val);

	void setx0(float const& val);
	void setx1(float const& val);
	void sety0(float const& val);
	void sety1(float const& val);

	void arrondValRoom();
	bool const isRoomIn(int const& size);

	void genInCircle(int const& map_size, int const& radius, int const& room_max_size, int const& room_min_size);
	bool const roomCollision(Room& A);

    void initCenterRooms();




private:
	int X, Y;  //coordonnees du centre de la room
	int IDlinked; // ID de la room lié
	float x0, x1, y0, y1; //float pour les calculs
	int X0, X1, Y0, Y1; //arrondi en int pour les affichages
	int H, L; //hauteur et largeur
};


#endif
