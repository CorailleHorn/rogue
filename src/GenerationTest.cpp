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

	Map* donjon = new Map;
	//donjon->initGenerationDebug();
	donjon->testRegression();

	delete donjon;
	donjon = NULL;

	return 0;
}
