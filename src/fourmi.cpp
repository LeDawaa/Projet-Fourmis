#include "AllHeaders.h"

fourmi::fourmi(Coord c, int colo, int nb) {
	Co = c;
	col = colo;
	Nb = nb;
}

fourmi::fourmi() {
	Co = Coord();
	col = -1;
	Nb = -1;
}

bool fourmi::rentreNid() {
	return Psucre;
}

bool fourmi::chercheSucre() {
	return not Psucre;
}

bool fourmi::estVivante() {
	return vivante;
}

void fourmi::tueFourmi() {
	vivante = false;
}

void fourmi::deplace(Coord c) {
	Co = c;
}

void fourmi::prendSucre() {
	Psucre = true;
}

void fourmi::poseSucre() {
	Psucre = false;
}

int fourmi::getNum() {
	return Nb;
}

int fourmi::getNumColonie() {
	return col;
}

Coord fourmi::getCoord() {
	return Co;
}

TEST_CASE("TEST FOURMI") {
	std::vector<Coord> vc;
	std::vector<fourmi> vf;

	Coord c0(6, 8);
	Coord c1(15, 5);
	Coord c2(12, 13);
	Coord c3(5, 7);
	Coord c4(15, 12);
	Coord c5(17, 16);
	Coord c6(18, 14);
	Coord c7(11, 2);
	vc.push_back(c0); vc.push_back(c1); vc.push_back(c2); vc.push_back(c3); vc.push_back(c4); vc.push_back(c5); vc.push_back(c6); vc.push_back(c7);
	EnsCoord co(vc);
	vf = creeTabFourmis(co, 0);
	CHECK(vf[2].getCoord() == c2);
	CHECK(vf[4].getCoord() == c4);
	CHECK(vf[7].getCoord() != c3);
	CHECK(vf[5].getNum() == 5);
	CHECK(vf[1].getNum() == 1);
	CHECK(vf[0].getNum() != 4);
	CHECK(vf[0].getNumColonie() == 0);
	CHECK(not vf[0].rentreNid());
	CHECK(vf[0].chercheSucre());
	vf[0].prendSucre();
	CHECK(vf[0].rentreNid());
	CHECK(not vf[0].chercheSucre());
	vf[0].poseSucre();
	CHECK(not vf[0].rentreNid());
	CHECK(vf[0].chercheSucre());
	CHECK(vf[0].getCoord() == c0);
	CHECK(vf[0].estVivante());
	vf[0].tueFourmi();
	CHECK(not vf[0].estVivante());
}