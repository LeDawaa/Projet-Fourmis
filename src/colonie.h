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

	//Constructeur de Colonie à partir de la coordonnée haut gauche du nid
	Colonie(Coord nid);

	//Constructeur de Colonie vide
	Colonie();

	/*
	* Méthodes sur Colonie
	*/

	//Méthode sur Colonie permettant de linéariser les phéromones de nid de la colonie
	void lineariserPheroNidOpti();

	//Méthode sur Colonie pour ajouter la Colonie à la Grille
	void ajouterGrille();

	void tueFourmiColonie(fourmi f);

	//Méthode sur Colonie pour ajouter une nouvelle fourmi dans la Colonie et sur la grille
	void naissance();

	//Méthode sur Colonie pour appliquer Ants7RulesBis à toutes les fourmis de la Colonie
	void RulerOfAnts(std::vector<Colonie>& vcco);

	//Méthode sur Colonie pour appliquer les règles à la ième fourmi
	void Ants7RulesBis(std::vector<Colonie>& vcco, int i);

	/*
	* Fonctions sur Colonie
	*/

	//Fonction sur Colonie qui retourne le numéro de la Colonie
	int getNbColonie();

	//Fonction sur Colonie qui retourne le nombre de sucre de la Colonie
	int getSugar();

	//Fonction sur Colonie qui retourne le vector de la Colonie
	std::vector<fourmi> getFourmiVector();
};

#endif