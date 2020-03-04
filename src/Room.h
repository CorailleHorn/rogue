#ifndef ROOM_H
#define ROOM_H
#include <iostream>

class Room {
public:
	float x0, x1, y0, y1; //float pour les calculs
	int X0, X1, Y0, Y1; //arrondi en int pour les affichages
	int X, Y;  //coordonnées du centre de la room
	int H, L;
	bool slc; //true si selectionné pour être une room
	int link; //compteur du nombre de liens avec les autres rooms (pour la gen  

};

#endif