/*
 * ProprietaireTesteur.cpp
 *
 *  Created on: 2016-12-05
 *      Author: etudiant
 */

/*
 * ProprietaireTesteur.cpp
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "VehiculePromenade.h"
#include "Proprietaire.h"
#include "VehiculeException.h"
#include "Camion.h"
using namespace tp;
using namespace std;
/**
 * \brief Test du constructeur Proprietaire
 * 		  Cas valides: Création d'un objet VehiculePromenade et vérification de tous les attributs
 *		  Cas invalides:
 *		       nom vide
 *		       prenom vide
 *
 */

TEST(ProprietaireTesteur,ConstructeurDefaut) {
	try {
		Proprietaire UnProprietaireTest("Simpson", "Homer");
		ASSERT_EQ("Simpson", UnProprietaireTest.reqNom());
		ASSERT_EQ("Homer", UnProprietaireTest.reqPrenom());

	} catch (ContratException& e) {
		cout<<e.reqTexteException();
	}
}
//cas invalide
TEST(ProprietaireTesteur,ConstructeurNomInvalide) {
	ASSERT_THROW(
			Proprietaire UnProprietaireTest("", "Homer"),
			PreconditionException);
}
TEST(ProprietaireTesteur,ConstructeurPrenomInvalide) {
	ASSERT_THROW(
			Proprietaire UnProprietaireTest("Simpson", ""),
			PreconditionException);
}

/**
 * \class UnProprietaire
 * \brief Fixture  UnProprietaire pour la création d'un objet Proprietaire pour les tests
 */
class UnProprietaire: public ::testing::Test {
public:
	UnProprietaire() :
			t_proprietaire("Simpson", "Homer") {
	}
	;

	Proprietaire t_proprietaire;
};

/*Brief Test de la methode reqNom()
 * Cas valide : Verification des informations contenus dans le retour de lobjet t_proprietaire
 * Cas invalide: Aucun
 * */
TEST_F(UnProprietaire, reqNom) {
	ASSERT_EQ("Simpson",t_proprietaire.reqNom());
}

/**
 * \brief Test de la méthode reqPrenom()
 *        Cas valides: vérifier le retour des informations de l'objet t_proprietaire
 *        Cas invalides: aucun
 */
TEST_F(UnProprietaire, reqPrenom) {
	ASSERT_EQ("Homer",t_proprietaire.reqPrenom());
}

/**
 * \brief Test de la méthode ajouterVehicule()
 *        Cas valides: si on ajoute un vehicule identique deux fois avec
 *        la methode ajouterVehicule() et qu une exception
 *        VehiculeDejaPresentException est levee, cest que la methode fonctionne.
 *
 *        Cas invalides: aucun
 */
TEST_F(UnProprietaire, ajouterVehicule) {

	Camion VehiculeValide("3VWFE21C04M000001", "L000000", 4000, 4);
	t_proprietaire.ajouterVehicule(VehiculeValide);
	ASSERT_THROW(t_proprietaire.ajouterVehicule(VehiculeValide), VehiculeDejaPresentException);

}
/**
 * \brief Test de la méthode reqProprietaireFormate()
 *        Cas valides: vérifier le retour des information sur l'objets t_propretaire formaté
 *        Cas invalides: aucun
 */
TEST_F(UnProprietaire, reqProprietaireFormate) {

	std::ostringstream os;
	VehiculePromenade unVehProm("2B3LJ74WX8H302695", "123 ABC", 5); //On crée un objet VehiculePromenade
	t_proprietaire.ajouterVehicule(unVehProm);
	string tirait = "--------------------";
	os << endl << "Proprietaire" << endl << tirait << endl << "Nom       " << ": "
	<< "Simpson" << endl << "Prenom    " << ": " << "Homer" << endl
	<< tirait << endl<<unVehProm.reqVehiculeFormate()<<endl<<tirait;

	ASSERT_EQ(os.str(),t_proprietaire.reqProprietaireFormate());

}

/**
 * \brief Test de la methode supprimerVehicule.
 *
 *cas valide :  On essaie de supprimer un vehicule en passant un NIV valide avec la methode supprimerVehicule().
 * Comme aucun vehicule n a ete ajoute prealablement, une exception de type VehiculeNonPresentException est levee.

 */
TEST_F (UnProprietaire, supprimerVehicule) {

	ASSERT_THROW(t_proprietaire.supprimerVehicule("11111111111111111"), VehiculeNonPresentException);

}

/**
 * \brief Test de la methode VehiculeDejaPresent().
 * On ajoute deux fois le meme vehicule avec la methode ajouterVehicule().
 * cas valide: Si une exception de type VehiculeDejaPresentException est levee , tout fonctionne.
 *\
 */
TEST_F(UnProprietaire, VehiculeEstDejaPresent) {
	Camion VehiculeValide("3VWFE21C04M000001", "L000000", 4000, 4);
	t_proprietaire.ajouterVehicule(VehiculeValide);
	ASSERT_THROW(t_proprietaire.ajouterVehicule(VehiculeValide), VehiculeDejaPresentException);
}

