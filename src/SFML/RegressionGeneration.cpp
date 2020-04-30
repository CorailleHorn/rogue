#include <iostream>
#include "Map.h"
#include "Personnages.h"

using namespace std;

int main(int argc, char *argv[])
{
	//on peut écrire la seed manuellement (utile en debug)
	//int const seed = 1588189442;
	// ... ou la générer avec time(NULL)
	int const seed = time(NULL);
	srand(seed);
	cout << seed << endl;
	Map* donjon = new Map();

	donjon->testRegression();

	delete donjon;
	donjon = NULL;

	return 0;
}
