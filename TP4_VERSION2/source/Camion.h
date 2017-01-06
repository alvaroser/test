/*
 * Camion.h
 *
 *  Created on: 2016-11-25
 *      Author: etudiant
 */

#ifndef CAMION_H_
#define CAMION_H_
#include "ContratException.h"
#include "Vehicule.h"

//Constante qui contient les choix de cout annuel des camions.
const double COUT_IMM_CAMION[6] = { 556.50, 881.50, 1512.94, 2132.94, 2698.06,
		3577.06 };

/*\namespace
 * tp
 */
namespace tp {

class Camion: public Vehicule {
public:

	Camion(const std::string& p_niv, const std::string& p_immatriculation,
			int p_poid = 3001, int p_nbEssieux = 2);
	virtual ~Camion();
	virtual double tarificationAnnuelle() const;

	void asgImmatriculation(const std::string& p_immatriculation);
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;
	int reqNbEssieux() const;
	int reqPoids() const;

private:

	int m_poids;
	int m_nbEssieux;
	void verifieInvariant() const;

};

} /* namespace tp */

#endif /* CAMION_H_ */
