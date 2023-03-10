#include "AllHeaders.h"

Grille g;

Grille::Grille() {
	for (int i = 0; i < taillegrille; i++) {
		for (int j = 0; j < taillegrille; j++) {
			Coord coo(i, j);
			Place pl(coo);
			pla.push_back(pl);
		}
	}
}

void Grille::placeNid(EnsCoord e, int col) {
	for (int i = 0; i < e.getTaille(); i++) {
		Place p = chargePlace(e.getIeme(i));
		p.poseNid();
		p.posePheroNid(col, 1);
		rangePlace(p);
	}
}

void Grille::placeSucre(EnsCoord e) {
	for (int i = 0; i < e.getTaille(); i++) {
		Place p = chargePlace(e.getIeme(i));
		p.poseSucre();
		rangePlace(p);
	}
}

void Grille::placeFourmi(std::vector<fourmi> vfou) {
	for (int i = 0; (unsigned)i < vfou.size(); i++) {
		Place p = chargePlace(vfou[i].getCoord());
		p.poseFourmi(vfou[i], vfou);
		rangePlace(p);
	}
}

void Grille::diminuePheroSucre() {
	for (int j = 0; (unsigned)j < pla.size(); j++) {
		pla[j].diminuePheroSucre();
	}
}

void Grille::deplaceFourmi(fourmi foufou, std::vector<fourmi>& vfou, Place p1, Place p2) {
	p2.poseFourmi(foufou, vfou);
	p1.enleveFourmi();
	rangePlace(p1);
	rangePlace(p2);
}

void Grille::rangePlace(Place p) {
	auto t = p.getCoord().getTupleCoord();
	pla[(std::get<0>(t) * taillegrille) + std::get<1>(t)] = p;
}

Place Grille::chargePlace(Coord c) {
	auto t = c.getTupleCoord();
	Place p = pla[(std::get<0>(t) * taillegrille + std::get<1>(t))];
	return p;
}

std::vector<Place> Grille::getGrilleVector() {
	return pla;
}

void Grille::afficher() {
	for (int i = 0; (unsigned)i < pla.size(); i++) {
		if (pla[i].contientNid()) {
			std::cout << "[N]";
		}
		else if (pla[i].contientSucre()) {
			std::cout << "[S]";
		}
		else if (pla[i].getNbFourmi() != -1) {
			std::cout << "[F]";
		}
		else {
			std::cout << "[ ]";
		}
		if ((i + 1) % taillegrille == 0 and i != 0) {
			std::cout << std::endl;
		}
		else {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void Grille::afficherpheroNid(int j) {
	for (int i = 0; (unsigned)i < pla.size(); i++) {
		if (pla[i].getpheroNid(j) == 0) {
			std::cout << "[0]";
		}
		else if (pla[i].getpheroNid(j) < 0.10) {
			std::cout << "[1]";
		}
		else if (pla[i].getpheroNid(j) < 0.20) {
			std::cout << "[2]";
		}
		else if (pla[i].getpheroNid(j) < 0.30) {
			std::cout << "[3]";
		}
		else if (pla[i].getpheroNid(j) < 0.40) {
			std::cout << "[4]";
		}
		else if (pla[i].getpheroNid(j) < 0.50) {
			std::cout << "[5]";
		}
		else if (pla[i].getpheroNid(j) < 0.60) {
			std::cout << "[6]";
		}
		else if (pla[i].getpheroNid(j) < 0.70) {
			std::cout << "[7]";
		}
		else if (pla[i].getpheroNid(j) < 0.80) {
			std::cout << "[8]";
		}
		else if (pla[i].getpheroNid(j) < 0.90) {
			std::cout << "[9]";
		}
		else {
			std::cout << "[10]";
		}
		if ((i + 1) % taillegrille == 0 and i != 0) {
			std::cout << std::endl;
		}
		else {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void Grille::lineariserPheroNid(int j) {
	int count = taillegrille;
	while (count > 0) {
		for (int i = 0; (unsigned)i < pla.size(); i++) {
			Place Pla = pla[i];
			float p = Pla.getpheroNid(j);
			if (p < 1) {
				float maxp = 0;
				EnsCoord ec = voisines(Pla.getCoord());
				for (int j = 0; j < ec.getTaille(); j++) {
					Place ptemp = chargePlace(ec.getIeme(j));
					if (ptemp.getpheroNid(j) > maxp) {
						maxp = ptemp.getpheroNid(j);
					}
				}
				if (((float)maxp - (1.0 / ((float)taillegrille))) > 0) {
					p = float((float)maxp - (1.0 / ((float)taillegrille)));
				}
				else {
					p = 0;
				}
				Pla.posePheroNid(j, p);
				rangePlace(Pla);
			}
		}
		count--;
	}
}

void Grille::TestIntegrite(std::vector<fourmi> vfou) {
	for (int i = 0; (unsigned)i < vfou.size(); i++) {
		if (vfou[i].getNum() != i) {
			throw std::runtime_error("Indice de fourmi non valide");
		}
	}
	for (int k = 0; k < taillegrille; k++) {
		for (int j = 0; j < taillegrille; j++) {
			Coord coo(k, j);
			if (pla[k * taillegrille + j].getCoord() != chargePlace(coo).getCoord()) {
				throw std::runtime_error("Coordonnées des places non valides");
			}
		}
	}
}

void Grille::TestCoherence(std::vector<fourmi> vfou, int colo) {
	for (int i = 0; (unsigned)i < vfou.size(); i++) {
		if (vfou[i].estVivante()) {
			Place p = chargePlace(vfou[i].getCoord());
			if (p.getNbFourmi() != i) {
				throw std::runtime_error("Coordonnées des fourmis non valides");
			}
		}
	}
	for (int j = 0; (unsigned)j < pla.size(); j++) {
		if (pla[j].getNbFourmi() != -1 and pla[j].getFourmi().getNumColonie() == colo) {
			try {
				fourmi f = vfou[pla[j].getNbFourmi()];
			}
			catch (std::out_of_range& e) {
				throw std::runtime_error("Fourmi sur la grille mais pas dans le tableau");
				exit(EXIT_FAILURE);
			}
			catch (...) {
				throw std::runtime_error("Erreur inconnue sur fourmis");
				exit(EXIT_FAILURE);
			}
		}
	}
}

TEST_CASE("TEST GRILLE") {
	Grille gr;

	std::vector<fourmi> vf = creeTabFourmis(EnsCoord({ Coord(3, 3) }), 0);
	CHECK(not gr.chargePlace(Coord(1, 1)).contientNid());
	CHECK(not gr.chargePlace(Coord(2, 2)).contientSucre());
	CHECK(not gr.chargePlace(Coord(3, 3)).contientFourmi());
	gr.placeNid(EnsCoord({ Coord(1, 1) }), 0);
	gr.placeSucre(EnsCoord({ Coord(2, 2) }));
	gr.placeFourmi(vf);
	CHECK(gr.chargePlace(Coord(1, 1)).contientNid());
	CHECK(gr.chargePlace(Coord(2, 2)).contientSucre());
	CHECK(gr.chargePlace(Coord(3, 3)).contientFourmi());
	Place pp = gr.chargePlace(Coord(4, 4));
	pp.poseSucre();
	gr.rangePlace(pp);
	CHECK(gr.chargePlace(Coord(4, 4)).contientSucre());
	CHECK(gr.chargePlace(Coord(5, 5)).estVide());
	gr.deplaceFourmi(vf[0], vf, gr.chargePlace(Coord(3, 3)), gr.chargePlace(Coord(5, 5)));
	CHECK(gr.chargePlace(Coord(3, 3)).estVide());
	CHECK(gr.chargePlace(Coord(5, 5)).contientFourmi());
	Place ppp = gr.chargePlace(Coord(6, 6));
	ppp.posePheroSucre(0);
	gr.rangePlace(ppp);
	CHECK(gr.chargePlace(Coord(6, 6)).getpheroSucre(0) == 255);
	gr.diminuePheroSucre();
	CHECK(gr.chargePlace(Coord(6, 6)).getpheroSucre(0) == 250);
}