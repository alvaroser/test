/*
 * validationFormat.h
 *
 *  Created on: 2016-10-02
 *      Author: etudiant
 */
/**
 * \file validationFormat.h
 * \brief Contient les declarations des fonctions et les constantes.
 * \author Vincent Boily Grant
 * \version 2.1
 * \date 03/10/16
 */
// derniere modification 27-11-16
#include "ContratException.h"
#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>
const int NIV_MAX_ESPACE = 17;
const int IMM_MAX_ESPACE = 7;
/*\namespace
 * util
 */
namespace util {

const std::string FICHIER_IMMATRICULATION = "immatriculation.txt";
const std::string FICHIER_NIV = "niv.txt";

void entrerCamionMain();

bool validerImmatriculation(const std::string& p_plaqueRecue);

bool validerNiv(const std::string& p_niv);

void lecture(const std::string & p_fichierSource);

void translation_niv_int(int p_tab_int_niv[NIV_MAX_ESPACE],
		const std::string & p_niv);
bool validationImmatriculationPromenade(
		const std::string& p_plaqueRecuePromenade);
bool validationImmatriculationCamion(const std::string& p_plaqueRecueCamion);
enum {
	OK, ERREUR
};
} // namspace util
#endif /* VALIDATIONFORMAT_H_ */
