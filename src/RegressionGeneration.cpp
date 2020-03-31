#include <iostream>
#include "Map.h"
#include "Personnages.h"

using namespace std;

int main(int argc, char *argv[])
{
	//on peut écrire la seed manuellement ...
	//int seed = 1585612957;
	// ... ou la générer avec time(NULL)
	int const seed = time(NULL);
	srand(seed);
	cout << seed << endl;
	Map* donjon = new Map();
	//donjon->initGenerationDebug();
	donjon->testRegression();

	delete donjon;
	donjon = NULL;

	return 0;
}
