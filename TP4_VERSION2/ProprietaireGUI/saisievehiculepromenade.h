/*
 *saisieVehiculePromenade.h
 \brief : Contient les declarations des methodes pour saisir des informations sur un vehicule de promenade.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#ifndef SAISIEVEHICULEPROMENADE_H
#define SAISIEVEHICULEPROMENADE_H
#include "VehiculePromenade.h"
#include <QtGui/QDialog>
#include "ui_saisievehiculepromenade.h"

class saisieVehiculePromenade: public QDialog {
	Q_OBJECT

public:
	saisieVehiculePromenade(QWidget *parent = 0);
	~saisieVehiculePromenade();
	QString reqNiv() const;
	QString reqImmatriculation() const;
	QString reqNbSieges() const;private slots:

private slots:
	void validerVehiculePromenade();

private:
	Ui::saisieVehiculePromenadeClass ui;
};

#endif // SAISIEVEHICULEPROMENADE_H
