/**
 * \file Vehicule.h
 * \brief Fichier qui contient l'interface de la classe vehicule et
 * qui sert au maintien et à la manipulation des véhicules.

 *      Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro

 * \date 20 octobre 2016
 * \version 2.1 avec contrat
 */
// derniere modif 2016-12-14
#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <string>
#include <vector>
#include "Date.h"
#include "ContratException.h"
#include "validationFormat.h"

/*\namespace
 * tp
 */
namespace tp {
/***
 * \class Vehicule
 * \brief Sert à créer des objets de type Vehicule.
 * 			Sert à changer au besoin la plaque d'immatriculation.
 * 			Cette classe peut comparer les attributs de deux objets véhicules pour
 * 			savoir s'ils sont égaux.
 * 			La classe utilise la classe Date pour la création de son véhicule.
 *
 *
 */
class Vehicule {

public:
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
	virtual ~Vehicule() {
	}
	;
	const std::string& reqNiv() const;
	const std::string& reqImmatriculation() const;
	bool operator==(const Vehicule& p_vehicule) const;
	util::Date reqDateEnregistrement() const;

	virtual Vehicule* clone() const = 0;
	virtual double tarificationAnnuelle() const=0;
	virtual std::string reqVehiculeFormate() const=0;

protected:

	void asgImmatriculation(const std::string & p_immatriculation);

private:
	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;
	void verifieInvariant() const;
};

} /* namespace tp */

#endif /* VEHICULE_H_ */
