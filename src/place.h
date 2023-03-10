#ifndef PLACE_H
#define PLACE_H

struct Place {
private:

	Coord Co;
	fourmi four = fourmi();
	bool sucre = false;
	int chargeSucre = 0;
	std::vector<int> pherosucre;
	bool nid = false;
	std::vector<float> pheronid;

public:

	/*
	* Constructeurs de Place
	*/

	//Constructeur de Place avec une Coord
	Place(Coord c);

	/*
	* Prédicats sur Place
	*/

	//Prédicat sur Place, place contenant sucre
	bool contientSucre();

	//Prédicat sur Place, place contenant nid
	bool contientNid();

	//Prédicat sur Place, place contenant fourmi
	bool contientFourmi();

	//Prédicat sur Place, place contenant phéromones de sucre
	bool estSurUnePiste(int i);

	//Prédicat sur Place, place ne contenant ni sucre, ni nid, ni fourmi
	bool estVide();

	/*
	* Méthodes sur Place
	*/

	//Méthode sur Place pour poser un sucre
	void poseSucre();

	//Méthode sur Place pour enlever le sucre
	void enleveSucre();

	//Méthode sur Place pour poser un nid
	void poseNid();

	//Méthode sur Place pour poser une fourmi foufou appartennant au vector vfou
	void poseFourmi(fourmi foufou, std::vector<fourmi>& vfou);

	//Méthode sur Place pour enlever la fourmi de la place
	void enleveFourmi();

	//Méthode sur Place pour poser une quantité q de pheromones de nid de la colonie i
	void posePheroNid(int i, float q);

	//Méthode sur Place pour poser la quantité maximale de pheromones de sucre de la colonie i
	void posePheroSucre(int i);

	//Méthode sur Place pour simuler l'évaporation du sucre sur la grille
	void diminuePheroSucre();

	//Méthode sur Place pour enlever une charge de sucre du sucre
	void dechargeSucre();

	/*
	* Fonctions sur Place
	*/

	//Fonction sur Place qui retourne le numéro de la fourmi de la place, sinon -1
	int getNbFourmi();

	//Fonction sur Place qui retourne la quantité de phéromones de sucre d'une colonie i
	int getpheroSucre(int i);

	//Fonction sur Place qui retourne la quantité de phéromones de nid d'une colonie i
	float getpheroNid(int i);

	//Fonction sur Place qui retourne la fourmi de la place
	fourmi getFourmi();

	//Fonction sur Place qui retourne les Coord de la place
	Coord getCoord();
};

#endif