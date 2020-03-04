// Projet_Rogue.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include "Room.h"
#include "Corridor.h"
using namespace std;

int const nbrooms = 50;

long double const pi = 3.1415926535897932384626433832795028841968;

double genRandomFloat() {
    return ((double)rand() / (RAND_MAX));
}

int arrondir(float e) {
    float res = e - (int)e;
    if (res >= 0.5) return ((int)e + 1);
    else return (int)e;
}

float dist2Points(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}


void arrondValRoom(Room& R) {
    //on arrondi les valeurs des rooms 
    R.X0 = arrondir(R.x0);
    R.X1 = arrondir(R.x1);
    R.Y0 = arrondir(R.y0);
    R.Y1 = arrondir(R.y1);
}



const bool room_collision(Room *A, Room *B) {
    
    //detecte si B entre en collision avec A
    if((B->x0 >= A->x0 + A->L)      // trop à droite
	|| (B->x0 + B->L <= A->x0) // trop à gauche
	|| (B->y0 >= A->y0 + A->H) // trop en bas
 	|| (B->y0 + B->H <= A->y0))  // trop en haut
        return false; 
   else return true; 
}

const bool allRoomsCollisions(int ID, Room list_room[]) {
    //vérifie si la room au rang ID entre en collision avec toutes les autres rooms
    for (int i = 0; i < nbrooms; i++) {
        //on test avec room_collision pour toutes les autres rooms
        if (i != ID) { 
            if (room_collision(&list_room[i], &list_room[ID])) {
                return true;
            }
        }
    }
    return false;
}

const bool isRoomIn(Room& R, int map_size) {
    //vérifie si la room est dans la map
    if ((R.X0 >= 0) && (R.Y0 >= 0) && (R.X1 < map_size) && (R.Y1 < map_size)) return true;
    else return false;
}

void createLink(int ID, Room list_room[]) {
    float tabLinks[nbrooms - 1];



}


void map_vide(int map_size,int **ptr_map) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            ptr_map[i][j] = 0;
        }
    }
}

void map_avec_room(int map_size, Room list_room[], int **ptr_map) {
    //ajouter l'affichage des rooms dans la map
    //on arrondi d'abord les valeurs 
    for (int i = 0; i < nbrooms; i++) {
        arrondValRoom(list_room[i]);
        if (list_room[i].slc && isRoomIn(list_room[i], map_size)) {
            //on ajoute la largeur des rooms
            // j parcourant la largeur de la room
            for (int j = 0; j < (list_room[i].L); j++) {
                ptr_map[list_room[i].X0 + j][list_room[i].Y0] = 1;
                ptr_map[list_room[i].X0 + j][list_room[i].Y1] = 1;
            }
            //on ajoute la hauteur des rooms
            for (int k = 0; k < (list_room[i].H); k++) {
                ptr_map[list_room[i].X0][list_room[i].Y0 + k] = 1;
                ptr_map[list_room[i].X1][list_room[i].Y0 + k] = 1;
            }
            //on affiche le num de la room
            ptr_map[list_room[i].X0 + arrondir(list_room[i].L / 2)][list_room[i].Y0 + arrondir(list_room[i].H / 2)] = i;

        }
       
    }
}

void afficheMap(int map_size, int **ptr_map) {
    //on affiche dans le terminal ligne par ligne
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {

            if (ptr_map[j][i] == 0) cout << "  ";
            else if (ptr_map[j][i] == 1) cout << "##";
            else if (ptr_map[j][i] < 10) cout << " " << ptr_map[j][i];
            else cout << ptr_map[j][i];
        }
        cout << endl;
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
    float t = 2 * pi * genRandomFloat();
    float u = genRandomFloat() + genRandomFloat();
    float r;
    if (u > 1) r = (2 - u);
    else r = u;
    
    R.x0 = (radius * r * cos(t)) + (map_size/2); 
    R.y0 = (radius * r * sin(t)) + (map_size/2);
    R.x1 = R.x0 + R.L - 1; 
    R.y1 = R.y0 + R.H - 1;
}

void eclatement(Room list_room[]) {
    //on "éclate" les rooms
    //pour chaque room on la déplace suivant un angle variant sur le cercle tant qu'elle est en collision avec une des rooms de la map

    for (int i = 0; i < nbrooms; i++) {
        while (allRoomsCollisions(i,list_room)) {

            list_room[i].x0 += (cos(((i + 1.0) * pi) / (nbrooms / 2)));
            list_room[i].y0 += (sin(((i + 1.0) * pi) / (nbrooms / 2)));
            list_room[i].x1 = list_room[i].x0 + list_room[i].L - 1;
            list_room[i].y1 = list_room[i].y0 + list_room[i].H - 1;
        }
    }
}

void chooseRooms(Room list_room[]) {
    //on choisis les rooms en fonction des parametres voulus
    for (int i = 0; i < nbrooms; i++) {
        if ((list_room[i].H < 7) || (list_room[i].L < 7)) {
            list_room[i].slc = false;
        }
    }
}

void initCenterRooms(Room list_room[]) {
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



void initLinks(int nbrooms, Room list_room[]) {
    //on va créer des liens (des rooms) pour chaques 
    for (int i = 0; i < nbrooms; i++) {
        if (list_room[i].slc) {
            createLink(i,list_room);
        }
    }
}


int main()
{
    //INITIALISATION
  
    //on peut écrire la seed manuellement ou la générer avec time(NULL)
    //int seed = 132892952984;
    //srand(seed);
    srand(time(NULL));
    //parametre des rooms et du terrain
    int const map_size = 100;
    int const room_max_size = 20;
    int const room_min_size = 3;
    int const radius = 5;

     
    //création du terrain : chaque case dans un tableau dynamique de coordonnées (x,y)
    //on initialise un pointeur de pointeur ptr_map pointant sur un tableau de pointeur alloué dynamiquement sur le tas
    int **ptr_map = new int*[map_size];
    
    //on initialise les pointeurs sur des valeurs nulles
    for (int i = 0; i < map_size; i++) {
        ptr_map[i] = nullptr;
    }
    //on affecte a chaque pointeur du tableau un tableau alloué dynamiquement 
    for (int i = 0; i < map_size; i++) {
        ptr_map[i] = new int[map_size];
    }
    
    //on initialise un pointeur list_room pointant sur un tableau de Room
    Room *list_room = new Room[nbrooms];
    // On crée un tableau de rooms 
   

    //GENERATION
    //on fabrique la map : 0:vide 1:plein

    map_vide(map_size, ptr_map);


    //on genere les room
    for (int i = 0; i < nbrooms; i++) {
        list_room[i].slc = true;
        //Tech1 on gen les rooms sur la map alea
        //genInMap(list_room[i], room_max_size, room_min_size, map_size);
        //Tech2 on gen les rooms dans un cercle, puis on "éclate" les particules
        genInCircle(list_room[i], room_max_size, room_min_size, radius, map_size);
        cout << "room " << i << " : " << list_room[i].H << ";" << list_room[i].L << " - " << list_room[i].x0 << ";" << list_room[i].y0 << endl;
    }


    map_avec_room(map_size, &(*list_room), ptr_map);
    afficheMap(map_size, ptr_map);
    map_vide(map_size, ptr_map);
    
    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;

    eclatement(&(*list_room));
    initLinks(&(*list_room));

    
    //AFFICHAGE


    map_avec_room(map_size,&(*list_room), ptr_map);
    afficheMap(map_size, ptr_map);
    map_vide(map_size, ptr_map);

    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;

    
    chooseRooms(&(*list_room));
   
    map_avec_room(map_size, &(*list_room), ptr_map);
    afficheMap(map_size, ptr_map);
    map_vide(map_size, ptr_map);

    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;

    initCenterRooms(&(*list_room));


    map_avec_room(map_size, &(*list_room), ptr_map);
    afficheMap(map_size, ptr_map);
    map_vide(map_size, ptr_map);

    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;

    //on libère la mémoire du tableau 2D map
    for (int i = 0; i < map_size; i++) {
        delete[] ptr_map[i];
    }
    delete[] ptr_map;

    delete[] list_room;
    

    return 0;
} 