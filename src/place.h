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
	* Pr�dicats sur Place
	*/

	//Pr�dicat sur Place, place contenant sucre
	bool contientSucre();

	//Pr�dicat sur Place, place contenant nid
	bool contientNid();

	//Pr�dicat sur Place, place contenant fourmi
	bool contientFourmi();

	//Pr�dicat sur Place, place contenant ph�romones de sucre
	bool estSurUnePiste(int i);

	//Pr�dicat sur Place, place ne contenant ni sucre, ni nid, ni fourmi
	bool estVide();

	/*
	* M�thodes sur Place
	*/

	//M�thode sur Place pour poser un sucre
	void poseSucre();

	//M�thode sur Place pour enlever le sucre
	void enleveSucre();

	//M�thode sur Place pour poser un nid
	void poseNid();

	//M�thode sur Place pour poser une fourmi foufou appartennant au vector vfou
	void poseFourmi(fourmi foufou, std::vector<fourmi>& vfou);

	//M�thode sur Place pour enlever la fourmi de la place
	void enleveFourmi();

	//M�thode sur Place pour poser une quantit� q de pheromones de nid de la colonie i
	void posePheroNid(int i, float q);

	//M�thode sur Place pour poser la quantit� maximale de pheromones de sucre de la colonie i
	void posePheroSucre(int i);

	//M�thode sur Place pour simuler l'�vaporation du sucre sur la grille
	void diminuePheroSucre();

	//M�thode sur Place pour enlever une charge de sucre du sucre
	void dechargeSucre();

	/*
	* Fonctions sur Place
	*/

	//Fonction sur Place qui retourne le num�ro de la fourmi de la place, sinon -1
	int getNbFourmi();

	//Fonction sur Place qui retourne la quantit� de ph�romones de sucre d'une colonie i
	int getpheroSucre(int i);

	//Fonction sur Place qui retourne la quantit� de ph�romones de nid d'une colonie i
	float getpheroNid(int i);

	//Fonction sur Place qui retourne la fourmi de la place
	fourmi getFourmi();

	//Fonction sur Place qui retourne les Coord de la place
	Coord getCoord();
};

#endif