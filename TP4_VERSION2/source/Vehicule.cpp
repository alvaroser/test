/**
 * \file Vehicule.cpp
 * \brief Implantation de la classe Vehicule
 *        balises Doxygen
 *        r�vision des commentaires d'en-t�te des m�thodes
 * \author Vincent Boily Grant
 * \date 20 octobre 2016
 * \version 2.1 avec contrat
 */
// derni�re modification : 2016-11-27
#include "Date.h"
#include "Vehicule.h"
#include <string>
#include <iostream>
#include <sstream>
/*\mainpage Travail pratique 3 par Vincent Boily Grant
 *Travail pratique 3 par Vincent Boily Grant
 */
using namespace std;
namespace tp {

/**
 * \brief Constructeur par défaut pour construire un
 * 	véhicule a partir d'un niv valide et d'une plaque d'immatriculation valide.
 * \Param[in] p_niv un string contenant un numéro d'identification de véhicule.
 * \Param[in] p_immatriculation  un string contenant un numéro de plaque valide
 */
Vehicule::Vehicule(const std::string& p_niv,
		const std::string& p_immatriculation) :
		m_niv(p_niv), m_immatriculation(p_immatriculation) {
	PRECONDITION(util::validerNiv(p_niv));
	PRECONDITION(util::validerImmatriculation(p_immatriculation));
	POSTCONDITION(m_niv == p_niv);
	POSTCONDITION(m_immatriculation == p_immatriculation);
	INVARIANTS();
}

/**
 * \brief Méthode qui retourne le numéro d'identification  du véhicule courant
 *\return le N.I.V de l'objet courant.
 */
const std::string& Vehicule::reqNiv() const {
	return m_niv;
}
/**
 * \brief Méthode qui retourne la plaque d'immatriculationn du véhicule courant
 *\return la plaque d'immatriculation de l'objet courant.
 */
const std::string& Vehicule::reqImmatriculation() const {
	return m_immatriculation;
}
/**
 * \brief Sert a changer le numéro de plaque d'un vehiule.
 * \Param[in] p_immatriculation un string qui contient un numéro d'immatriculation.
 */
void Vehicule::asgImmatriculation(const std::string& p_immatriculation) {
	PRECONDITION(util::validerImmatriculation(p_immatriculation));
	m_immatriculation = p_immatriculation;
	POSTCONDITION(m_immatriculation == p_immatriculation);
	INVARIANTS();

}

/**
 * \brief Méthode d'affichage du véhicule dans un format spécifique dans la console.
 *\return Affiche à l'ecran le N.I.V, le numéro de plaque d'immatriculation et la
 * date de création du véhicule.
 */
std::string Vehicule::reqVehiculeFormate() const {
	std::ostringstream outputStream;
	outputStream << "Numéro de serie" << "           : " << reqNiv() << "\n"
			<< "Numéro d'immatriculation" << "  : " << reqImmatriculation()
			<< "\n" << "Date d'enregistrement" << "     : "
			<< m_dateEnregistrement.reqDateFormatee();

	return outputStream.str();
}

/**
 * \brief Méthode qui retourne la date d'enregistrement du Véhicule courant.

 *\return La date d'enregistrement du véhicule.
 */
util::Date Vehicule::reqDateEnregistrement() const {
	return m_dateEnregistrement;
}

/**
 * \brief Méthode pour comparer deux objets Véhicules.
 * \Param[in] p_vehicule Un objet de type Vehicule.
 *\return Un boleeen vrai si les attributs des objets sont tous égaux, faux autrement.
 */
bool Vehicule::operator ==(const Vehicule& p_vehicule) const {
	PRECONDITION(
			util::validationImmatriculationPromenade(
					p_vehicule.reqImmatriculation())
					|| util::validationImmatriculationCamion(
							p_vehicule.reqImmatriculation()));
	PRECONDITION(util::validerNiv(p_vehicule.reqNiv()));
	return ((m_niv == p_vehicule.m_niv)
			&& (m_immatriculation == p_vehicule.m_immatriculation)
			&& (m_dateEnregistrement == p_vehicule.m_dateEnregistrement));
} // A changer partie alvaro

/*
void Vehicule::verifieInvariant() const {
	INVARIANT(util::validerNiv(m_niv) == 1);
	INVARIANT(util::validerImmatriculation(m_immatriculation) == 1);
*/

}
}
/* namespace tp */
