    // Projet_Rogue.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include "Room.h"
#include "Corridor.h"
#include "Map.h"
using namespace std;

//On définit la constante Pi
long double const PI = 3.1415926535897932384626433832795028841968;

double genRandomDouble() {
    return ((double)rand() / (RAND_MAX));
}

float dist2Points(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}



const bool roomCollision(Room *A, Room *B) {

    //detecte si B entre en collision avec A
    if((B->x0 >= A->x0 + A->L)      // trop à droite
	|| (B->x0 + B->L <= A->x0) // trop à gauche
	|| (B->y0 >= A->y0 + A->H) // trop en bas
 	|| (B->y0 + B->H <= A->y0))  // trop en haut
        return false;
    else return true;
}

const bool allRoomsCollisions(int ID, Room list_room[], int nbrooms) {
    //vérifie si la room au rang ID entre en collision avec toutes les autres rooms
    for (int i = 0; i < nbrooms; i++) {
        //on test avec roomCollision pour toutes les autres rooms
        if (i != ID) {
            if (roomCollision(&list_room[i], &list_room[ID])) {
                return true;
            }
        }
    }
    return false;
}

void updateRooms(Room list_room[], int nbrooms,int map_size) {
    for(int i = 0; i < nbrooms; i++) {
        if(list_room[i].slc){
            list_room[i].arrondValRoom();
            if(list_room[i].isRoomIn(map_size)) {
                cout << "room " << i << " : " << list_room[i].H << ";" << list_room[i].L << " - " << list_room[i].X0 << ";" << list_room[i].Y0 << endl;
            }
            else list_room[i].slc = false;
        }
    }
}

void genInMap(Room& R, int max, int min, int map_size) {
    R.H = (rand() % (max - min)) + min;//hauteur
    R.L = (rand() % (max - min)) + min;//largeur
    R.x0 = rand() % (map_size - R.L); //x0 en évitant de sortir de la map : gen entre 0 - largeur
    R.y0 = rand() % (map_size - R.H); //y0
    R.x1 = R.x0 + R.L - 1; //x1
    R.y1 = R.y0 + R.H - 1; //y1
}

void genInCircle(Room& R, int max, int min, int radius, int map_size) {
    //on genere des tailles aléatoire
    R.H = (rand() % (max - min)) + min;//hauteur
    R.L = (rand() % (max - min)) + min;//largeur

    //on genere des points aléatoires dans un cercle
    float t = 2 * PI * genRandomDouble();
    float u = genRandomDouble() + genRandomDouble();
    float r;
    if (u > 1) r = (2 - u);
    else r = u;

    R.x0 = (radius * r * cos(t)) + (map_size/2);
    R.y0 = (radius * r * sin(t)) + (map_size/2);
    R.x1 = R.x0 + R.L - 1;
    R.y1 = R.y0 + R.H - 1;
}

void genRooms(Room list_room[], int nbrooms, int room_max_size, int room_min_size, int radius, int map_size)  {
    for (int i = 0; i < nbrooms; i++) {
        list_room[i].slc = true;
        //Tech1 on gen les rooms sur la map alea
        //genInMap(list_room[i], room_max_size, room_min_size, map_size);
        //Tech2 on gen les rooms dans un cercle, puis on "éclate" les particules
        genInCircle(list_room[i],room_max_size, room_min_size, radius, map_size);
    }
}


void eclatement(Room list_room[], int nbrooms) {
    //on "éclate" les rooms
    //pour chaque room on la déplace suivant un angle variant sur le cercle tant qu'elle est en collision avec une des rooms de la map

    for (int i = 0; i < nbrooms; i++) {
        while (allRoomsCollisions(i,list_room, nbrooms)) {

            list_room[i].x0 += (cos(((i + 1.0) * PI) / (nbrooms / 2)));
            list_room[i].y0 += (sin(((i + 1.0) * PI) / (nbrooms / 2)));
            list_room[i].x1 = list_room[i].x0 + list_room[i].L - 1;
            list_room[i].y1 = list_room[i].y0 + list_room[i].H - 1;
        }
    }
}

void chooseRooms(Room list_room[], int nbrooms) {
    //on choisis les rooms en fonction des parametres voulus
    for (int i = 0; i < nbrooms; i++) {
        if ((list_room[i].H < 7) || (list_room[i].L < 7)) {
            list_room[i].slc = false;
        }
    }
}

void initCenterRooms(Room list_room[], int nbrooms) {
    //on place les centres des rooms utilisé (slc = true)
    for (int i = 0; i < nbrooms; i++) {
        if (list_room[i].slc) {
            if ((list_room[i].L % 2) == 0) list_room[i].X = list_room[i].L / 2;
            else list_room[i].X = (int)(list_room[i].L / 2) + (rand() % 2);

            if ((list_room[i].H % 2) == 0) list_room[i].Y = list_room[i].H / 2;
            else list_room[i].Y = (int)(list_room[i].H / 2) + (rand() % 2);
        }
    }
}


/*
void initLinks(int nbrooms, Room list_room[]) {
    //on va créer des liens (des rooms) pour chaques
    for (int i = 0; i < nbrooms; i++) {
        if (list_room[i].slc) {
            createLink(i,list_room);
        }
    }
}
*/

int main(int argc, char *argv[], char **envp)
{
    //INITIALISATION des constantes,

    //on peut écrire la seed manuellement ...
    //int seed = 132892952984;
    //srand(seed);
    // ... ou la générer avec time(NULL)
    int const seed = time(NULL);
    srand(seed);

    //parametre des rooms et du terrain pour la generation
    int const map_size = 90;
    int const room_max_size = 25; //ces dimensions sont uniquement pour la génération les dimensions réél sont séléctionner dans chooseRooms
    int const room_min_size = 3;
    int const radius = 5;
    int const nbrooms = 100;//comme pour les dimensions on ne conservera pas toutes les rooms generees

    Map *donjon = new Map(map_size, nbrooms);
    //création du terrain : chaque case dans un tableau dynamique de coordonnées (x,y)
    //on initialise un pointeur de pointeur donjon.ptr_map pointant sur un tableau de pointeur alloué dynamiquement sur le tas
    // => chaque "cases" du terrain map 0:vide 1:plein

    //on initialise un pointeur list_room pointant sur un tableau de Room
    Room *list_room = new Room[nbrooms];
    // On crée un tableau de rooms

    //GENERATION
    //on genere les rooms
    genRooms(list_room, nbrooms, room_max_size, room_min_size, radius, map_size);
    //comme on manipule des coordonnees de type float on les arrondis en entier avec updateRooms
    updateRooms(list_room, nbrooms, map_size);

    //AFFICHAGE
    //on affiche les rooms
    //on ajoute les affichages des rooms dans le tableau de la map donjon
    donjon->ajouterRooms(list_room);
    donjon->afficherMap();
    //on onblie pas de vider le tableau pour pouvoir mettre à jours l'aspect
    donjon->viderMap();

    //on procède à l'éclatement en cercle
    eclatement(list_room, nbrooms);
    updateRooms(list_room, nbrooms, map_size);

    donjon->ajouterRooms(list_room);
    donjon->afficherMap();
    donjon->viderMap();

    //on choisis les rooms qui possède un aspect jouable
    chooseRooms(list_room, nbrooms);
    updateRooms(list_room, nbrooms, map_size);

    donjon->ajouterRooms(list_room);
    donjon->afficherMap();
    //on ne vide pas le tableau car on conservera ces rooms dans la version finale

    //Generation des couloirs


    //initCenterRooms(&(*list_room));
    delete donjon;
    delete[] list_room;


    return 0;
}
