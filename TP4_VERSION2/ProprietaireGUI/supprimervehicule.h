/*
 *supprimerVehicule.h
 \brief : Contient les declations des methodes pour supprimer un vehicule.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#ifndef SUPPRIMERVEHICULE_H
#define SUPPRIMERVEHICULE_H

#include <QtGui/QDialog>
#include "ui_supprimervehicule.h"

class supprimerVehicule: public QDialog {
	Q_OBJECT

public:
	supprimerVehicule(QWidget *parent = 0);
	~supprimerVehicule();
	QString reqNiv() const;

private slots:
	void validerSupprimer();

private:
	Ui::SupprimerVehiculeClass ui;
};

#endif // SUPPRIMERVEHICULE_H
