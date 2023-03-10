#ifndef FOURMI_H
#define FOURMI_H

struct fourmi {
private:

	Coord Co;
	int col;
	int Nb;
	bool vivante = true;
	bool Psucre = false;

public:

	/*
	* Constructeurs de fourmi
	*/

	//Constructeur de fourmi avec un ses Coord, le numéro de sa colonie et son numéro
	fourmi(Coord c, int colo, int nb);

	//Constructeur de fourmi vide
	fourmi();

	/*
	* Prédicats sur fourmi
	*/

	//Prédicat sur fourmi, fourmi porte du sucre
	bool rentreNid();

	//Prédicat sur fourmi, fourmi ne porte pas de sucre
	bool chercheSucre();

	//Prédicat sur fourmi, fourmi vivante ou non
	bool estVivante();

	/*
	* Méthodes sur fourmi
	*/

	//Méthode sur fourmi pour tuer une fourmi en passant l'attribut vivante a false
	void tueFourmi();

	//Méthode sur fourmi pour déplacer (changer les Coord) la fourmi aux Coord c
	void deplace(Coord c);

	//Méthode sur fourmi pour rendre sucre vrai
	void prendSucre();

	//Méthode sur fourmi pour rendre sucre faux
	void poseSucre();

	/*
	* Fonctions sur fourmi
	*/

	//Fonction sur fourmi qui retourne le numéro de la fourmi
	int getNum();

	//Fonction sur fourmi qui retourne le numéro de la colonie de la fourmi
	int getNumColonie();

	//Fonction sur fourmi qui retourne les Coord de la fourmi
	Coord getCoord();
};

#endif