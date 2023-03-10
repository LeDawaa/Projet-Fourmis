#include "AllHeaders.h"

int compteurcolonies = 0;

Colonie::Colonie(Coord nid) {
	nbv = compteurcolonies;
	compteurcolonies++;
	entre = nid;
	EnsCoord ef = creeEnsCoord4x4(nid);
	vf = creeTabFourmis(ef, nbv);
	nest = creeEnsCoord2x2(nid);
	lineariserPheroNidOpti();
	ajouterGrille();
	g.TestIntegrite(vf);
}

Colonie::Colonie() {
	nbv = -1;
	entre = Coord();
	vf = {};
	nest = EnsCoord();
}

void Colonie::lineariserPheroNidOpti() {
	auto t0 = nest.getEnsCoord()[0].getTupleCoord();
	int lig0 = std::get<0>(t0);
	int col0 = std::get<1>(t0);
	auto t1 = nest.getEnsCoord()[1].getTupleCoord();
	int lig1 = std::get<0>(t1);
	int col1 = std::get<1>(t1);
	auto t2 = nest.getEnsCoord()[2].getTupleCoord();
	int lig2 = std::get<0>(t2);
	int col2 = std::get<1>(t2);
	auto t3 = nest.getEnsCoord()[3].getTupleCoord();
	int lig3 = std::get<0>(t3);
	int col3 = std::get<1>(t3);

	std::vector<Place> place = g.getGrilleVector();

	for (int i = 0; (unsigned)i < place.size(); i++) {
		Place plac = place[i];
		auto pla = plac.getCoord().getTupleCoord();
		int lig = std::get<0>(pla);
		int col = std::get<1>(pla);
		int max = 0;
		if (lig <= lig0 and col <= col0) {
			max = (abs(lig - lig0) > abs(col - col0)) ? abs(lig - lig0) : abs(col - col0);
		}
		else if (lig >= lig1 and col <= col1) {
			max = (abs(lig - lig1) > abs(col - col1)) ? abs(lig - lig1) : abs(col - col1);
		}
		else if (lig <= lig2 and col >= col2) {
			max = (abs(lig - lig2) > abs(col - col2)) ? abs(lig - lig2) : abs(col - col2);
		}
		else {
			max = (abs(lig - lig3) > abs(col - col3)) ? abs(lig - lig3) : abs(col - col3);
		}
		float quantity = 1 - ((float)max / (float)taillegrille);
		plac.posePheroNid(nbv, quantity);
		g.rangePlace(plac);
	}
}

void Colonie::ajouterGrille() {
	g.placeNid(nest, nbv);
	g.placeFourmi(vf);
}

void Colonie::tueFourmiColonie(fourmi f) {
	vf[f.getNum()].tueFourmi();
}

void Colonie::naissance() {
	auto t = entre.getTupleCoord();
	int lig = std::get<0>(t);
	int col = std::get<1>(t);
	Place p = g.chargePlace(Coord(lig - 1, col));
	if (sugar >= 10 and g.chargePlace(Coord(lig - 1, col)).estVide()) {
		vf.push_back(fourmi(Coord(lig - 1, col), getNbColonie(), vf.size()));
		Place p = g.chargePlace(Coord(lig - 1, col));
		p.poseFourmi(vf[(vf.size() - 1)], vf);
		g.rangePlace(p);
		sugar -= 10;
	}
	else if (sugar >= 10 and g.chargePlace(Coord(lig, col - 1)).estVide()) {
		vf.push_back(fourmi(Coord(lig, col - 1), getNbColonie(), vf.size()));
		Place p = g.chargePlace(Coord(lig, col - 1));
		p.poseFourmi(vf[(vf.size() - 1)], vf);
		g.rangePlace(p);
		sugar -= 10;
	}
}

void Colonie::RulerOfAnts(std::vector<Colonie>& vcco) {
	g.TestCoherence(vf, nbv);
	for (int i = 0; (unsigned)i < vf.size(); i++) {
		Ants7RulesBis(vcco, i);
	}
	naissance();
}

void Colonie::Ants7RulesBis(std::vector<Colonie>& vcco, int i) {
	fourmi f = vf[i];
	if (f.estVivante()) {
		Place p1 = g.chargePlace(f.getCoord());
		std::vector<Coord> vfvo = voisines(f.getCoord()).getEnsCoord();;
		int ran = rand() % vfvo.size();
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (p2.contientFourmi()) {
				fourmi f2 = p2.getFourmi();
				if (not AppartientColonie(f, f2)) {
					vcco[f2.getNumColonie()].tueFourmiColonie(f2);
					p2.enleveFourmi();
					g.rangePlace(p2);
					return;
				}
			}
		}
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (f.chercheSucre() and p2.contientSucre()) {
				vf[i].prendSucre();
				p1.posePheroSucre(nbv);
				p2.dechargeSucre();
				g.rangePlace(p1);
				g.rangePlace(p2);
				return;
			}
		}
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (f.rentreNid() and p2.contientNid()) {
				vf[i].poseSucre();
				sugar++;
				naissance();
				return;
			}
		}
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (f.rentreNid() and p2.estVide() and plusProcheNid(p2, p1, nbv)) {
				p2.posePheroSucre(nbv);
				g.deplaceFourmi(f, vf, p1, p2);
				return;
			}
		}
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (f.chercheSucre() and p1.estSurUnePiste(nbv) and p2.estVide() and plusLoinNid(p2, p1, nbv) and p2.estSurUnePiste(nbv)) {
				g.deplaceFourmi(f, vf, p1, p2);
				return;
			}
		}
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (f.chercheSucre() and p2.estSurUnePiste(nbv) and p2.estVide()) {
				g.deplaceFourmi(f, vf, p1, p2);
				return;
			}
		}
		for (int j = ran; (unsigned)j != (((ran + (vfvo.size() - 1))) % vfvo.size()); j = ((j + 1) % vfvo.size())) {
			Place p2 = g.chargePlace(vfvo[j]);
			if (f.chercheSucre() and p2.estVide()) {
				g.deplaceFourmi(f, vf, p1, p2);
				return;
			}
		}
	}
}

int Colonie::getNbColonie() {
	return nbv;
}

int Colonie::getSugar() {
	return sugar;
}

std::vector<fourmi> Colonie::getFourmiVector() {
	return vf;
}