#include <iostream>
#include "Map.h"

using namespace std;

int main(int argc, char *argv[], char **envp)
{
	//on peut écrire la seed manuellement ...
	//int seed = 132892952984;
	//srand(seed);
	// ... ou la générer avec time(NULL)
	int const seed = time(NULL);
	srand(seed);

	int const map_size = 90;
	int const nbrooms = 50;//comme pour les dimensions on ne conservera pas toutes les rooms generees
    int const room_max_size = 20; //ces dimensions sont uniquement pour la génération les dimensions réél sont séléctionner dans chooseRooms
    int const room_min_size = 3;
    int const radius = 10;

    Map *donjon = new Map(map_size, nbrooms, room_max_size, room_min_size, radius);

	donjon->initGeneration();

	delete donjon;

	return 0;
}
