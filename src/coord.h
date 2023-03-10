#ifndef COORD_H
#define COORD_H

#include <iostream>
#include <iomanip>
#include <tuple>

struct Coord {
private:

	int ligne;
	int colonne;

public:

	/*
	* Constructeurs de Coord
	*/

	//Constructeur de Coord avec 2 variables int
	Coord(int lig, int col);

	//Constructeur sur Coord vide
	Coord();

	/*
	* Fonctions sur Coord
	*/

	//Fonction sur Coord qui retourne la ligne et la colonne
	std::tuple<int, int> getTupleCoord();
};

//Surcharge de l'opérateur cout pour Coord
std::ostream& operator<<(std::ostream& out, Coord c);

//Surcharge de l'opérateur == pour Coord
bool operator==(Coord c1, Coord c2);

//Surcharge de l'opérateur != pour Coord
bool operator!=(Coord c1, Coord c2);

#endif