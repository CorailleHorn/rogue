#ifndef ROOM_H
#define ROOM_H

class Room {
//classe Room (salles) contenant principalement les coordonnees des salles, la hauteur et la largeur
public:
	//Méthode
	//Accesseur
	int getIDlinked(); //obtenir l'id de la room à laquel this est lié

	float getx0(); //retourne la coordonnee x0 du point en haut à gauche de la room en float
	float gety0(); //retourne la coordonnee y0 du point en haut à gauche de la room en float

	int getX0(); //retourne la coordonnee X0 du point en haut à gauche de la room en entier
	int getY0(); //retourne la coordonnee Y0 du point en haut à gauche de la room en entier

	int getX(); //retourne la coordonnee X du centre de la room
	int getY(); //retourne la coordonnee Y du centre de la room
	int getH(); //retourne la hauteur H de la room
	int getL(); //retourne la largeur L de la room

	//Mutateur
	void setIDlinked(int const val); //modifier l'id de la room à laquel this est lié
	void setx0(float const val); // modifier la coordonnee x0 du point en haut à gauche de la room en float
	void sety0(float const val);  // modifier la coordonnee y0 du point en haut à gauche de la room en float

	void arrondValRoom();  // arrondis la valeurs de coordonees x0 et y0 en entier X0 et Y0
 	bool const isRoomIn(int const size); //renvoi un boolean si la room est dans la map de taille size

	// génération aléatoire d'une room dans un cercle de rayon radius dans une map de taille map_size avec des tailles spécifiées
	void genInCircle(int const map_size, int const radius, int const room_max_size, int const room_min_size);
	bool const roomCollision(Room& A); //test si une room A entre en collision avec this






private:
	//METHODES
    void initCenterRooms(); // on créer les valeurs des centres des rooms [TOUJOURS UTILISER APRES arrondValRoom]

	//ATTRIBUTS
	int X, Y;  //coordonnees du centre de la room
	int IDlinked; // ID de la room lié
	float x0, y0; //coordonees du point en haut à gauche de la room en float pour les calculs
	int X0, Y0; //arrondi en int pour les affichages
	int H, L; //hauteur et largeur
};


#endif
