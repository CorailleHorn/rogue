#include <iostream>
#include "Map.h"

using namespace std;

int main(int argc, char *argv[], char **envp)
{
	//on peut écrire la seed manuellement ...
	//int seed = 1585401860;
	// ... ou la générer avec time(NULL)
	int const seed = time(NULL);
	srand(seed);

	cout << "LA SEED EST " << seed <<endl;

	int const map_size = 90;
	int const nbrooms = 100;//comme pour les dimensions on ne conservera pas toutes les rooms generees
	int const radius = 5;
	int const room_max_size = 20; //ces dimensions sont uniquement pour la génération les dimensions réél sont séléctionner dans chooseRooms
    int const room_min_size = 5;

    Map *donjon = new Map(map_size, nbrooms, radius, room_max_size, room_min_size);

	donjon->initGeneration();

	delete donjon;

	return 0;
}
