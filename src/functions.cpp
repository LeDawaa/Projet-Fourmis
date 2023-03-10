#include "AllHeaders.h"

// Fonctions sur EnsCoord

EnsCoord creeEnsCoord2x2(Coord c) {
	auto t = c.getTupleCoord();
	int lig = std::get<0>(t);
	int col = std::get<1>(t);
	return EnsCoord({ Coord(lig, col), Coord(lig + 1, col), Coord(lig, col + 1), Coord(lig + 1, col + 1) });
}

EnsCoord creeEnsCoord4x4(Coord c) {
	auto t = c.getTupleCoord();
	int lig = std::get<0>(t);
	int col = std::get<1>(t);
	return EnsCoord({ Coord(lig - 1, col - 1), Coord(lig - 1, col), Coord(lig - 1, col + 1), Coord(lig - 1, col + 2),
		Coord(lig, col - 1), Coord(lig, col + 2),
		Coord(lig + 1, col - 1), Coord(lig + 1, col + 2),
		Coord(lig + 2, col - 1), Coord(lig + 2, col), Coord(lig + 2, col + 1), Coord(lig + 2, col + 2) });
}

EnsCoord voisines(Coord c) {
	auto t = c.getTupleCoord();
	int ligne = std::get<0>(t);
	int colonne = std::get<1>(t);
	int imin = std::max(ligne - 1, 0);
	int imax = std::min(ligne + 1, taillegrille - 1);
	int jmin = std::max(colonne - 1, 0);
	int jmax = std::min(colonne + 1, taillegrille - 1);
	EnsCoord ec;
	Coord ctemp(0, 0);
	for (int i = imin; i <= imax; i++) {
		for (int j = jmin; j <= jmax; j++) {
			Coord ctemp(i, j);
			if (ctemp != c) {
				ec.ajoute(ctemp);
			}
		}
	}
	return ec;
}

// Fonctions sur Place

bool plusProcheNid(Place p1, Place p2, int col) {
	return p1.getpheroNid(col) > p2.getpheroNid(col);
}

bool plusLoinNid(Place p1, Place p2, int col) {
	return not plusProcheNid(p1, p2, col);
}

// Fonctions sur fourmi

std::vector<fourmi> creeTabFourmis(EnsCoord e, int colo) {
	std::vector<fourmi> vfou;
	for (int i = 0; i < e.getTaille(); i++) {
		fourmi f(e.getIeme(i), colo, i);
		vfou.push_back(f);
	}
	return vfou;
}

//Fonctions sur Grille

Grille initialiseGrille(std::vector<fourmi> vfou, EnsCoord sucre, EnsCoord nid, int col) {
	Grille g;
	g.placeFourmi(vfou);
	g.placeSucre(sucre);
	g.placeNid(nid, col);
	return g;
}

void InitSucre() {
	std::vector<Coord> vsuc;
	for (int i = 0; i < taillegrille; i++) {
		Coord Cos((rand() % taillegrille), (rand() % 100));
		if (g.chargePlace(Cos).estVide()) {
			vsuc.push_back(Cos);
		}
		else {
			i--;
		}
	}
	EnsCoord ec(vsuc);
	g.placeSucre(ec);
}

//Fonctions sur Colonie

bool AppartientColonie(fourmi f1, fourmi f2) {
	return (f1.getNumColonie() == f2.getNumColonie());
}