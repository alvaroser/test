/*
 * VehiculeException.h
 ** \brief Implantation de classe dexception avec hierarchie.
 *        balises Doxygen
 *        Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */

#ifndef VEHICULEEXCEPTION_H_
#define VEHICULEEXCEPTION_H_

#include <stdexcept>

class VehiculeException: public std::runtime_error {
public:
	VehiculeException(const std::string & p_raison) :
			std::runtime_error(p_raison) {
	}
	;
};

class VehiculeDejaPresentException: public VehiculeException {
public:
	VehiculeDejaPresentException(const std::string& p_raison) :
			VehiculeException(p_raison) {
	}
	;
};

class VehiculeNonPresentException: public VehiculeException {
public:
	VehiculeNonPresentException(const std::string& p_raison) :
			VehiculeException(p_raison) {
	}
	;
};

#endif /* VEHICULEXCEPTION_H_ */

