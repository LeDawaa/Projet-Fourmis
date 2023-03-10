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

	//Constructeur de fourmi avec un ses Coord, le num�ro de sa colonie et son num�ro
	fourmi(Coord c, int colo, int nb);

	//Constructeur de fourmi vide
	fourmi();

	/*
	* Pr�dicats sur fourmi
	*/

	//Pr�dicat sur fourmi, fourmi porte du sucre
	bool rentreNid();

	//Pr�dicat sur fourmi, fourmi ne porte pas de sucre
	bool chercheSucre();

	//Pr�dicat sur fourmi, fourmi vivante ou non
	bool estVivante();

	/*
	* M�thodes sur fourmi
	*/

	//M�thode sur fourmi pour tuer une fourmi en passant l'attribut vivante a false
	void tueFourmi();

	//M�thode sur fourmi pour d�placer (changer les Coord) la fourmi aux Coord c
	void deplace(Coord c);

	//M�thode sur fourmi pour rendre sucre vrai
	void prendSucre();

	//M�thode sur fourmi pour rendre sucre faux
	void poseSucre();

	/*
	* Fonctions sur fourmi
	*/

	//Fonction sur fourmi qui retourne le num�ro de la fourmi
	int getNum();

	//Fonction sur fourmi qui retourne le num�ro de la colonie de la fourmi
	int getNumColonie();

	//Fonction sur fourmi qui retourne les Coord de la fourmi
	Coord getCoord();
};

#endif