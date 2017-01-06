/*
 *ProprietaireGUI.h
 \brief : Contient les declarations des methodes de la fenetre principale.
 *
 Author: Vincent Boily Grant
 *      Author: Serrano Gomez, Alvaro
 *      created 2016-12-14
 */
#ifndef PROPRIETAIREGUI_H
#define PROPRIETAIREGUI_H

#include <QtGui/QMainWindow>
#include <string>
#include "ui_proprietairegui.h"
#include "Proprietaire.h"

class ProprietaireGUI: public QMainWindow {
	Q_OBJECT

public:

	ProprietaireGUI(QWidget *parent, tp::Proprietaire& p_Proprietaire);
	~ProprietaireGUI();

private slots:
	void dialogVehiculePromenade();
	void dialogCamion();
	void dialogSupprimerVehicule();
private:
	tp::Proprietaire m_Proprietaire;
	Ui::ProprietaireGUIClass ui;
};

#endif // PROPRIETAIREGUI_H
