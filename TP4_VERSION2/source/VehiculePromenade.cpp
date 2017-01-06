/*
 * VehiculePromenade.cpp
 ** \brief Implantation de la classe Vehicule Promenade
 *        balises Doxygen
 * \author Vincent Boily Grant
 *  Created on: 2016-11-25
 *      Author: Vincent Boily Grant
 */

#include "VehiculePromenade.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
namespace tp {

/**
 * \brief Constructeur d un Vehicule promenade. Sert a instancier un VehiculePromenade valide.
 * \Param[in]const std::string& p_niv: Le numero didentification du vehicule.
 * \Param[in]const std::string& p_immatriculation : La plaque dimmatriculation du vehicule promenade.
 * \Param[in] int p_nbPlaces : Nombre de place du vehicules. Doit etre plus grand que 0.
 */

VehiculePromenade::VehiculePromenade(const std::string& p_niv,
		const std::string& p_immatriculation, int p_nbPlaces) :
		Vehicule(p_niv, p_immatriculation), m_nbPlaces(p_nbPlaces) {
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
	PRECONDITION(p_nbPlaces > 0)
	POSTCONDITION(m_nbPlaces == p_nbPlaces);
	INVARIANTS();
}

/**
 * \brief Destructeur du vehiculePromenade. Sert a supprimer lobjet.
 */
VehiculePromenade::~VehiculePromenade() {

}

/**
 * \brief La methode sert a donner la tarificationAnnuelle du vehicule Promenade. Le montant est fixe.
 *\return Le montant que le proprietaire doit payer annuellement pour son vehicule de promenade.
 */
double VehiculePromenade::tarificationAnnuelle() const {
	return 217.82;
}

/**
 * \brief La methode asgImmatriculation sert a assigner une nouvelle plaque d immatriculation a un vehiculePromenade.
 * Fait appel a la methode de la classe parent.
 */
void VehiculePromenade::asgImmatriculation(

const std::string& p_immatriculation) {
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
	Vehicule::asgImmatriculation(p_immatriculation);
	INVARIANTS();
}

/**
 * \brief Methode clone permet de faire une copie dun vehiculePromenade a une adresse differente.
 *\return Un vehicule promenade
 */
Vehicule* VehiculePromenade::clone() const {
	return new VehiculePromenade(*this);
}

/**
 * \brief La methode reqVehiculeFormate met les informations du vehicule dans un flux ostringstream.
 *\return Un string contenant les informations du vehiculePromenade formate.
 */
std::string VehiculePromenade::reqVehiculeFormate() const {
	ostringstream os;

	os << Vehicule::reqVehiculeFormate() << endl << "nombre de places   " << ":"
			<< m_nbPlaces << endl << "tarif              " << ":"
			<< tarificationAnnuelle() << "$" << endl;
	return os.str();
}

void VehiculePromenade::verifieInvariant() const {
	INVARIANT(m_nbPlaces > 0);
	//Poids<= 3000 kg, proprietaire habite au quebec.
}

} /* namespace tp */
