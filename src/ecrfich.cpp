#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

#include "AllHeaders.h"

// variable globale permettant de creer des noms de fichiers differents
int compteurFichier = 0;

#ifndef VCOLOR
#define VCOLOR

typedef std::tuple<int, int, int> tupleRGB;

std::vector<tupleRGB> make_vcolor() {
	std::vector<tupleRGB> v;
	v.push_back(std::make_tuple(255, 0, 255));
	v.push_back(std::make_tuple(255, 255, 0));
	v.push_back(std::make_tuple(0, 255, 255));
	v.push_back(std::make_tuple(0, 255, 0));
	return v;
}

const std::vector<tupleRGB> vcolor = make_vcolor();

#endif

void dessinerFourmilliere(Grille gr) {
	int i, j;
	int r, g, b;
	int rv, gv, bv;
	std::ostringstream filename;

	// creation d'un nouveau nom de fichier de la forme img347.ppm
	filename << "img" << std::setfill('0') << std::setw(3) << compteurFichier << ".ppm";
	compteurFichier++;
	std::cout << "Ecriture dans le fichier : " << filename.str() << std::endl;

	// ouverture du fichier
	std::ofstream fic(filename.str(), std::ios::out | std::ios::trunc);

	// ecriture de l'entete
	fic << "P3" << std::endl
		<< taillegrille << " " << taillegrille << " " << std::endl
		<< 255 << " " << std::endl;

	// ecriture des pixels
	for (i = 0; i < taillegrille; i++) {
		for (j = 0; j < taillegrille; j++) {
			// calcul de la couleur
			r = 0; g = 0; b = 0;

			Coord coo(i, j);
			Place pla = gr.chargePlace(coo);

			for (int k = 0; k < NbColonies; k++) {
				if (pla.getpheroSucre(k) != 0) {
					std::tie(rv, gv, bv) = vcolor[k];
					r = (std::max(rv / 2, 0)) * pla.getpheroSucre(k) / 255; g = (std::max(gv / 2, 0)) * pla.getpheroSucre(k) / 255; b = (std::max(bv / 2, 0)) * pla.getpheroSucre(k) / 255;
				}
			}

			if (pla.contientNid()) { r = 165; g = 42; b = 42; }
			else if (pla.contientSucre()) { r = 255; g = 255; b = 255; }
			else if (pla.contientFourmi()) {
				std::tie(rv, gv, bv) = vcolor[pla.getFourmi().getNumColonie()];
				if (pla.getFourmi().chercheSucre()) {
					r = rv; g = gv; b = bv;
				}
				else {
					r = std::max(rv - 10, 0); g = std::max(gv - 10, 0); b = std::max(bv - 10, 0);
				}
			}

			// ecriture de la couleur dans le fichier
			fic << r << " " << g << " " << b << "    ";
		}

		// fin de ligne dans l'image
		fic << std::endl;
	}
	fic.close();
}