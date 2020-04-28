#include "SFMLJeu.h"

using namespace std;

int main() {
	srand(time(NULL));
	Hero* h = new Hero;
	Boucle(h);
	delete h;
	h = NULL;
	return 0;
}
