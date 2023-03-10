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
	* Prédicats sur EnsCoord
	*/

	//Prédicat sur EnsCoord, vector contenant la cordonnée donnée en param
	bool contient(Coord c);

	//Prédicat sur EnsCoord, vector est vide
	bool estVide();

	/*
	* Méthodes sur EnsCoord
	*/

	//Méthode sur EnsCoord pour ajouter une Coord
	void ajoute(Coord c);

	//Méthode sur EnsCoord pour supprimer une Coord
	void supprime(Coord c);

	/*
	* Fonctions sur EnsCoord
	*/

	//Fonction sur EnsCoord qui retourne la position dans le vector d'une Coord
	int getPosition(Coord c);

	//Fonction sur EnsCoord qui retourne la taille du vector
	int getTaille();

	//Fonction sur EnsCoord qui retourne la nième valeur du vector
	Coord getIeme(int c);

	//Fonction sur EnsCoord qui retourne une Coord aléatoire de EnsCoord
	Coord choixHasard();

	//Fonction sur EnsCoord qui retourne le vector de EnsCoord
	std::vector<Coord> getEnsCoord();
};

//Surcharge de l'opérateur cout pour EnsCoord
std::ostream& operator<<(std::ostream& out, EnsCoord e);

#endif