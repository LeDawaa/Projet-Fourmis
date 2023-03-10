#ifndef GRILLE_H
#define GRILLE_H

struct Grille {
private:

	std::vector<Place> pla;

public:

	/*
	* Constructeurs de Grille
	*/

	//Constructeur de Grille sans param�tre
	Grille();

	/*
	* M�thodes sur Grille
	*/

	//M�thode sur Grille pour placer un nid sur la place
	void placeNid(EnsCoord e, int col);

	//M�thode sur Grille pour placer un sucre sur la place
	void placeSucre(EnsCoord e);

	//M�thode sur Grille pour placer l'ensemble des fourmis d'un vector
	void placeFourmi(std::vector<fourmi> vfou);

	//M�thode sur Grille pour diminuer progressivement les ph�romones de sucre
	void diminuePheroSucre();

	//M�thode sur Grille pour d�placer une fourmi foufou appartenant a un vector vfou d'une place p1 � une place p2
	void deplaceFourmi(fourmi foufou, std::vector<fourmi>& vfou, Place p1, Place p2);

	//M�thode sur Grille pour range une place p dans la grille
	void rangePlace(Place p);

	//M�thode sur Grille pour lin�ariser les ph�romones de Nid d'une colonie (Remplac�e car peu efficace)
	void lineariserPheroNid(int j);

	/*
	* Fonctions sur Grille
	*/

	//M�thode/Fonction sur Grille pour r�cup�rer une place p dans la grille aux Coord c
	Place chargePlace(Coord c);

	//Fonction sur Grille qui retourne le vector de la grille
	std::vector<Place> getGrilleVector();

	/*
	* Affichage de Grille
	*/

	//Affiche la Grille sans distinction  particuli�re entre les �l�ments de diff�rentes colonies
	void afficher();

	//Affiche les ph�romones de Nid d'une colonie j dans la Grille
	void afficherpheroNid(int j);

	void TestIntegrite(std::vector<fourmi> vfou);

	void TestCoherence(std::vector<fourmi> vfou, int colo);
};

//D�claration de la grille g pour utilisation dans plusieurs fichiers sans avoir a la mettre en param�tre
extern Grille g;

#endif