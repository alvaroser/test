/*
 ** \brief Implantation de la classe Vehicule Camion
 *        balises Doxygen
 * \author Vincent Boily Grant
 *  Created on: 2016-11-25
 *      Author: Vincent Boily Grant
 */

#include "Camion.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
namespace tp {

/**
 * \brief : Constructeur dun objet camion. Son poids doit etre > 3000 kg et avoir 2 essieux et +.
 * \Param[in]const std::string& p_niv : Le numero didentification du camion
 * \Param[in]const std::string& p_immatriculation :La plaque dimmatriculaiton du camion
 * \Param[in]int p_poids : Le poids du camion
 *\Param[in] int p_nbEssieux : Le nombre dessieux du camion

 */
Camion::Camion(const std::string& p_niv, const std::string& p_immatriculation,
		int p_poids, int p_nbEssieux) :
		Vehicule(p_niv, p_immatriculation), m_poids(p_poids), m_nbEssieux(
				p_nbEssieux) {
	PRECONDITION (util::validationImmatriculationCamion(p_immatriculation))
	PRECONDITION(p_poids > 3000);
	PRECONDITION(p_nbEssieux >= 2);

	POSTCONDITION(m_poids == p_poids);
	POSTCONDITION(m_nbEssieux == p_nbEssieux);
	INVARIANTS();

}
/**
 * \brief Destructeur dun camion. Sert a detruire un objet de type camion.
 */
Camion::~Camion() {

}

/**
 * \brief Methode tarificationAnnuelle sert a determiner
 * le cout annuelle que doit payer le proprietaire selon le type de camion quil possede.
 * Le cout est contenu dans un tableau constant COUT_IMM_CAMION, les possibilites sont:
 * Camion 2 essieux dun poids < 4001 kg
 * Camion 2 essieux dun poids >= 4001 kg
 * Camion 3, 4, 5, 6 essieux.
 *\return  Le cout annuelle que doit payer le proprietaire du camion.
 */
double Camion::tarificationAnnuelle() const {
	PRECONDITION(m_poids > 3000);
	PRECONDITION(m_nbEssieux >= 2);
	if (Camion::reqNbEssieux() == 2) {
		if (Camion::reqPoids() < 4001) {
			return COUT_IMM_CAMION[0];
		} else {
			return COUT_IMM_CAMION[1];
		}

	} else {
		return COUT_IMM_CAMION[(Camion::reqNbEssieux()) - 1];
	}
	POSTCONDITION(m_poids == Camion::reqPoids());
	POSTCONDITION(m_nbEssieux == Camion::reqNbEssieux());
	INVARIANTS();
}

/**
 * \brief La methode asgImmatriculation sert a assigner une nouvelle plaque d immatriculation a un Camion.
 * Fait appel a la methode de la classe parent Vehicule.
 */
void Camion::asgImmatriculation(const std::string& p_immatriculation) {
	PRECONDITION((util::validationImmatriculationCamion(p_immatriculation)));
	Vehicule::asgImmatriculation(p_immatriculation);
	POSTCONDITION(Vehicule::reqImmatriculation() == p_immatriculation);
	INVARIANTS();
}
/**
 * \brief Methode clone permet de faire une copie dun Camion a une adresse differente.
 *\return Un objet camion
 */
Vehicule * Camion::clone() const {
	return new Camion(*this);
}

/**
 * \brief La methode reqVehiculeFormate met les informations du Camion dans un flux ostringstream.
 *\return Un string contenant les informations du Camion formate.
 */
std::string Camion::reqVehiculeFormate() const {
	ostringstream os;

	os << Vehicule::reqVehiculeFormate() << endl << "nombre d'essieux   " << ":"
			<< m_nbEssieux << endl << "poids              " << ":" << m_poids
			<< "kg" << endl << "tarif              " << ":"
			<< tarificationAnnuelle() << "$" << endl;
	return os.str();
}

/**
 * \brief reqNbEssieux sert a connaitre le nombre dessieux du camion
 *\return Un entier: Le nombre dessieux
 */
int Camion::reqNbEssieux() const {
	return m_nbEssieux;
}

/**
 * \brief reqPoids sert a connaitre le poids du camion
 *\return Un entier: Le poids
 */
int Camion::reqPoids() const {
	return m_poids;
}

void Camion::verifieInvariant() const {
	INVARIANT(m_nbEssieux >= 2);
	INVARIANT(m_poids >= 3001);
}
} /* namespace tp */
