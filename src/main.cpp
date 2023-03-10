#include "AllHeaders.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main() {
	Colonie a(Coord(25, 25));
	Colonie b(Coord(75, 25));
	Colonie c(Coord(25, 75));
	Colonie d(Coord(75, 75));

	std::vector<Colonie> vco{ a, b, c, d };

	InitSucre();

	int count = 800;
	while (count != 0) {
		dessinerFourmilliere(g);
		for (int k = 0; k < NbColonies; k++) {
			vco[k].RulerOfAnts(vco);
		}
		g.diminuePheroSucre();
		count--;
	}
	return 0;
}