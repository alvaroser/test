/********************************************************************************
 ** Form generated from reading UI file 'proprietairegui.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.7
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_PROPRIETAIREGUI_H
#define UI_PROPRIETAIREGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProprietaireGUIClass {
public:
	QAction *actionVehicule_Promenade;
	QAction *action_Ajout_Vehicule_Promenade;
	QAction *action_Ajout_Camion;
	QAction *actionSupprimer_Vehicule;
	QAction *actionQuitter;
	QWidget *centralwidget;
	QTextBrowser *affichage;
	QMenuBar *menubar;
	QMenu *menuMenu;
	QMenu *menu_ajouterVehicule;
	QStatusBar *statusbar;

	void setupUi(QMainWindow *ProprietaireGUIClass) {
		if (ProprietaireGUIClass->objectName().isEmpty())
			ProprietaireGUIClass->setObjectName(
					QString::fromUtf8("ProprietaireGUIClass"));
		ProprietaireGUIClass->resize(341, 282);
		actionVehicule_Promenade = new QAction(ProprietaireGUIClass);
		actionVehicule_Promenade->setObjectName(
				QString::fromUtf8("actionVehicule_Promenade"));
		action_Ajout_Vehicule_Promenade = new QAction(ProprietaireGUIClass);
		action_Ajout_Vehicule_Promenade->setObjectName(
				QString::fromUtf8("action_Ajout_Vehicule_Promenade"));
		action_Ajout_Camion = new QAction(ProprietaireGUIClass);
		action_Ajout_Camion->setObjectName(
				QString::fromUtf8("action_Ajout_Camion"));
		actionSupprimer_Vehicule = new QAction(ProprietaireGUIClass);
		actionSupprimer_Vehicule->setObjectName(
				QString::fromUtf8("actionSupprimer_Vehicule"));
		actionQuitter = new QAction(ProprietaireGUIClass);
		actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
		centralwidget = new QWidget(ProprietaireGUIClass);
		centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		affichage = new QTextBrowser(centralwidget);
		affichage->setObjectName(QString::fromUtf8("affichage"));
		affichage->setGeometry(QRect(20, 0, 301, 231));
		affichage->setAcceptDrops(false);
		affichage->setReadOnly(true);
		affichage->setOverwriteMode(true);
		ProprietaireGUIClass->setCentralWidget(centralwidget);
		menubar = new QMenuBar(ProprietaireGUIClass);
		menubar->setObjectName(QString::fromUtf8("menubar"));
		menubar->setGeometry(QRect(0, 0, 341, 27));
		menuMenu = new QMenu(menubar);
		menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
		menu_ajouterVehicule = new QMenu(menuMenu);
		menu_ajouterVehicule->setObjectName(
				QString::fromUtf8("menu_ajouterVehicule"));
		ProprietaireGUIClass->setMenuBar(menubar);
		statusbar = new QStatusBar(ProprietaireGUIClass);
		statusbar->setObjectName(QString::fromUtf8("statusbar"));
		ProprietaireGUIClass->setStatusBar(statusbar);

		menubar->addAction(menuMenu->menuAction());
		menuMenu->addAction(menu_ajouterVehicule->menuAction());
		menuMenu->addSeparator();
		menuMenu->addAction(actionSupprimer_Vehicule);
		menuMenu->addAction(actionQuitter);
		menu_ajouterVehicule->addAction(action_Ajout_Vehicule_Promenade);
		menu_ajouterVehicule->addAction(action_Ajout_Camion);

		retranslateUi(ProprietaireGUIClass);
		QObject::connect(action_Ajout_Vehicule_Promenade, SIGNAL(triggered()),
				ProprietaireGUIClass, SLOT(dialogVehiculePromenade()));
		QObject::connect(action_Ajout_Camion, SIGNAL(triggered()),
				ProprietaireGUIClass, SLOT(dialogCamion()));
		QObject::connect(actionQuitter, SIGNAL(triggered()),
				ProprietaireGUIClass, SLOT(close()));
		QObject::connect(actionSupprimer_Vehicule, SIGNAL(triggered()),
				ProprietaireGUIClass, SLOT(dialogSupprimerVehicule()));

		QMetaObject::connectSlotsByName(ProprietaireGUIClass);
	} // setupUi

	void retranslateUi(QMainWindow *ProprietaireGUIClass) {
		ProprietaireGUIClass->setWindowTitle(
				QApplication::translate("ProprietaireGUIClass",
						"Gestion de Vehicules", 0, QApplication::UnicodeUTF8));
		actionVehicule_Promenade->setText(
				QApplication::translate("ProprietaireGUIClass",
						"Vehicule Promenade", 0, QApplication::UnicodeUTF8));
		action_Ajout_Vehicule_Promenade->setText(
				QApplication::translate("ProprietaireGUIClass",
						"Vehicule Promenade", 0, QApplication::UnicodeUTF8));
		action_Ajout_Camion->setText(
				QApplication::translate("ProprietaireGUIClass", "Camion", 0,
						QApplication::UnicodeUTF8));
		actionSupprimer_Vehicule->setText(
				QApplication::translate("ProprietaireGUIClass",
						"Supprimer Vehicule", 0, QApplication::UnicodeUTF8));
		actionQuitter->setText(
				QApplication::translate("ProprietaireGUIClass", "Quitter", 0,
						QApplication::UnicodeUTF8));
		menuMenu->setTitle(
				QApplication::translate("ProprietaireGUIClass", "Menu", 0,
						QApplication::UnicodeUTF8));
		menu_ajouterVehicule->setTitle(
				QApplication::translate("ProprietaireGUIClass",
						"Ajouter Vehicule", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class ProprietaireGUIClass: public Ui_ProprietaireGUIClass {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPRIETAIREGUI_H
