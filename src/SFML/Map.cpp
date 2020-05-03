#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <assert.h>
#include "Map.h"
#include "Room.h"

using namespace std;
//on créer un constante PI pour les calculs utilisant de la trigonométrie
long double const PI = 3.1415926535897932384626433832795028841968;

//fonction retournant un float de la distance entre deux points (x1,y1) et (x2,y2)
float dist2Points(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

//constructeur surchargé de map prenant plusieurs paramètres (voir doc)
Map::Map(int const size, int const nb, int const rad, int const max, int const min) :
    map_size(size), nbrooms(nb), radius(rad), room_max_size(max), room_min_size(min) {
    //on "fabrique" la map ptr_map, pointeur de pointeur
    ptr_map = new int*[map_size];
    //on initialise les pointeurs sur des valeurs nulles
    for (int i = 0; i < map_size; i++) {
      ptr_map[i] = nullptr;
    }

    //on affecte a chaque pointeur du tableau, un tableau alloué dynamiquement
    for (int i = 0; i < map_size; i++) {
      ptr_map[i] = new int[map_size];
    }
    //on fabrique la map : 0:vide 1:plein
    viderMap();
    list_room.resize(nbrooms);
}

/*Map::Map(Hero *h) : Map() {
  hero = h;
}*/

//constructeur par défaut de map
Map::Map() : Map(90,100,5,20,5) {} //param par defaut

Map::~Map() {
  //on libère la mémoire du tableau 2D map
  for (int i = 0; i < map_size; i++) {
      delete[] ptr_map[i];
  }
  delete[] ptr_map;

}


void Map::initGeneration() { //on lance la generation complete
    genRooms(); //on genere les rooms dans un cercle
    eclatement();//on procede a l'eclatement des rooms en leur donnant une physique (et donc un vecteur de deplacement)
    updateRooms();//on "met a jour" les rooms affichables (a l'interieur de map)
    chooseRooms();//on selectionne les rooms avec un aspect jouable
    ajouterRoomsSFML();//on ajoute les rooms dans la map physiquement

    initLinks(); //on initialise les liens pour pouvoir ensuite gen les couloirs
    genCorridors();// on gen les couloirs

    ajouterCorridorsSFML();  // on ajoute les chemins des couloirs avec les murs telles qu'on les veut pour l'affichage graphique
    //afficherMapSFML(); // on affiche la map ; inutile en graphique
    //viderMap(); // on vide la map i.e. on remet tout les valeurs de map à 0; PENSER à la commenter pour pouvoir utiliser les donner de maps après génération
/*
    int pos[2];
    for(long unsigned int i = 1; i < list_room.size(); i++) {
      nb_ennemie = rand() % 2 + 1;
      for(int j = 0; j < nb_ennemie; j++) {
        if(ennemis.size() == 0) {
          pos[0] = rand() % (list_room[i].getX0()-(list_room[i].getX0() + list_room[i].getL() - 1) ) + (list_room[i].getX0()+1);
          pos[1] = rand() % (list_room[i].getY0()-(list_room[i].getY0() + list_room[i].getH() - 1) ) + (list_room[i].getY0()+1);
        }
        else {
          do {
            pos[0] = rand() % (list_room[i].getX0()-(list_room[i].getX0() + list_room[i].getL() - 1) ) + (list_room[i].getX0()+1);
            pos[1] = rand() % (list_room[i].getY0()-(list_room[i].getY0() + list_room[i].getH() - 1) ) + (list_room[i].getY0()+1);
          } while(ennemis[ennemis.size()-1]->getX() == pos[0]
            && ennemis[ennemis.size()-1]->getY() == pos[1]);
        }
        ennemis.push_back(new Ennemi(hero->getLv()));
        ennemis[ennemis.size()-1]->setX(pos[0]);
        ennemis[ennemis.size()-1]->setY(pos[1]);
      }
    }
    hxm1 = list_room[0].getX();
    hym1 =list_room[0].getY();
    hero->setX(hxm1);
    hero->setY(hym1);
    ptr_map[hxm1][hym1] = 2;*/
}


void Map::testRegression() { //on lance le test de regression
    //dans ces tests on vérifie après chaque parties de la Generation la
    //"viabilite" des variables, i.e qu'elles ne depassent pas les regles qui
    //leurs sont donnees, les tableaux, que les pointeurs sont bien remis sur NULL
    //après utilisation, etc
    //et ensuite on affiche en detail la generation step by step (comme dans initGenerationDebug() )

    //TEST : CONSTRUCTEUR PAR DEFAUT + DESTRUCTEUR

    Map* M = new Map;
    assert(M->map_size == 90);
    assert(M->nbrooms == 100);
    assert(M->radius == 5);
    assert(M->room_max_size == 20 && M->room_min_size == 5);
    for (int i = 0; i < M->map_size; i++) {
        for (int j = 0; j < M->map_size; j++) {
          assert(M->ptr_map[i][j] == 0);
        }
    }
    assert((int)M->list_room.size() == M->nbrooms);
    delete M;
    M = NULL;
    assert(M == NULL);

    //TEST : CONSTRUCTEUR SURCHAGE ET GENERATION
    //STEP 0 : ON GENERE LA CLASS MAP
    Map M2(90,100,5,20,5);
    assert(M2.map_size == 90);
    assert(M2.nbrooms == 100);
    assert(M2.radius == 5);
    assert(M2.room_max_size == 20 && M2.room_min_size == 5);
    for(int i = 0; i < M2.map_size; i++) {
        for (int j = 0; j < M2.map_size; j++) {
          assert(M2.ptr_map[i][j] == 0);
        }
    }
    assert((int)M2.list_room.size() == M2.nbrooms);
    for(int i = 0; i < M2.nbrooms; i++) {
        assert(M2.list_room[i].getx0() == 0);
        assert(M2.list_room[i].gety0() == 0);
        assert(M2.list_room[i].getX0() == 0);
        assert(M2.list_room[i].getY0() == 0);
        assert(M2.list_room[i].getX() == 0);
        assert(M2.list_room[i].getY() == 0);
        assert(M2.list_room[i].getIDlinked() == 0);
    }
    M2.afficherMapTXT();

    //STEP 1 : ON GENERE LES ROOMS
    M2.genRooms();
    for(int i = 0; i < M2.nbrooms; i++) {
        assert((M2.list_room[i].getx0() >= 0)
            && (M2.list_room[i].gety0() >= 0)
            && ((M2.list_room[i].getx0() + M2.list_room[i].getL() - 1)  < map_size)
            && ((M2.list_room[i].gety0() + M2.list_room[i].getH() - 1) < map_size));
        assert(M2.list_room[i].getIDlinked() == -1);
    }
    M2.updateRooms();
    //on parcoure ici pour une taille nbrooms car toutes les rooms sont affichables pour l'instant
    for(int i = 0; i < M2.nbrooms; i++) {
        assert(M2.list_room[i].isRoomIn(M2.map_size));
    }
    M2.ajouterRoomsTXT();
    for(int i = 0; i < M2.nbrooms; i++) {
        //lignes pour l'affichage des données des rooms
        cout<< "room " << i << " : " << M2.list_room[i].getH() << ";"
        << M2.list_room[i].getL() << " - " << M2.list_room[i].getX0() << ";"
        << M2.list_room[i].getY0() << endl;
    }
    M2.afficherMapTXT();
    M2.viderMap();

    //STEP 2 : ON ECLATE LES ROOMS
    M2.eclatement();
    for (int i = 0; i < nbrooms; i++) {
        assert(!allRoomsCollisions(i));
    }
    M2.updateRooms();
    for(int i = 0; i < (int)M2.list_room.size(); i++) {
        assert(M2.list_room[i].isRoomIn(M2.map_size));
    }
    M2.ajouterRoomsTXT();
    for(int i = 0; i < (int)M2.list_room.size(); i++) {
        //lignes pour l'affichage des données des rooms
        cout<< "room " << i << " : " << M2.list_room[i].getH() << ";"
        << M2.list_room[i].getL() << " - " << M2.list_room[i].getX0() << ";"
        << M2.list_room[i].getY0() << endl;

        //ligne pour l'affichage des numéros des rooms
        M2.ptr_map[M2.list_room[i].getX()][M2.list_room[i].getY()] = i;
    }
    M2.afficherMapTXT();
    M2.viderMap();

    //STEP 3 : ON SELECTIONNE LES ROOMS
    M2.chooseRooms();
    M2.ajouterRoomsTXT();
    for(int i = 0; i < (int)M2.list_room.size(); i++) {
        //lignes pour l'affichage des données des rooms
        cout<< "room " << i << " : " << M2.list_room[i].getH() << ";"
        << M2.list_room[i].getL() << " - " << M2.list_room[i].getX0() << ";"
        << M2.list_room[i].getY0() << endl;

        //ligne pour l'affichage des numéros des rooms
        M2.ptr_map[M2.list_room[i].getX()][M2.list_room[i].getY()] = i;
    }

    M2.afficherMapTXT();

    //STEP 4 : ON GENERE LES LIENS
    M2.initLinks(); //on initialise les liens pour pouvoir ensuite gen les couloirs
    for(int i = 0; i < (int)M2.list_room.size(); i++) {
        assert(M2.list_room[i].getIDlinked() != i);
        //ligne pour afficher les liens de manière condensé
        //NOTE :Ligne mis en comm car bug non resolu
        //assert(M2.list_room[i].getIDlinked() != i);

    }
    M2.ajouterLinks();
    for(int i = 0; i < (int)M2.list_room.size(); i++) {
        //ligne pour afficher les liens de manière condensé
        cout << i  << " -> " <<M2.list_room[i].getIDlinked() <<endl;;
    }
    M2.afficherMapTXT();
    M2.viderMap();

    //STEP 5 : ON AJOUTE LES COULOIRS A PARTIR DES LIENS CREES
    M2.genCorridors();

    M2.ajouterRoomsTXT();
    for(int i = 0; i < (int)M2.list_corridor.size(); i++) {
        for(int j = 0; j < (int)M2.list_corridor[i].layer.size(); j++) {
            int x = M2.list_corridor[i].layer[j].first;
            int y = M2.list_corridor[i].layer[j].second;
            M2.ptr_map[x][y] = -1;
        }
    }
    for(int i = 0; i < (int)M2.list_room.size(); i++) {
        //lignes pour l'affichage des données des rooms
        cout<< "room " << i << " : " << M2.list_room[i].getH() << ";"
        << M2.list_room[i].getL() << " - " << M2.list_room[i].getX0() << ";"
        << M2.list_room[i].getY0() << endl;

        //ligne pour l'affichage des numéros des rooms
        M2.ptr_map[M2.list_room[i].getX()][M2.list_room[i].getY()] = i;
    }
    M2.afficherMapTXT();


    //STEP 7 : ON AFFICHE LA VERSION POUR LA SFML
    M2.viderMap();
    M2.ajouterRoomsSFML();
    M2.ajouterCorridorsSFML();
    M2.afficherMapSFML();

}


void Map::genRooms()  {
    for (int i = 0; i < nbrooms; i++) {

        //on gen les rooms dans un cercle, puis on "éclate" les particules
        list_room[i].genInCircle(map_size, radius, room_max_size, room_min_size);
        //on initialise tout les liens à -1
        list_room[i].setIDlinked(-1);
    }
}

void Map::eclatement() {
    //on "éclate" les rooms
    //pour chaque room on la déplace suivant un angle variant sur le cercle tant qu'elle est en collision avec une des rooms de la map

    for (unsigned int i = 0; i < list_room.size(); i++) {
        //tant que toutes les autres rooms sont en collision avec la room que l'on déplace
        while (allRoomsCollisions(i)) {
            //déplacement de la room dans toutes les directions du cercle trigonométrique
            list_room[i].setx0(list_room[i].getx0() +  (cos(((i + 1.0) * PI) / (nbrooms / 2))));
            list_room[i].sety0(list_room[i].gety0() + (sin(((i + 1.0) * PI) / (nbrooms / 2))));
        }
    }
}

void Map::chooseRooms() {
    //on choisis toutes les rooms plus grande que la moyenne de toute les
    //rooms affichées
    float mean[2] = {0,0};
    moyenneRooms(mean);
    //dans ces lignes on peut choisir si on veut un plus grand nombre de rooms en divisant la moyenne
    //mean[0] *= 0.75;
    //mean[1] *= 0.75;
    //NOTE: on ne met pas de unsigned int pour i car cette valeur peut prendre-1
    for (int i = 0; i < (int)list_room.size(); i++) {
        if ((list_room[i].getH() < mean[0]) || (list_room[i].getL() < mean[1])) {
            list_room.erase(list_room.begin() + i); // suppression de la room du tableau
            i--;
        }
    }
}


void Map::initLinks() {
    //on initialise les liens entres les centres des rooms pour ensuite générer des couloirs allant d'un centre à l'autre

    //version utilisant l'algorithme de PRIM–DIJKSTRA
    //pour trouver un arbre de liens couvrant toutes les centres des rooms et qui soit de poid minimal
    //pour plus d'informations : https://fr.wikipedia.org/wiki/Algorithme_de_Prim

    //tableau de priorité contenant un boolean (true si déjà lié) et les "poids" ou priorités de chaque id de rooms
    //par la suite on choisira une a une les rooms par leurs poids dans un ordre croissant
    vector<pair<bool, float>> prio;
    //on initialise toutes les rooms comme n'ayant pas été lié
    // et on leur donne une une valeur très grande
    for(int i = 0; i < (int)list_room.size(); i++) {
        prio.push_back(make_pair(false, 100000));
    }
    //On commence au sommet de la room 0 en lui donnant la plus faible valeur (elle passera donc en priorité)
    prio[0].second = 0;

    int p;
    float arrete;
    //pour toute les rooms -1 car il faut q'il reste au moins deux rooms valides à étudier
    for(int k = 0; k < (int)list_room.size() - 1; k++) {
        //p prend les valeurs de l'element a la priorite la plus importante i.e. la valeur la plus petite
        p = priorite(prio);
        prio[p].first = true;
        //on teste si on peut la lié aux autres rooms
        for(int i = 0; i < (int)list_room.size(); i++){
            //on verifie qu'on etudie une arrete entre deux éléments différents (pour éviter des calculs supplémentaire)
            if(p != i) {
                //on calcule la distance entre le centre de la room p et de la room i
                arrete = dist2Points(list_room[p].getX(), list_room[p].getY(), list_room[i].getX(), list_room[i].getY());
                //si la room est valide et que son arrete et inferieur à au poid de I qui correspond [si déjà modifié] au poid de son arrete précédente
                if(prio[i].first == false && prio[i].second >= arrete) {
                    //on lie
                    list_room[i].setIDlinked(p);
                    //le poids de i devient la distance entre p et i
                    prio[i].second = arrete;
                }
            }
        }

    }

}

int Map::priorite(const vector<pair<bool, float>> &prio) {
    //retourne l'indice de la valeur la plus petite dans le tableau prio soit le poid minimal
    float min = 10000000.0;
    int p;
    for(int i = 0; i < (int)list_room.size(); i++) {
        if(prio[i].first == false && prio[i].second < min) {
            p = i;
            min = prio[i].second;
        }
    }
    return p;
}

void Map::ajouterLinks(){
    //on ajoute les liens sur la map pour mieux visualiser si la gen est correct
    //ici pas d'aléatoire ni de génération propre car on utilisera uniquement cette fonction en debug

    int r, x0, y0, x1, y1, diffX, diffY;
    //ces variables "de transition" ne sont pas necessaire, elle sont
    //seulement là pour plus de lisibilité du code

    for(int i = 0; i < (int)list_room.size(); i++) {
        //on récupère le lien de la room
        r = list_room[i].getIDlinked();
        //si le lien existe
        if(r != -1) {
            x0 = list_room[i].getX();
            y0 = list_room[i].getY();
            x1 = list_room[r].getX();
            y1 = list_room[r].getY();
            diffX = x0 - x1;
            diffY = y0 - y1;
            //si le second point est à un x supérieur premier
            //on ajoute a la map les points allant d'un x à l'autre
            if( diffX <= 0) {
                for (int j = 0; j < abs(diffX); j++) {
                    ptr_map[x0 + j][y0] = -1;
                }
            }
            else{
                for (int j = 0; j < diffX; j++) {
                    ptr_map[x0 - j][y0] = -1;
                }
            }
            //si le second point est à un y supérieur premier
            if( diffY <= 0) {
                for (int j = 0; j < abs(diffY); j++) {
                    ptr_map[x1][y0 + j] = -1;
                }
            }
            else{
                for (int j = 0; j < diffY; j++) {
                    ptr_map[x1][y0 - j] = -1;
                }
            }
        }
    }
}

void Map::genCorridors() {
    //on génère les couloirs procéduralement en deux lignes de droite d'un centre à l'autre
    int id2, x, y, r, incx, incy;
    int id_corridor = 0;
    pair<int,int>  pair1, pair2; //on créer
    Corridor a; //on créer un couloir a, couloir de base
    a.layer.resize(0);

    for(int i = 0; i < (int)list_room.size(); i++) {
        //on donne à id2 l'indice de la room liée
        id2 = list_room[i].getIDlinked();
        //si ce lien existe
        if(id2 != -1) {
            //on initialise le couloir dans le tableau de couloirs
            list_corridor.push_back(a);
            //coordonnées du centre de la room i point de départ du couloir
            x = list_room[i].getX();
            y = list_room[i].getY();

            //on fait commencer les couloirs en ordonnée ou en abcisse suivant la valeur de r
            r = rand() % 2 - 1; //0 ou 1
            if (r) { // si on commence par un couloir de type y
                //point de flexion du couloir a mi chemin entre la room i et id2
                pair1 = make_pair(list_room[i].getX(), list_room[id2].getY());

                //incrementeur des y en fonction de la direction à prendre
                if(pair1.second > y) incy = 1;
                else incy = -1;

                //tant qu'on a pas atteint le point de flexion on ajoute les blocs
                while( y != pair1.second ) {
                    //on place les "bloc" du couloir successivement si le point est n'est pas dans room (bords exclues)
                    y += incy;
                    if(!isPointInRoom(x, y, "exc"))
                        list_corridor[id_corridor].layer.push_back(make_pair(x,y));
                }
                //point d'arrivé = centre de la room id2
                pair2 = make_pair(list_room[id2].getX(), list_room[id2].getY());

                //incrementeur des x en fonction de la direction à prendre
                if(pair2.first > x) incx = 1;
                else incx = -1;
                //tant qu'on a pas atteint le point de flexion on ajoute les blocs
                while( x != pair2.first ) {
                    //on place les "bloc" du couloir successivement si le point est n'est pas dans room (bords exclues)
                    x += incx;
                    if(!isPointInRoom(x, y, "exc"))
                        list_corridor[id_corridor].layer.push_back(make_pair(x,y));
                }

            }
            else {// si on commence par un couloir de type x
                pair1 = make_pair(list_room[id2].getX(), list_room[i].getY());

                if(pair1.first > x) incx = 1;
                else incx = -1;

                while( x != pair1.first ) {
                    x += incx;
                    if(!isPointInRoom(x, y, "exc"))
                        list_corridor[id_corridor].layer.push_back(make_pair(x,y));

                }
                pair2 = make_pair(list_room[id2].getX(), list_room[id2].getY());

                if(pair2.second > y) incy = 1;
                else incy = -1;

                while( y != pair2.second ) {
                    y += incy;
                    if(!isPointInRoom(x, y, "exc"))
                        list_corridor[id_corridor].layer.push_back(make_pair(x,y));

                }
            }
            //la taille de list_corridor est differente de list_room car une room peut ne pas etre liée
            //on incremente le compteur id_cooridor uniquement si on viens de creer le layer du couloir precedent
            id_corridor++;
        }

    }
}


void Map::ajouterCorridorsSFML() {
    //version d'affichage graphique en SFML
    //on ajout ici à la map les couloirs avec les murs
    int x,y;
    for(int i = 0; i < (int)list_corridor.size(); i++) {
        for(int j = 0; j < (int)list_corridor[i].layer.size(); j++) {
            //
            x = list_corridor[i].layer[j].first;
            y = list_corridor[i].layer[j].second;
            //on ajoute le chemin i.e. dans tout les cas (on a déjà testé dans la génération si on passait dans une room)
            ptr_map[x][y] = 2;
            //ajoute les murs tout autour de chaque coordonees de chemins si l'endroit est vide donc égale à 0
            if(ptr_map[x-1][y-1] == 0)
                ptr_map[x-1][y-1] = 1;
            if(ptr_map[x-1][y] == 0)
                ptr_map[x-1][y] = 1;
            if(ptr_map[x-1][y+1] == 0)
                ptr_map[x-1][y+1] = 1;
            if(ptr_map[x][y-1] == 0)
                ptr_map[x][y-1] = 1;
            if(ptr_map[x][y+1] == 0)
                ptr_map[x][y+1] = 1;
            if(ptr_map[x+1][y-1] == 0)
                ptr_map[x+1][y-1] = 1;
            if(ptr_map[x+1][y] == 0)
                ptr_map[x+1][y] = 1;
            if(ptr_map[x+1][y+1] == 0)
                ptr_map[x+1][y+1] = 1;
        }
    }
}




bool const Map::isPointInCorridor(int const X, int const Y, unsigned int const ID) {
    //test si le point du couloir ID passe a travers un couloir déjà affiché
    for(unsigned int i = 0; i < ID; i++) {
        //on test si le point correspond à un point déjà définis
        for(int j = 0; j < (int)list_corridor[i].layer.size() ; j++) {
            if(((X == list_corridor[i].layer[j].first)
            &&  (Y == list_corridor[i].layer[j].second)))
                return true;
        }
    }
    return false;
}
bool const Map::isPointInRoom(int const X, int const Y, string const &param) {
    //test si point est dans une room avec différent parametre possible (voir doc)
    //bords inclues
    if(param == "inc") {
        for(int i = 0; i < (int)list_room.size(); i++) {
            if((X >= list_room[i].getX0())
            &&  (X <= (list_room[i].getX0() + list_room[i].getL() - 1) )
            &&  (Y >= list_room[i].getY0())
            &&  (Y <= (list_room[i].getY0() + list_room[i].getH() - 1) ))
                return true;
        }
    }
    //bords exclues
    else if (param == "exc") {
        for(int i = 0; i < (int)list_room.size(); i++) {
            if((X > list_room[i].getX0())
            &&  (X < (list_room[i].getX0() + list_room[i].getL() - 1) )
            &&  (Y > list_room[i].getY0())
            &&  (Y < (list_room[i].getY0() + list_room[i].getH() - 1) ))
                return true;
        }
    }
    //bords seulement
    else if (param =="bords") {
        for(int i = 0; i < (int)list_room.size(); i++) {
            if(((X == list_room[i].getX0()) ||  (X == (list_room[i].getX0() + list_room[i].getL() - 1) ))
            && ((Y == list_room[i].getY0()) ||  (Y == (list_room[i].getY0() + list_room[i].getH() - 1) )))
                return true;
        }
    }

    return false;
}

bool const Map::allRoomsCollisions(unsigned int const ID) {
    //vérifie si la room au rang ID entre en collision avec toutes les autres rooms
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on test avec roomCollision pour toutes les autres rooms
        if (i != ID) {
            if (list_room[i].roomCollision(list_room[ID])) {
                return true;
            }
        }
    }
    return false;
}

float* Map::moyenneRooms(float mean[]) {
    //renvoie la moyenne des tailles en Largeur et Hauteur de toutes les rooms dans la map
    for(unsigned int i = 0; i < list_room.size(); i++) {
        mean[0] += list_room[i].getH();
        mean[1] += list_room[i].getL();
    }
    mean[0] /= list_room.size();
    mean[1] /= list_room.size();
    return mean;
}


void Map::ajouterRoomsTXT() {
    //ajouter l'affichage des rooms dans la map
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on ajoute la largeur des rooms
        // j parcourant la largeur de la room
        for (int j = 0; j < list_room[i].getL(); j++) {
            ptr_map[list_room[i].getX0() + j][list_room[i].getY0()] = 1;
            ptr_map[list_room[i].getX0() + j][(list_room[i].getY0() + list_room[i].getH() - 1) ] = 1;
        }
        //on ajoute la hauteur des rooms
        // k parcourant la hauteur de la room
        for (int k = 0; k < list_room[i].getH(); k++) {
            ptr_map[list_room[i].getX0()][list_room[i].getY0() + k] = 1;
            ptr_map[(list_room[i].getX0() + list_room[i].getL() - 1) ][list_room[i].getY0() + k] = 1;
        }
    }
}

void Map::ajouterRoomsSFML() {
    //ajouter les valeurs d'affichage de la map
    for (unsigned int i = 0; i < list_room.size(); i++) {
        //on ajoute la largeur des rooms
        // j parcourant la largeur de la room
        for (int j = 0; j < list_room[i].getL(); j++) {
            ptr_map[list_room[i].getX0() + j][list_room[i].getY0()] = 1;
            ptr_map[list_room[i].getX0() + j][(list_room[i].getY0() + list_room[i].getH() - 1) ] = 1;
        }
        //on ajoute la hauteur des rooms
        // k parcourant la hauteur de la room
        for (int k = 0; k < list_room[i].getH(); k++) {
            ptr_map[list_room[i].getX0()][list_room[i].getY0() + k] = 1;
            ptr_map[(list_room[i].getX0() + list_room[i].getL() - 1) ][list_room[i].getY0() + k] = 1;
        }
        //on ajout l'interieur des rooms
        for (int j = 1; j < list_room[i].getH() - 1; j++) {
            for(int k = 1; k < list_room[i].getL() - 1; k++) {
                ptr_map[list_room[i].getX0() + k][list_room[i].getY0() + j] = 2;
            }
        }
    }
}

void Map::updateRooms() {
    //cette methode s'assure que les rooms soit affichables dans la map
    for(int i = 0; i < (int)list_room.size(); i++) {
        //on arrondis les valeurs des coordonnees des rooms
        list_room[i].arrondValRoom();
        //et on verifie que les rooms ne sont pas dans la map
        if(!list_room[i].isRoomIn(map_size)) {
            //et on les supprime du tableau dynamique
            list_room.erase(list_room.begin() + i);
            i--;
        }
    }
}

/*int Map::update() {
  newPosHero();
  for(unsigned int i = 0; i < ennemis.size(); i++) {
    ptr_map[ennemis[i]->getX()][ennemis[i]->getY()] = 0;
    if(position_valide(ennemis[i]->getX(),(ennemis[i]->getY() + 1))
      && hero->getY() < ennemis[i]->getY())
      ennemis[i]->Haut();
    if(position_valide(ennemis[i]->getX(),(ennemis[i]->getY() - 1))
      && hero->getY() > ennemis[i]->getY())
      ennemis[i]->Bas();
    if(position_valide((ennemis[i]->getX() - 1),ennemis[i]->getY())
      && hero->getX() < ennemis[i]->getX())
      ennemis[i]->Gauche();
    if(position_valide((ennemis[i]->getX() + 1),ennemis[i]->getY())
      && hero->getX() > ennemis[i]->getX())
      ennemis[i]->Droite();
    ptr_map[ennemis[i]->getX()][ennemis[i]->getY()] = 3;
  }
  return 0;
}*/

int Map::size() {
  return map_size;
}

void Map::positionnement(Hero *hero, std::vector<Ennemi*> &ennemis) {
  int pos[2];
  for(long unsigned int i = 1; i < list_room.size(); i++) {
    nb_ennemie = rand() % 2 + 1;
    for(int j = 0; j < nb_ennemie; j++) {
      if(ennemis.size() == 0) {
        pos[0] = rand() % (list_room[i].getX0()-(list_room[i].getX0() + list_room[i].getL() - 1) ) + (list_room[i].getX0()+1);
        pos[1] = rand() % (list_room[i].getY0()-(list_room[i].getY0() + list_room[i].getH() - 1) ) + (list_room[i].getY0()+1);
      }
      else {
        do {
          pos[0] = rand() % (list_room[i].getX0()-(list_room[i].getX0() + list_room[i].getL() - 1) ) + (list_room[i].getX0()+1);
          pos[1] = rand() % (list_room[i].getY0()-(list_room[i].getY0() + list_room[i].getH() - 1) ) + (list_room[i].getY0()+1);
        } while(ennemis[ennemis.size()-1]->getX() == pos[0]
            && ennemis[ennemis.size()-1]->getY() == pos[1]);
      }
      ennemis.push_back(new Ennemi(hero->getLv()));
      ennemis[ennemis.size()-1]->setX(pos[0]);
      ennemis[ennemis.size()-1]->setY(pos[1]);
    }
  }
  hxm1 = list_room[0].getX();
  hym1 = list_room[0].getY();
  hero->setX(hxm1);
  hero->setY(hym1);
  ptr_map[hxm1][hym1] = 2;
}

void Map::viderMap() {
    //on vide la map i.e. on remet toutes les valeurs à 0
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            ptr_map[i][j] = 0;
        }
    }
}

void Map::afficherMapTXT() {
    //on affiche dans le terminal lignes par lignes avec les codes voulu
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (ptr_map[j][i] == 0) cout << "  ";
            else if (ptr_map[j][i] == 1) cout << "##";
            else if (ptr_map[j][i] == -1) cout << "XX";
            else if (ptr_map[j][i] < 10) cout << " " << ptr_map[j][i]; //petite modif pour afficher les num des rooms
            else cout << ptr_map[j][i];
        }
        cout << endl;
    }
    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;
}

void Map::afficherMapSFML() {
    // [DEBUG UNIQUEMENT] on affiche dans le terminal lignes par lignes la version qu'on envoie pour la sfml
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (ptr_map[j][i] == 0) cout <<"  ";
            else if (ptr_map[j][i] == 2) cout << " 2";
            else cout <<"##";
        }
        cout << endl;
    }
    //on affiche une ligne de **
    for (int i = 0; i < map_size; i++) {
        cout << "**";
    }
    cout << endl;
}

//ACCESSEUR

int Map::getValueMap(int const X, int const Y) {
    //retourne la valeur de map en X et Y
    return ptr_map[X][Y];
}
//accesseur pour les rooms
int Map::getX0Room(int const ID){
    return list_room[ID].getX0();
}

int Map::getY0Room(int const ID){
    return list_room[ID].getY0();
}

int Map::getXRoom(int const ID){
    return list_room[ID].getX();
}

int Map::getYRoom(int const ID){
    return list_room[ID].getY();
}

int Map::getHRoom(int const ID){
    return list_room[ID].getH();
}

int Map::getLRoom(int const ID){
    return list_room[ID].getL();
}
