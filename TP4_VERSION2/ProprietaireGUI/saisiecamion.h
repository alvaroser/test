/*
 *saisieCamion.h
 \brief : Contient les declarations des methodes pour saisir un camion.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#ifndef SAISIECAMION_H
#define SAISIECAMION_H
#include "Camion.h"
#include <QtGui/QDialog>
#include "ui_saisiecamion.h"

class saisieCamion: public QDialog {
	Q_OBJECT

public:
	saisieCamion(QWidget *parent = 0);
	~saisieCamion();
	QString reqNiv() const;
	QString reqImmatriculation() const;
	QString reqPoids() const;
	QString reqNbEssieux() const;

private slots:
	void validerCamion();
private:

	Ui::saisieCamionClass ui;
};

#endif // SAISIECAMION_H
