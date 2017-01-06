/*
 * Proprietaire.cpp
 ** \brief Implantation de la classe Vehicule Proprietaire
 *        balises Doxygen

 *  Created on: 2016-12-14
 *      Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 derniere modif 2016-12-14
 */
#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_
#include "ContratException.h"
#include "Vehicule.h"
#include "VehiculeException.h"
#include <vector>
#include <string>
#include <iostream>
/*\namespace
 * tp
 */
namespace tp {

class Proprietaire {
public:
	Proprietaire(const std::string& p_nom, const std::string& p_prenom);

	~Proprietaire();
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;

	std::string reqProprietaireFormate() const;
	void ajouterVehicule(const Vehicule& p_nouveauVehicule);
	void supprimerVehicule(const std::string& p_niv);
private:
	bool VehiculeEstDejaPresent(const std::string& p_niv) const;
	std::string m_nom;
	std::string m_prenom;
	std::vector<Vehicule*> m_vVehicules;
	void verifieInvariant() const;
	Proprietaire(const Proprietaire& p_proprietaire);
	const Proprietaire &operator =(const Proprietaire& p_proprietaire);
};

} /* namespace tp */

#endif /* PROPRIETAIRE_H_ */
