#ifndef Map_H
#define Map_H

#include <vector>
#include <utility> //pour utiliser pair<type,type>
#include <string>
#include "Room.h"
#include "Personnages.h"

//structure couloir contenant des tableaux dynamiques des coordonees de chaques points des couloirs
struct Corridor {
  std::vector<std::pair<int,int>> layer;
};

class Map {
public:
    //METHODES

    Map(int const size, int const nb, int const radius, int const room_max_size,
        int const room_min_size); //constructeur surchargé avec les paramètres de création
    Map(Hero *h); //constructeur surchargé avec le hero
    Map(); //constructeur
    ~Map(); //destructeur

    void initGeneration(); //initialisation de la génération
    void testRegression(); //initialisation de la génération
    void genRooms(); //génération des salles (rooms)
    void eclatement(); //procédure ou on éclate les rooms dans toutes les directions en leurs donnant une physique
    void chooseRooms(); //on séléctionne les rooms que l'on souhaite garder, on supprime les autres

    void initLinks(); //initialisation des liens entres les rooms afin de pouvoir les relier avec des couloirs (Algorithme de PRIM)
    void ajouterLinks(); //ajout des liens dans la map pour pouvoir les visualiser, pour afficher les couloirs, utiliser ajouterCorridorsSFML() après génération des couloirs

    void genCorridors(); //generation des valeurs des couloirs (dans le tableau de structure couloir : list_corridor)
    void ajouterCorridorsSFML();//ajout des valeurs des couloirs pour la SFML dans map

    bool const isPointInCorridor(int const X, int const Y, unsigned int const ID = -1); //renvoi si le point est dans un couloirs, ajouter un id de couloir si le point est celui d'un couloir à générer
    bool const isPointInRoom(int const X, int const Y, std::string const &param = "inc"); //renvoi si un point est dans une room, voir doc pour les parametre

    float* moyenneRooms(float mean[]); //renvoie un tableau mean[Hauteur float, Largeur float] renvoyant la moyenne des hauteurs et des largeurs de toutes les rooms

    void ajouterRoomsTXT();//ajoute les rooms pour l'affichage terminal
    void ajouterRoomsSFML();//ajoute les rooms pour l'affichage en SFML
    void updateRooms();//met à jour les rooms avec des positions en int qui était en float

    int newPosHero();
    int update();
    int position_valide(const int &x, const int &y);
    int size();


    void viderMap(); //vide la map i.e. met toute les valeurs de la map à 0
    void afficherMapTXT(); //affiche la version shell de la map en terminal
    void afficherMapSFML();//affiche la version graphique de la map en terminal [uniquement en debug]


private:
    //METHODES
    int priorite(const std::vector<std::pair<bool, float>> &prio); // renvoie le plus petit élément du tableau prio
    bool const allRoomsCollisions(unsigned int const ID); //teste si une des rooms entre en collisions avec une des autres rooms présente dans list_room

    //ATTRIBUTS
    int **ptr_map; //pointeur de pointeurs sur des tableaux de pointeurs (x) pointant sur des tableaux (y) avec pour valeurs : 0 vide; 1 mur; 2 sol;
    std::vector<Room> list_room; //tableau contenant des objets de type Room, correspondant aux salles du donjon
    std::vector<Corridor> list_corridor; //tableau contenant des structures de type Corridor, correspondant aux couloirs du donjon

    int map_size, nbrooms, radius, room_max_size, room_min_size, nb_ennemie;
    //taille de la map, nombre de rooms, radian , taille max d'une room en H et L, taille min d'une room en H et L, nombres d'ennemies
    int hxm1, hym1;
    //Hero *hero;
    //std::vector<Ennemi*> ennemis;
};



#endif /* Map_H */
