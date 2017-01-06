/*
 * Proprietaire.cpp
 ** \brief Implantation de la classe Vehicule Proprietaire
 *        balises Doxygen

 *  Created on: 2016-12-14
 *      Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 */

#include "Proprietaire.h"
#include "Vehicule.h"
#include <sstream>
#include <iostream>
using namespace std;

namespace tp {

/**
 * \brief  Constructeur dun proprietaire
 * \Param[in] p_nom Un string contenant le nom du proprietaire.
 * \Param[in] p_prenom Un string. Le prenom du proprietaire.
 */
Proprietaire::Proprietaire(const std::string& p_nom,
		const std::string& p_prenom) :
		m_nom(p_nom), m_prenom(p_prenom) {
	PRECONDITION(!p_nom.empty());
	PRECONDITION(!p_prenom.empty());

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);

	INVARIANTS();
}

/**
 * \brief Destructeur de lobjet proprietaire. Les vehicules presents dans le vecteur m_vVehicules
 * sont detruits avant de detruire le proprietaire.
 */
Proprietaire::~Proprietaire() {

	if (m_vVehicules.empty() == false) {

		vector<Vehicule*>::iterator it;
		for (it = m_vVehicules.begin(); it < m_vVehicules.end(); it++) {

			m_vVehicules.erase(it);
			delete (*it);
		}
	}

}
/**
 * \brief Methode reqNom() pour aller chercher le nom du proprietaire
 *\return  retourne un string par reference constante.
 */
const std::string& Proprietaire::reqNom() const {
	return m_nom;
}

/**
 * \brief Methode reqPrenom() pour aller chercher le prenom du proprietaire
 *\return  retourne un string par reference constante.
 */
const std::string& Proprietaire::reqPrenom() const {
	return m_prenom;
}

/**
 * \brief Methode reqProprietaireFormate() pour aller chercher le prenom du proprietaire
 *\return  retourne un flux ostringstream contenant les informations du proprietaire et de ses vehicules.
 */
std::string Proprietaire::reqProprietaireFormate() const {
	std::ostringstream os;

	string tirait = "--------------------";
	os << endl << "Proprietaire" << endl << tirait << endl << "Nom       "
			<< ": " << m_nom << endl << "Prenom    " << ": " << m_prenom << endl
			<< tirait;
	if (m_vVehicules.empty() == false) {

		vector<Vehicule*>::const_iterator it;
		for (it = m_vVehicules.begin(); it < m_vVehicules.end(); it++) {

			os << endl << (*it)->reqVehiculeFormate() << endl << tirait;
		}

		return os.str();
	}
	return os.str();
}

/**
 * \brief Methode ajouterVehicule( const Vehicule& p_nouveauVehicule).
 * param[in] p_nouveauVehicule : un objet de type vehicule.
 * Sert a ajouter un pointeur de vehicule dans le vecteur contenant les vehicules du proprietaire
 */
void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule) {
	PRECONDITION(
			util::Date::validerDate(
					p_nouveauVehicule.reqDateEnregistrement().reqJour(),
					p_nouveauVehicule.reqDateEnregistrement().reqMois(),
					p_nouveauVehicule.reqDateEnregistrement().reqAnnee()));
	PRECONDITION(
			util::validationImmatriculationPromenade(
					p_nouveauVehicule.reqImmatriculation())
					|| util::validationImmatriculationCamion(
							p_nouveauVehicule.reqImmatriculation()));
	PRECONDITION(util::validerNiv(p_nouveauVehicule.reqNiv()));

	if (!VehiculeEstDejaPresent(p_nouveauVehicule.reqNiv())) {

		m_vVehicules.push_back(p_nouveauVehicule.clone());
	} else {
		throw VehiculeDejaPresentException(
				p_nouveauVehicule.reqVehiculeFormate());
	}
	INVARIANTS();

}

/**
 * \brief  prend en parametre le niv du vehicule a supprimer
 * il fait une iteration sur le vecteur de vehicule pour verifier sil y en a un qui correspond au niv passer en parametre et le supprimer si cest le cas.
 * sinon rien ne se passe.
 * param[in] p_niv : le numero d identificaiton du vehicule
 */
void Proprietaire::supprimerVehicule(const std::string& p_niv) {
	PRECONDITION(util::validerNiv(p_niv));
	if (!VehiculeEstDejaPresent(p_niv)) {
		throw VehiculeNonPresentException(
				"Impossible de supprimer le Vehicule, il n est pas present dans la liste");
	}
	vector<Vehicule*>::iterator it;
	for (it = m_vVehicules.begin(); it < m_vVehicules.end(); it++) {
		if ((*it)->reqNiv() == p_niv) {
			m_vVehicules.erase(it);
			delete (*it);
		}
	}
	INVARIANTS();
}

/**
 * \brief Methode VehiculeEstdejaPresent (const std::string& p_niv)
 *\param[in] p_niv : le numero d identificaiton du vehicule
 *\return booleen vrai si le vehicule est dans le vecteur des vehicules ou faux autrement.
 */
bool Proprietaire::VehiculeEstDejaPresent(const std::string& p_niv) const {
	bool reponse = false;
	if (m_vVehicules.empty()) {
		return reponse;
	} else {
		vector<Vehicule*>::const_iterator it;
		for (it = m_vVehicules.begin(); it < m_vVehicules.end(); it++) {

			if ((*it)->reqNiv() == p_niv) {
				return reponse = true;
			}

		}
		INVARIANTS();
		return reponse;
	}
}
void Proprietaire::verifieInvariant() const {
	INVARIANT(!(m_nom.empty()));
	INVARIANT(!(m_prenom.empty()));

}
} /* namespace tp */

