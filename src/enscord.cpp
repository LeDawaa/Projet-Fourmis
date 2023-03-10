#include "AllHeaders.h"

EnsCoord::EnsCoord(std::vector<Coord> C) {
	Co = C;
}

EnsCoord::EnsCoord() {
	Co = {};
}

bool EnsCoord::contient(Coord c) {
	return getPosition(c) != -1;
}

bool EnsCoord::estVide() {
	return Co.size() == 0;
}

void EnsCoord::ajoute(Coord c) {
	if (contient(c) == false) {
		Co.push_back(c);
	}
}

void EnsCoord::supprime(Coord c) {
	try {
		if (contient(c) == true) {
			Co.erase(Co.begin() + getPosition(c));
		}
		else {
			throw std::invalid_argument("Coordonnees en dehors du tableau");
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int EnsCoord::getPosition(Coord c) {
	for (int i = 0; (unsigned)i < Co.size(); i++) {
		if (Co[i] == c) {
			return i;
		}
	}
	return -1;
}

int EnsCoord::getTaille() {
	return Co.size();
}

Coord EnsCoord::getIeme(int c) {
	return Co[c];
}

Coord EnsCoord::choixHasard() {
	return Co[rand() % Co.size()];
}

std::vector<Coord> EnsCoord::getEnsCoord() {
	return Co;
}

std::ostream& operator<<(std::ostream& out, EnsCoord e) {
	std::vector<Coord> Co = e.getEnsCoord();
	int size = Co.size();
	for (int i = 0; i < size; i++) {
		out << Co[i] << " ";
		if ((i > 0) and ((i + 1) % taillegrille == 0)) {
			out << std::endl;
		}
	}
	return out;
}

TEST_CASE("TEST ENSCOORD") {
	std::vector<Coord> vc;

	EnsCoord co1(vc);
	CHECK(co1.estVide() == true);
	CHECK(co1.getTaille() == 0);
	CHECK(co1.getPosition(Coord(1, 1)) == -1);

	Coord c1(15, 5);
	Coord c2(12, 13);
	Coord c3(5, 7);
	Coord c4(15, 12);
	vc.push_back(c1); vc.push_back(c2); vc.push_back(c3); vc.push_back(c4);
	EnsCoord co2(vc);
	CHECK(co2.estVide() == false);
	CHECK(co2.getTaille() == 4);

	Coord c5(17, 16);
	Coord c6(18, 14);
	Coord c7(11, 2);
	Coord c8(6, 8);
	vc.push_back(c5); vc.push_back(c6); vc.push_back(c7); vc.push_back(c8);
	EnsCoord co3(vc);
	CHECK(co3.getTaille() == 8);
	co3.ajoute(c1);
	CHECK(co3.getTaille() == 8);
	Coord c9(1, 1);
	co3.ajoute(c9);
	CHECK(co3.getTaille() == 9);
	co3.supprime(c1);
	CHECK(co3.getTaille() == 8);
	CHECK(co3.contient(c1) == false);
	CHECK(co3.getIeme(3) == c5);
	CHECK(co3.getPosition(Coord(1, 1)) == 7);
	vc = { Coord(1,1), Coord(2,2) };
	EnsCoord co4(vc);
	Coord c = co4.choixHasard();
	bool b = (c == Coord(1, 1)) || (c == Coord(2, 2));
	CHECK(b);
	EnsCoord ec = voisines(Coord(1, 1));
	vc = { Coord(0,0), Coord(0,1), Coord(0,2), Coord(1,0), Coord(1,2), Coord(2,0), Coord(2,1), Coord(2,2) };
	CHECK(ec.getEnsCoord() == vc);
}