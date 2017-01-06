/********************************************************************************
 ** Form generated from reading UI file 'saisievehiculepromenade.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.7
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_SAISIEVEHICULEPROMENADE_H
#define UI_SAISIEVEHICULEPROMENADE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saisieVehiculePromenadeClass {
public:
	QPushButton *pushButtonOkayVehPromenade;
	QLabel *labelSoustitreAjoutVehiculePromenade;
	QLabel *label_Niv_VehProm;
	QLabel *label_Immatriculation_VehProm;
	QLabel *label_Nb_Sieges;
	QLineEdit *lineEdit_Niv_VehProm;
	QLineEdit *lineEdit_ImmatriculationVehProm;
	QLineEdit *lineEdit_NbSieges_VehProm;

	void setupUi(QDialog *saisieVehiculePromenadeClass) {
		if (saisieVehiculePromenadeClass->objectName().isEmpty())
			saisieVehiculePromenadeClass->setObjectName(
					QString::fromUtf8("saisieVehiculePromenadeClass"));
		saisieVehiculePromenadeClass->resize(351, 212);
		pushButtonOkayVehPromenade = new QPushButton(
				saisieVehiculePromenadeClass);
		pushButtonOkayVehPromenade->setObjectName(
				QString::fromUtf8("pushButtonOkayVehPromenade"));
		pushButtonOkayVehPromenade->setGeometry(QRect(260, 180, 85, 27));
		labelSoustitreAjoutVehiculePromenade = new QLabel(
				saisieVehiculePromenadeClass);
		labelSoustitreAjoutVehiculePromenade->setObjectName(
				QString::fromUtf8("labelSoustitreAjoutVehiculePromenade"));
		labelSoustitreAjoutVehiculePromenade->setGeometry(
				QRect(50, 20, 241, 20));
		labelSoustitreAjoutVehiculePromenade->setAlignment(Qt::AlignCenter);
		label_Niv_VehProm = new QLabel(saisieVehiculePromenadeClass);
		label_Niv_VehProm->setObjectName(
				QString::fromUtf8("label_Niv_VehProm"));
		label_Niv_VehProm->setGeometry(QRect(90, 60, 31, 31));
		label_Immatriculation_VehProm = new QLabel(
				saisieVehiculePromenadeClass);
		label_Immatriculation_VehProm->setObjectName(
				QString::fromUtf8("label_Immatriculation_VehProm"));
		label_Immatriculation_VehProm->setGeometry(QRect(20, 100, 111, 31));
		label_Nb_Sieges = new QLabel(saisieVehiculePromenadeClass);
		label_Nb_Sieges->setObjectName(QString::fromUtf8("label_Nb_Sieges"));
		label_Nb_Sieges->setGeometry(QRect(10, 140, 111, 31));
		lineEdit_Niv_VehProm = new QLineEdit(saisieVehiculePromenadeClass);
		lineEdit_Niv_VehProm->setObjectName(
				QString::fromUtf8("lineEdit_Niv_VehProm"));
		lineEdit_Niv_VehProm->setGeometry(QRect(120, 60, 191, 27));
		lineEdit_ImmatriculationVehProm = new QLineEdit(
				saisieVehiculePromenadeClass);
		lineEdit_ImmatriculationVehProm->setObjectName(
				QString::fromUtf8("lineEdit_ImmatriculationVehProm"));
		lineEdit_ImmatriculationVehProm->setGeometry(QRect(120, 100, 191, 27));
		lineEdit_NbSieges_VehProm = new QLineEdit(saisieVehiculePromenadeClass);
		lineEdit_NbSieges_VehProm->setObjectName(
				QString::fromUtf8("lineEdit_NbSieges_VehProm"));
		lineEdit_NbSieges_VehProm->setGeometry(QRect(120, 140, 51, 27));

		retranslateUi(saisieVehiculePromenadeClass);

		QMetaObject::connectSlotsByName(saisieVehiculePromenadeClass);
	} // setupUi

	void retranslateUi(QDialog *saisieVehiculePromenadeClass) {
		saisieVehiculePromenadeClass->setWindowTitle(
				QApplication::translate("saisieVehiculePromenadeClass",
						"Ajouter un vehicule promenade", 0,
						QApplication::UnicodeUTF8));
		pushButtonOkayVehPromenade->setText(
				QApplication::translate("saisieVehiculePromenadeClass", "Ok", 0,
						QApplication::UnicodeUTF8));
		labelSoustitreAjoutVehiculePromenade->setText(
				QApplication::translate("saisieVehiculePromenadeClass",
						"Informations du vehicule de promenade", 0,
						QApplication::UnicodeUTF8));
		label_Niv_VehProm->setText(
				QApplication::translate("saisieVehiculePromenadeClass", "NIV",
						0, QApplication::UnicodeUTF8));
		label_Immatriculation_VehProm->setText(
				QApplication::translate("saisieVehiculePromenadeClass",
						"Immatriculation", 0, QApplication::UnicodeUTF8));
		label_Nb_Sieges->setText(
				QApplication::translate("saisieVehiculePromenadeClass",
						"Nombre de sieges", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class saisieVehiculePromenadeClass: public Ui_saisieVehiculePromenadeClass {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAISIEVEHICULEPROMENADE_H
