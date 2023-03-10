#ifndef ENSCOORD_H
#define ENSCOORD_H

#include <vector>
#include <time.h>

struct EnsCoord {
private:

	std::vector<Coord> Co;

public:

	/*
	* Constructeurs de EnsCoordf
	*/

	//Constructeur de EnsCoord avec un vecteur de Coord
	EnsCoord(std::vector<Coord> C);

	//Constructeur de EnsCoord vide
	EnsCoord();

	/*
	* Pr�dicats sur EnsCoord
	*/

	//Pr�dicat sur EnsCoord, vector contenant la cordonn�e donn�e en param
	bool contient(Coord c);

	//Pr�dicat sur EnsCoord, vector est vide
	bool estVide();

	/*
	* M�thodes sur EnsCoord
	*/

	//M�thode sur EnsCoord pour ajouter une Coord
	void ajoute(Coord c);

	//M�thode sur EnsCoord pour supprimer une Coord
	void supprime(Coord c);

	/*
	* Fonctions sur EnsCoord
	*/

	//Fonction sur EnsCoord qui retourne la position dans le vector d'une Coord
	int getPosition(Coord c);

	//Fonction sur EnsCoord qui retourne la taille du vector
	int getTaille();

	//Fonction sur EnsCoord qui retourne la ni�me valeur du vector
	Coord getIeme(int c);

	//Fonction sur EnsCoord qui retourne une Coord al�atoire de EnsCoord
	Coord choixHasard();

	//Fonction sur EnsCoord qui retourne le vector de EnsCoord
	std::vector<Coord> getEnsCoord();
};

//Surcharge de l'op�rateur cout pour EnsCoord
std::ostream& operator<<(std::ostream& out, EnsCoord e);

#endif