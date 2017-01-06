/**
 * \file validationFormat.cpp
 * \brief Contient les definitions des fonctions.
 * \author Vincent Boily Grant
 * \version 2.1
 * \date 03/10/16
 */
//Date modification 27-11-16
#include "validationFormat.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

namespace util {

/**
 * \brief Fonction permettant à l'utilisateur de lire et mettre dans une variable temporaire les lignes d un fichier texte.
 *  Il envoit les donnees a la fonction de verification appropriee les données
 * \param[in] const string & p_fichierSource: Le nom du fichier source a lire,
 */
void lecture(const string & p_fichierSource) {
	string ligneDuFichier;
	ifstream fichier(p_fichierSource.c_str(), ios::in);
	if (!fichier) {
		cout << "Erreur d'ouverture du fichier\n";
		exit (ERREUR);
	}
	cout << std::endl;

	char buffer[256];
	while (fichier.getline(buffer, 255)) {
		ligneDuFichier = buffer;

		if (p_fichierSource == FICHIER_IMMATRICULATION) {

			validerImmatriculation(ligneDuFichier);
		}
		if (p_fichierSource == FICHIER_NIV) {

			validerNiv(ligneDuFichier);
		}

	}
	fichier.close();
}

/**
 * \brief Fonction permettant de valider des numeros de plaques dimmatriculation dun Vehicule de Promenade.
 * \param[in] const std::string& p_plaqueRecuePromenade: Le numero de plaque a traiter,
 * \param[out] bool: Vrai ou Faux, la plaque est elle valide?
 */
bool validationImmatriculationPromenade(
		const std::string& p_plaqueRecuePromenade) {
	bool resultat = 0;
	if ((p_plaqueRecuePromenade.length() != 7)
			|| (p_plaqueRecuePromenade[0] == 76)) {
		//cout << p_plaqueRecuePromenade << endl;
		//	cout << "Plaque non valide " << endl;
		//cout << endl;
		return resultat;
	}

	/* test ligneDuFichier de type 000H000*/

	if ((isdigit(p_plaqueRecuePromenade[0]))
			&& (isdigit(p_plaqueRecuePromenade[1]))
			&& (isdigit(p_plaqueRecuePromenade[2]))) {
		if ((isdigit(p_plaqueRecuePromenade[4]))
				&& (isdigit(p_plaqueRecuePromenade[5]))
				&& (isdigit(p_plaqueRecuePromenade[6]))
				&& isupper(p_plaqueRecuePromenade[3])) {
			//cout << p_plaqueRecuePromenade << endl;
			//cout << "Plaque valide " << endl;
			//cout << endl;
			return resultat = 1;
		}

		/* test ligneDuFichier de type 000 ABC
		 */
		if ((p_plaqueRecuePromenade[3] == 32)
				&& (isupper(p_plaqueRecuePromenade[4]))
				&& (isupper(p_plaqueRecuePromenade[5]))
				&& (isupper(p_plaqueRecuePromenade[6]))) {
			//cout << p_plaqueRecuePromenade << endl;
			//cout << "Plaque valide" << endl;
			//cout << endl;
			return resultat = 1;
		}
		//cout << p_plaqueRecuePromenade << endl;
		//cout << "Plaque non valide " << endl;
		//cout << endl;
		return resultat = 0;
	}
	/*Plaque debutant par une lettre mais pas L*/
	if (isupper(p_plaqueRecuePromenade[0])
			&& (p_plaqueRecuePromenade[0] != 76)) {
		resultat = 1;
		for (unsigned int j = 1; j < p_plaqueRecuePromenade.length(); j++) {

			/*Test ligneDuFichier du type <ABC  000>*/

			if (isupper(p_plaqueRecuePromenade[j])
					&& (p_plaqueRecuePromenade[3] == 32)) {

				resultat = 1;
				if (isupper(p_plaqueRecuePromenade[2])) {

					if ((isdigit(p_plaqueRecuePromenade[4]))
							&& (isdigit(p_plaqueRecuePromenade[5]))
							&& (isdigit(p_plaqueRecuePromenade[6]))) {
						//cout << p_plaqueRecuePromenade << endl;
						//cout << "Plaque  valide " << endl;
						//	cout << endl;
						return resultat;
					}
				}
			}
			/*test ligneDuFichier du type A00 ABC*/
			if ((isdigit(p_plaqueRecuePromenade[1]))
					&& (isdigit(p_plaqueRecuePromenade[2]))
					&& (p_plaqueRecuePromenade[3] == 32)
					&& (isupper(p_plaqueRecuePromenade[4]))
					&& (isupper(p_plaqueRecuePromenade[5]))
					&& (isupper(p_plaqueRecuePromenade[6]))) {
				//cout << p_plaqueRecuePromenade << endl;
				//cout << "Plaque valide " << endl;
				//cout << endl;
				return resultat = 1;
			}

			else {
				//cout << p_plaqueRecuePromenade << endl;
				//cout << "Plaque non valide " << endl;
				//cout << endl;
				return resultat = 0;
			}
			//cout << p_plaqueRecuePromenade << endl;
			//cout << "Plaque valide " << endl;
			//cout << endl;
			return resultat;
		}

	}
	return resultat;
}

bool validationImmatriculationCamion(const std::string& p_plaqueRecueCamion) {
	bool resultat = 0;
	if (p_plaqueRecueCamion.length() != 7) {
		//cout << p_plaqueRecueCamion << endl;
		//cout << "Plaque non valide " << endl;
		//cout << endl;
		return resultat;
	}
	// Test plaque L000000
	if (isupper(p_plaqueRecueCamion[0]) && (p_plaqueRecueCamion[0] == 76)) {
		resultat = 1;

		for (unsigned int i = 1; i < p_plaqueRecueCamion.length(); i++) {
			if (isdigit(p_plaqueRecueCamion[i])) {
				resultat = 1;
			} else {
				resultat = 0;
				//cout << p_plaqueRecueCamion << endl;
				//cout << "Plaque non valide " << endl;
				//cout << endl;
				return resultat;
			}
			//cout << p_plaqueRecueCamion << endl;
			//cout << "Plaque valide " << endl;
			//cout << endl;
			return resultat;
		}
		return resultat;
	}

	return resultat;
}

bool validerImmatriculation(const string& p_plaqueRecue) {
	bool resultat = 0;

	if (p_plaqueRecue.length() != 7) {
		//cout << p_plaqueRecue << endl;
		//cout << "Plaque non valide " << endl;
		//cout << endl;
		return resultat;
	}

	if (isupper(p_plaqueRecue[0]) && (p_plaqueRecue[0] == 76)) {
		resultat = 1;

		for (unsigned int i = 1; i < p_plaqueRecue.length(); i++) {
			if (isdigit(p_plaqueRecue[i]) || (p_plaqueRecue[3] == 48)) {
				resultat = 1;
			} else {
				resultat = 0;
				//cout << p_plaqueRecue << endl;
				//cout << "Plaque non valide " << endl;
				//cout << endl;
				return resultat;
			}
			//cout << p_plaqueRecue << endl;
			//cout << "Plaque valide " << endl;
			//cout << endl;
			return resultat;
		}
		return resultat;
	}

	/*Plaque debutant par une lettre mais pas L*/
	if (isupper(p_plaqueRecue[0]) && (p_plaqueRecue[0] != 76)) {
		resultat = 1;
		for (unsigned int j = 1; j < p_plaqueRecue.length(); j++) {

			/*Test ligneDuFichier du type <ABC  000>*/

			if (isupper(p_plaqueRecue[j]) && (p_plaqueRecue[3] == 32)) {

				resultat = 1;
				if (isupper(p_plaqueRecue[2])) {

					if ((isdigit(p_plaqueRecue[4]))
							&& (isdigit(p_plaqueRecue[5]))
							&& (isdigit(p_plaqueRecue[6]))) {
						//cout << p_plaqueRecue << endl;
						//cout << "Plaque  valide " << endl;
						//cout << endl;
						return resultat;
					}
				}
			}
			/*test ligneDuFichier du type A00 ABC*/
			if ((isdigit(p_plaqueRecue[1])) && (isdigit(p_plaqueRecue[2]))
					&& (p_plaqueRecue[3] == 32) && (isupper(p_plaqueRecue[4]))
					&& (isupper(p_plaqueRecue[5]))
					&& (isupper(p_plaqueRecue[6]))) {
				//cout << p_plaqueRecue << endl;
				//cout << "Plaque valide " << endl;
				//cout << endl;
				return resultat = 1;
			}

			else {
				//cout << p_plaqueRecue << endl;
				//cout << "Plaque non valide " << endl;
				//cout << endl;
				return resultat = 0;
			}
			//cout << p_plaqueRecue << endl;
			//cout << "Plaque valide " << endl;
			//cout << endl;
			return resultat;
		}

	}
	/* test ligneDuFichier de type 000H000*/

	if ((isdigit(p_plaqueRecue[0])) && (isdigit(p_plaqueRecue[1]))
			&& (isdigit(p_plaqueRecue[2]))) {
		if ((isdigit(p_plaqueRecue[4])) && (isdigit(p_plaqueRecue[5]))
				&& (isdigit(p_plaqueRecue[6])) && isupper(p_plaqueRecue[3])) {
			//cout << p_plaqueRecue << endl;
			//cout << "Plaque valide " << endl;
			//	cout << endl;
			return resultat = 1;
		}
	}

	/* test ligneDuFichier de type 000 ABC
	 */
	if ((p_plaqueRecue[3] == 32) && (isupper(p_plaqueRecue[4]))
			&& (isupper(p_plaqueRecue[5])) && (isupper(p_plaqueRecue[6]))) {
		//cout << p_plaqueRecue << endl;
		//cout << "Plaque valide" << endl;
		//cout << endl;
		return resultat = 1;
	}
	//cout << p_plaqueRecue << endl;
	//cout << "Plaque non valide" << endl;
	return resultat;
}

/**
 * \brief Fonction permettant à valider des niv.
 * \param[in] const std::string& p_niv: Le numero didentification vehicule a traiter,
 * \param[out] bool: Vrai ou Faux precede d une sortie vers la console pour montrer le niv a lutilisateur
 * ainsi qu un string expliquant si le niv est valide ou non,
 */
bool validerNiv(const std::string& p_niv) {

	bool resultat = 0;

	/*Test du nb de caracteres que doit avoir la variable NIV*/
	if ((p_niv == "") || (p_niv.length() != NIV_MAX_ESPACE)) {
		//cout << p_niv << endl;
		//cout << "NIV  non valide (ligne 300)";
		return resultat = 0;
	}
	/*Test du 9ieme caractere que doit avoir la variable NIV
	 * Si la variable nest pas un nombre entre 0 et 9 et que ce nest pas X
	 * alors le NIV ne peu pas etre valide*/
	if (not (isdigit(p_niv[8])) && ((p_niv[8]) != 88)) {
		//cout << p_niv << endl;
		//cout << "NIV non valide (ligne 186)" << endl;
		//cout << endl;
		return resultat = 0;
	}

	else {
		/* Si un caractere nest pas majuscule et nest pas un chiffre retourne faux ou si la lettre est Q, I, O*/
		for (unsigned int i = 0; i < p_niv.length(); i++) {

			if (((islower(p_niv[i])) && (not (isdigit(p_niv[i]))))
					|| (p_niv[i] == 73) || (p_niv[i] == 79)
					|| (p_niv[i] == 81)) {
				//cout << p_niv << endl;
				//cout << "NIV non valide (ligne 199) " << endl;
				//cout << endl;
				return resultat = 0;
			}
		}
		int p_tab_int_niv[NIV_MAX_ESPACE]; /*p_tab_int_niv contient des entiers qui correspondent a un string du NIV*/

		translation_niv_int(p_tab_int_niv, p_niv);

		int intTabPoids[17] = { 8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3,
				2 };
		int sommeTotal = 0;
		for (unsigned int i = 0; i < p_niv.length(); i++) {
			int multi = intTabPoids[i] * p_tab_int_niv[i];
			sommeTotal += multi;
		}
		int reponse = sommeTotal % 11;
		/*Si la reponse du modulo donne 10, le 9 caractere devrait etre X sinon ce n est pas une bonne reponse*/
		if ((reponse == 10) && (p_niv[8] == 88)) {

			//cout << p_niv << endl;
			//cout << "NIV valide (ligne 220)" << endl;
			//cout << endl;
			return resultat = 1;
		}
		/*Si reponse vaut entre 0 et 9 et que le 9 caractere
		 * est identique a lentier contenu de la reponse le niv est bon*/
		if ((reponse < 10) && (reponse >= 0)) {
			if ((p_niv[8] - 48) == reponse) {
				//cout << p_niv << endl;
				//cout << "NIV valide (ligne 229)" << endl;
				//cout << endl;
				return resultat = 1;
			}
		}
	}
	//cout << p_niv << endl;
	//cout << "NIV non valide (ligne 236)" << endl;
	//cout << endl;
	return resultat = 0;
}

/**
 * \brief Fonction permettant de remplir un tableau dentiers avec des valeurs
 * contenues dans une string ayant le meme nombre de caracteres
 * \param[in] int p_tab_int_niv[NIV_MAX_ESPACE]: le tableau dentier qui contiendra la translation du string.

 * \param[in]const string & p_niv: la string recu qui servira a definir les valeurs a mettre dans le tableau recu.
 */
void translation_niv_int(int p_tab_int_niv[NIV_MAX_ESPACE],
		const string & p_niv) {

	for (unsigned int i = 0; i < p_niv.length(); i++) {
		if (isupper(p_niv[i])) {
			if (p_niv[i] == 'A') {
				p_tab_int_niv[i] = 1;
			}
			if (p_niv[i] == 'B') {
				p_tab_int_niv[i] = 2;
			}
			if (p_niv[i] == 'C') {
				p_tab_int_niv[i] = 3;
			}
			if (p_niv[i] == 'D') {
				p_tab_int_niv[i] = 4;
			}
			if (p_niv[i] == 'E') {
				p_tab_int_niv[i] = 5;
			}
			if (p_niv[i] == 'F') {
				p_tab_int_niv[i] = 6;
			}
			if (p_niv[i] == 'G') {
				p_tab_int_niv[i] = 7;
			}
			if (p_niv[i] == 'H') {
				p_tab_int_niv[i] = 8;
			}
			if (p_niv[i] == 'J') {
				p_tab_int_niv[i] = 1;
			}
			if (p_niv[i] == 'K') {
				p_tab_int_niv[i] = 2;
			}
			if (p_niv[i] == 'L') {
				p_tab_int_niv[i] = 3;
			}
			if (p_niv[i] == 'M') {
				p_tab_int_niv[i] = 4;
			}
			if (p_niv[i] == 'N') {
				p_tab_int_niv[i] = 5;
			}
			if (p_niv[i] == 'P') {
				p_tab_int_niv[i] = 7;
			}
			if (p_niv[i] == 'R') {
				p_tab_int_niv[i] = 9;
			}
			if (p_niv[i] == 'S') {
				p_tab_int_niv[i] = 2;
			}
			if (p_niv[i] == 'T') {
				p_tab_int_niv[i] = 3;
			}
			if (p_niv[i] == 'U') {
				p_tab_int_niv[i] = 4;
			}
			if (p_niv[i] == 'V') {
				p_tab_int_niv[i] = 5;
			}
			if (p_niv[i] == 'W') {
				p_tab_int_niv[i] = 6;
			}
			if (p_niv[i] == 'X') {
				p_tab_int_niv[i] = 7;
			}
			if (p_niv[i] == 'Y') {
				p_tab_int_niv[i] = 8;
			}
			if (p_niv[i] == 'Z') {
				p_tab_int_niv[i] = 9;
			}
		}

		else {
			if (p_niv[i] == '0') {
				p_tab_int_niv[i] = 0;
			}
			if (p_niv[i] == '1') {
				p_tab_int_niv[i] = 1;
			}
			if (p_niv[i] == '2') {
				p_tab_int_niv[i] = 2;
			}
			if (p_niv[i] == '3') {
				p_tab_int_niv[i] = 3;
			}
			if (p_niv[i] == '4') {
				p_tab_int_niv[i] = 4;
			}
			if (p_niv[i] == '5') {
				p_tab_int_niv[i] = 5;
			}
			if (p_niv[i] == '6') {
				p_tab_int_niv[i] = 6;
			}
			if (p_niv[i] == '7') {
				p_tab_int_niv[i] = 7;
			}
			if (p_niv[i] == '8') {
				p_tab_int_niv[i] = 8;
			}
			if (p_niv[i] == '9') {
				p_tab_int_niv[i] = 9;
			}
		}
	}
}

} //Namespace util
