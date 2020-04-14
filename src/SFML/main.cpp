#include "Jeu.h"

using namespace std;

int main() {
	srand(time(NULL));
	Hero* h = new Hero;
	system("clear");
	Boucle(h);
	system("clear");
	delete h;
	h = NULL;
	return 0;
}
