/*
 *saisieCamion.cpp
 \brief : Contient les definitions des methodes pour saisir un camions.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */

#include "saisiecamion.h"
#include "Proprietaire.h"
#include <QMessageBox>
#include "VehiculeException.h"
#include <sstream>
#include <iostream>
#include <string>

/**
 * \brief Constructeur de la fenetre pour saisir un camion QT
 * \Param[in] *parent : un pointeur vers la main window.
 *\return
 */
saisieCamion::saisieCamion(QWidget *parent) :
		QDialog(parent) {
	ui.setupUi(this);
	QObject::connect(ui.pushButtonSaisieCamionOk, SIGNAL(clicked()), this,
			SLOT(validerCamion()));
}

/**\Brief Sert a valider le camion saisie.

 */
void saisieCamion::validerCamion() {
	if (ui.lineEditNiv->text().isEmpty()) {
		QString message("Le niv ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if (ui.lineEditImmatriculation->text().isEmpty()) {
		QString message("La plaque d'immatriculation\n ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}

	if (ui.lineEditPoids->text().isEmpty()) {
		QString message("Le poids ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if (ui.lineEditEssieux->text().isEmpty()) {
		QString message("Le nombre d'esieux ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if (ui.lineEditPoids->text().toInt() < 3001) {
		QString message("Le poids doit être supérieur à 3000");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}

	if (ui.lineEditEssieux->text().toInt() < 2) {
		QString message("Le nombre d'essieux doit être supérieur ou égal à 2");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}

	else {
	}
	accept();
}

/**\brief  Destructeur
 * \return Le niv du vehicule de promenade

 */
saisieCamion::~saisieCamion() {

}

//Accesseur pour la récupération de l'attribut
/**\brief  Sert a retourner le niv
 * \return Le niv du camion

 */
QString saisieCamion::reqNiv() const {
	return (ui.lineEditNiv->text());
}

/**\brief  Sert a retourner la plaque dimmatriculation
 * \return La plaque dimmatriculation du camion

 */
QString saisieCamion::reqImmatriculation() const {
	return (ui.lineEditImmatriculation->text());
}

/**\brief  Sert a retourner le poids du camion
 * \return Le poids du camion

 */
QString saisieCamion::reqPoids() const {
	return (ui.lineEditPoids->text());
}

/**\brief  Sert a retourner le niv
 * \return Le nombre d'essieux du camion

 */
QString saisieCamion::reqNbEssieux() const {
	return (ui.lineEditEssieux->text());
}

