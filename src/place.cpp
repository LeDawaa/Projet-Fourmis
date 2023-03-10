#include "AllHeaders.h"

Place::Place(Coord c) {
	Co = c;
	pherosucre = std::vector<int>(NbColonies, 0);
	pheronid = std::vector<float>(NbColonies, 0);
}

bool Place::contientSucre() {
	return sucre;
}

bool Place::contientNid() {
	return nid;
}

bool Place::contientFourmi() {
	return four.getNum() != -1;
}

bool Place::estSurUnePiste(int i) {
	return (pherosucre[i] != 0);
}

bool Place::estVide() {
	if (not contientNid()) {
		if (not contientSucre()) {
			if (not contientFourmi()) {
				return true;
			}
		}
	}
	return false;
}

void Place::poseSucre() {
	sucre = true; chargeSucre = 5;
}

void Place::enleveSucre() {
	sucre = false;
}

void Place::poseNid() {
	nid = true;
}

void Place::poseFourmi(fourmi foufou, std::vector<fourmi>& vfou) {
	four = foufou;
	vfou[four.getNum()].deplace(Co);
}

void Place::enleveFourmi() {
	four = fourmi();
}

void Place::posePheroNid(int i, float q) {
	pheronid[i] = q;
}

void Place::posePheroSucre(int i) {
	pherosucre[i] = 255;
}

void Place::diminuePheroSucre() {
	for (int i = 0; (unsigned)i < pherosucre.size(); i++) {
		pherosucre[i] = std::max(pherosucre[i] - 5, 0);
	}
}

void Place::dechargeSucre() {
	chargeSucre--;
	if (chargeSucre == 0) {
		sucre = false;
	}
}

int Place::getNbFourmi() {
	return four.getNum();
}

int Place::getpheroSucre(int i) {
	return pherosucre[i];
}

float Place::getpheroNid(int i) {
	return pheronid[i];
}

fourmi Place::getFourmi() {
	return four;
}

Coord Place::getCoord() {
	return Co;
}

TEST_CASE("TEST PLACE") {
	Coord c1(15, 5);

	std::vector<fourmi> vf = creeTabFourmis(EnsCoord({ Coord(1,1) }), 0);

	Place p1(c1);
	CHECK(not p1.contientSucre());
	CHECK(not p1.contientNid());
	CHECK(not p1.contientFourmi());
	CHECK(not p1.estSurUnePiste(0));
	CHECK(p1.estVide());

	p1.poseSucre();
	p1.poseNid();
	p1.poseFourmi(vf[0], vf);
	p1.poseSucre();
	CHECK(p1.contientSucre());
	CHECK(p1.contientNid());
	CHECK(p1.contientFourmi());
	CHECK(not p1.estVide());

	p1.enleveFourmi();
	CHECK(not p1.contientFourmi());

	p1.poseFourmi(vf[0], vf);
	p1.posePheroNid(0, (float)0.8);
	p1.posePheroSucre(0);
	CHECK(p1.getNbFourmi() == 0);
	CHECK(p1.getpheroSucre(0) == 255);
	CHECK(p1.estSurUnePiste(0));

	p1.diminuePheroSucre();
	CHECK(p1.getpheroSucre(0) == 250);

	p1.dechargeSucre();
	p1.dechargeSucre();
	p1.dechargeSucre();
	p1.dechargeSucre();
	p1.dechargeSucre();
	CHECK(not p1.contientSucre());

	CHECK(p1.getFourmi().getNum() == vf[0].getNum());
	CHECK(p1.getCoord() == c1);
}