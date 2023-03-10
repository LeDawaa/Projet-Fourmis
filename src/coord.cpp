#include "AllHeaders.h"

Coord::Coord(int lig, int col) {
	try {
		if (lig >= taillegrille or col >= taillegrille) {
			throw std::invalid_argument("Coordonnees en dehors de la grille");
		}
		else if (lig < 0 or col < 0) {
			throw std::invalid_argument("Coordonnees non valides");
		}
		else {
			ligne = lig;
			colonne = col;
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

Coord::Coord() {
	ligne = -1;	colonne = -1;
}

std::tuple<int, int> Coord::getTupleCoord() {
	return { ligne, colonne };
}

std::ostream& operator<<(std::ostream& out, Coord c) {
	auto t = c.getTupleCoord();
	int ligne, colonne;
	ligne = std::get<0>(t);
	colonne = std::get<1>(t);
	out << "(" << std::setfill('0') << std::setw(2) << ligne << "," << std::setfill('0') << std::setw(2) << colonne << ")";
	return out;
}

bool operator==(Coord c1, Coord c2) {
	auto t1 = c1.getTupleCoord();
	int ligne1, colonne1;
	ligne1 = std::get<0>(t1);
	colonne1 = std::get<1>(t1);
	auto t2 = c2.getTupleCoord();
	int ligne2, colonne2;
	ligne2 = std::get<0>(t2);
	colonne2 = std::get<1>(t2);

	if (ligne1 == ligne2) {
		if (colonne1 == colonne2) {
			return true;
		}
	}
	return false;
}

bool operator!=(Coord c1, Coord c2) {
	return (not (c1 == c2));
}

TEST_CASE("TEST COORD") {
	Coord c1(15, 5);
	Coord c2(12, 13);
	Coord c3(5, 7);
	Coord c4(15, 12);
	Coord c5(17, 16);
	Coord c6(18, 14);
	Coord c7(11, 2);
	Coord c8(6, 8);
	Coord c9(15, 5);
	Coord c10(5, 7);
	Coord c11(18, 14);

	std::tuple <int, int> coord;
	coord = std::make_tuple(15, 5);
	CHECK(c1.getTupleCoord() == coord);
	coord = std::make_tuple(6, 8);
	CHECK(c8.getTupleCoord() == coord);
	coord = std::make_tuple(13, 7);
	CHECK(c5.getTupleCoord() != coord);

	CHECK(c9 == c1);
	CHECK(c3 == c10);
	CHECK(c6 == c11);

	CHECK(c3 != c6);
	CHECK(c2 != c8);
	CHECK(c6 != c1);
}