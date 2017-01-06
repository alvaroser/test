/*
 *supprimerVehicule.cpp
 \brief : Contient les definitions des methodes pour supprimer un vehicule.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#include "supprimervehicule.h"
#include <QMessageBox>

/**
 * \brief Constructeur de la fenetre pour supprimer un vehicule
 * \Param[in] *parent : un pointeur vers la main window.
 */
supprimerVehicule::supprimerVehicule(QWidget *parent) :
		QDialog(parent) {
	ui.setupUi(this);
}

supprimerVehicule::~supprimerVehicule() {

}
/**
 * \brief sert a valider si le Niv est valide pour ensuite supprimer le vehicule

 */
void supprimerVehicule::validerSupprimer() {
	if (ui.lineEditNivSupprimer->text().isEmpty()) {
		QString message("Le Niv ne doit pas être vide");
		QMessageBox::information(this, "Erreur!", message);
		return;
	} else {
		accept();
	}

}

/**
 * \brief sert a mettre en text le niv a supprimer.
 * \return un QString contenant le niv du vehicule a supprimer.

 */
QString supprimerVehicule::reqNiv() const {
	return (ui.lineEditNivSupprimer->text());
}
