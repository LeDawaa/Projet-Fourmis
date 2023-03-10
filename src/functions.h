#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Fonctions sur EnsCoord

//Fonction permettant la cr�ation d'un EnsCoord de 4 Coord avec une seule Coord (utilit� : constructeur colonie)
EnsCoord creeEnsCoord2x2(Coord c);

//Fonction permettant la cr�ation d'un EnsCoord de 12 Coord avec une seule Coord (utilit� : constructeur colonie)
EnsCoord creeEnsCoord4x4(Coord c);

//Fonction retournant les voisins d'une Coord
EnsCoord voisines(Coord c);

// Fonctions sur Place

//Pr�dicat retournant si la place p1 est plus proche que la Place p2 du nid de la colonie col
bool plusProcheNid(Place p1, Place p2, int col);

//Pr�dicat retournant si la place p1 est plus loin que la Place p2 du nid de la colonie col
bool plusLoinNid(Place p1, Place p2, int col);

// Fonctions sur fourmi

//Fonction g�n�rant un tableau de fourmi a partir d'un EnsCoord et du num�ro de leur colonie
std::vector<fourmi> creeTabFourmis(EnsCoord e, int colo);

//Fonctions sur Grille

//Fonction g�n�rant une Grille o� se situent les �l�ments de sucre, de nid et les fourmis
Grille initialiseGrille(std::vector<fourmi> vfou, EnsCoord sucre, EnsCoord nid, int col);

//Fonction sur Grille posant taillegrille morceaux de sucre al�atoirement sur la Grille;
void InitSucre();

//Fonctions sur Colonie

//Pr�dicat retournant vrai si les fourmis f1 et f2 font parti de la m�me colonie, sinon false
bool AppartientColonie(fourmi f1, fourmi f2);

#endif