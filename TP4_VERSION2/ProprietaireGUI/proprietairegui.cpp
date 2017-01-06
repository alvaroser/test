/*
 *ProprietaireGUI.cpp
 \brief : Contient les methodes de la fenetre principale.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#include "proprietairegui.h"
#include "saisievehiculepromenade.h"
#include "saisiecamion.h"
#include "supprimervehicule.h"
#include "VehiculeException.h"
#include <stdexcept>
#include <QMessageBox>

using namespace tp;

/**
 * \brief Constructeur de la fenetre principale QT
 * \Param[in] *parent : un pointeur vers la main window.
 * \Param[in] p_Proprietaire , un objet de type proprietaire
 *\return
 */
ProprietaireGUI::ProprietaireGUI(QWidget *parent,
		tp::Proprietaire& p_Proprietaire) :
		QMainWindow(parent), m_Proprietaire(p_Proprietaire.reqPrenom(),
				p_Proprietaire.reqNom()) {

	ui.setupUi(this);
}

ProprietaireGUI::~ProprietaireGUI() {

}

/**
 * \brief methode pour afficher une fenetre qui demande des informations servant a ajouter un vehicule de promenade.

 *
 */
void ProprietaireGUI::dialogVehiculePromenade() {
	saisieVehiculePromenade SaisieVehicule(this);
	try {
		if (SaisieVehicule.exec()) {
			VehiculePromenade unVehiculeProm(
					SaisieVehicule.reqNiv().toStdString(),
					SaisieVehicule.reqImmatriculation().toStdString(),
					SaisieVehicule.reqNbSieges().toInt());
			m_Proprietaire.ajouterVehicule(unVehiculeProm);
			ui.affichage->setText(
					m_Proprietaire.reqProprietaireFormate().c_str());
		}
	} catch (PreconditionException& e) {
		QString message = ("NIV ou matricule invalid");
		QMessageBox::information(this, "Erreur!", message);
	} catch (VehiculeDejaPresentException& e) {
		QString message = (e.what());
		QMessageBox::information(this, "Erreur!", message);
	}
}
/**
 * \brief methode pour afficher une fenetre qui demande des informations servant a ajouter un camion le vehicule.

 *
 */

void ProprietaireGUI::dialogCamion() {
	saisieCamion SaisieCamion(this);
	try {
		if (SaisieCamion.exec()) {
			Camion unCamion(SaisieCamion.reqNiv().toStdString(),
					SaisieCamion.reqImmatriculation().toStdString(),
					SaisieCamion.reqPoids().toInt(),
					SaisieCamion.reqNbEssieux().toInt());
			m_Proprietaire.ajouterVehicule(unCamion);
			ui.affichage->setText(
					m_Proprietaire.reqProprietaireFormate().c_str());
		}
	} catch (PreconditionException& e) {
		QString message = ("NIV ou matricule invalid");
		QMessageBox::information(this, "Erreur!", message);
	} catch (VehiculeDejaPresentException& e) {
		QString message = (e.what());
		QMessageBox::information(this, "Erreur!", message);
	}
}

/**
 * \brief methode pour afficher une fenetre qui demande des informations servant a supprimer le vehicule.

 *
 */
void ProprietaireGUI::dialogSupprimerVehicule() {
	supprimerVehicule SuprVehicule(this);
	try {
		if (SuprVehicule.exec()) {

			m_Proprietaire.supprimerVehicule(
					SuprVehicule.reqNiv().toStdString());
		}

	} catch (VehiculeNonPresentException& e) {
		QString message = (e.what());
		QMessageBox::information(this, "Erreur!", message);
	} catch (PreconditionException& e) {
		QString message = ("NIV invalid");
		QMessageBox::information(this, "Erreur!", message);
	}
	try {
		ui.affichage->clear();
		ui.affichage->setText(m_Proprietaire.reqProprietaireFormate().c_str());
	} catch (...) {
		QString message = ("Fatal error");
		QMessageBox::information(this, "Erreur!", message);
	}

}

