/*
 * VehiculePromenade.h
 *
 *  Created on: 2016-11-25
 *      Author: etudiant
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_

#include "Vehicule.h"
#include <iostream>
#include "ContratException.h"
/*\namespace
 * tp
 */
namespace tp {

class VehiculePromenade: public Vehicule {
public:
	VehiculePromenade(const std::string& p_niv,
			const std::string& p_immatriculation, int p_nbPlaces = 2);
	virtual ~VehiculePromenade();

	virtual double tarificationAnnuelle() const;

	void asgImmatriculation(const std::string& p_immatriculation);
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;

private:
	int m_nbPlaces;
	void verifieInvariant() const;
};

} /* namespace tp */

#endif /* VEHICULEPROMENADE_H_ */
