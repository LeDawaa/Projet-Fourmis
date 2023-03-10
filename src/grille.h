#ifndef GRILLE_H
#define GRILLE_H

struct Grille {
private:

	std::vector<Place> pla;

public:

	/*
	* Constructeurs de Grille
	*/

	//Constructeur de Grille sans paramètre
	Grille();

	/*
	* Méthodes sur Grille
	*/

	//Méthode sur Grille pour placer un nid sur la place
	void placeNid(EnsCoord e, int col);

	//Méthode sur Grille pour placer un sucre sur la place
	void placeSucre(EnsCoord e);

	//Méthode sur Grille pour placer l'ensemble des fourmis d'un vector
	void placeFourmi(std::vector<fourmi> vfou);

	//Méthode sur Grille pour diminuer progressivement les phéromones de sucre
	void diminuePheroSucre();

	//Méthode sur Grille pour déplacer une fourmi foufou appartenant a un vector vfou d'une place p1 à une place p2
	void deplaceFourmi(fourmi foufou, std::vector<fourmi>& vfou, Place p1, Place p2);

	//Méthode sur Grille pour range une place p dans la grille
	void rangePlace(Place p);

	//Méthode sur Grille pour linéariser les phéromones de Nid d'une colonie (Remplacée car peu efficace)
	void lineariserPheroNid(int j);

	/*
	* Fonctions sur Grille
	*/

	//Méthode/Fonction sur Grille pour récupérer une place p dans la grille aux Coord c
	Place chargePlace(Coord c);

	//Fonction sur Grille qui retourne le vector de la grille
	std::vector<Place> getGrilleVector();

	/*
	* Affichage de Grille
	*/

	//Affiche la Grille sans distinction  particulière entre les éléments de différentes colonies
	void afficher();

	//Affiche les phéromones de Nid d'une colonie j dans la Grille
	void afficherpheroNid(int j);

	void TestIntegrite(std::vector<fourmi> vfou);

	void TestCoherence(std::vector<fourmi> vfou, int colo);
};

//Déclaration de la grille g pour utilisation dans plusieurs fichiers sans avoir a la mettre en paramètre
extern Grille g;

#endif