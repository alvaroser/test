/*
 *saisieVehiculePromenade.cpp
 \brief : Contient les definitions des methodes pour saisir un vehicule de promenade.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#include "saisievehiculepromenade.h"
#include <QMessageBox>

/**
 * \brief Constructeur de la fenetre pour saisir un vehicule de promenade.
 * \Param[in] *parent : un pointeur vers la main window.
 */
saisieVehiculePromenade::saisieVehiculePromenade(QWidget *parent) :
		QDialog(parent) {
	ui.setupUi(this);
	QObject::connect(ui.pushButtonOkayVehPromenade, SIGNAL(clicked()), this,
			SLOT(validerVehiculePromenade()));
}

/**
 * \brief Destructeur

 */
saisieVehiculePromenade::~saisieVehiculePromenade() {

}

/**
 * \brief serta valider que le vehiculePromenade est valide.

 */
void saisieVehiculePromenade::validerVehiculePromenade() {
	if (ui.lineEdit_Niv_VehProm->text().isEmpty()) {
		QString message("Le niv ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if (ui.lineEdit_ImmatriculationVehProm->text().isEmpty()) {
		QString message("La plaque d'immatriculation\n ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}

	if (ui.lineEdit_NbSieges_VehProm->text().isEmpty()) {
		QString message("Le nombre de sieges ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}
	if (ui.lineEdit_NbSieges_VehProm->text().toInt() < 1) {
		QString message("Le nombre de sieges doit être supérieur à 0 ");
		QMessageBox::information(this, "Erreur!", message);
		return;
	}

	else {
		accept();
	}

}

//Accesseur pour la récupération de l'attribut
/**
 * \return Le niv du vehicule de promenade

 */
QString saisieVehiculePromenade::reqNiv() const {
	return (ui.lineEdit_Niv_VehProm->text());
}

/**
 * \return La plaque dimmatriculation du vehicule de promenade

 */
QString saisieVehiculePromenade::reqImmatriculation() const {
	return (ui.lineEdit_ImmatriculationVehProm->text());
}

/**
 * \return Le nb de sieges du vehicule de promenade

 */
QString saisieVehiculePromenade::reqNbSieges() const {
	return (ui.lineEdit_NbSieges_VehProm->text());
}
