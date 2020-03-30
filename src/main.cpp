#include "txtJeu.h"

using namespace std;

int main() {
	srand(time(NULL));
	Hero* h;
	system("clear");
	txtBoucle(h);
	system("clear");
	delete h;
	h = NULL;
	return 0;
}
