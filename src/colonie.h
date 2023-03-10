#ifndef COLONNIE_H_
#define COLONNIE_H_

struct Colonie {
private:

	int nbv;
	Coord entre;
	std::vector<fourmi> vf;
	EnsCoord nest;
	int sugar = 0;

public:

	/*
	* Constructeurs de Colonie
	*/

	//Constructeur de Colonie � partir de la coordonn�e haut gauche du nid
	Colonie(Coord nid);

	//Constructeur de Colonie vide
	Colonie();

	/*
	* M�thodes sur Colonie
	*/

	//M�thode sur Colonie permettant de lin�ariser les ph�romones de nid de la colonie
	void lineariserPheroNidOpti();

	//M�thode sur Colonie pour ajouter la Colonie � la Grille
	void ajouterGrille();

	void tueFourmiColonie(fourmi f);

	//M�thode sur Colonie pour ajouter une nouvelle fourmi dans la Colonie et sur la grille
	void naissance();

	//M�thode sur Colonie pour appliquer Ants7RulesBis � toutes les fourmis de la Colonie
	void RulerOfAnts(std::vector<Colonie>& vcco);

	//M�thode sur Colonie pour appliquer les r�gles � la i�me fourmi
	void Ants7RulesBis(std::vector<Colonie>& vcco, int i);

	/*
	* Fonctions sur Colonie
	*/

	//Fonction sur Colonie qui retourne le num�ro de la Colonie
	int getNbColonie();

	//Fonction sur Colonie qui retourne le nombre de sucre de la Colonie
	int getSugar();

	//Fonction sur Colonie qui retourne le vector de la Colonie
	std::vector<fourmi> getFourmiVector();
};

#endif