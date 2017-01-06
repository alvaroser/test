/********************************************************************************
 ** Form generated from reading UI file 'supprimervehicule.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.7
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_SUPPRIMERVEHICULE_H
#define UI_SUPPRIMERVEHICULE_H

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

class Ui_SupprimerVehiculeClass {
public:
	QLineEdit *lineEditNivSupprimer;
	QLabel *label;
	QLabel *labelNivSupprimer;
	QPushButton *buttonSupprimer;

	void setupUi(QDialog *SupprimerVehiculeClass) {
		if (SupprimerVehiculeClass->objectName().isEmpty())
			SupprimerVehiculeClass->setObjectName(
					QString::fromUtf8("SupprimerVehiculeClass"));
		SupprimerVehiculeClass->resize(384, 129);
		lineEditNivSupprimer = new QLineEdit(SupprimerVehiculeClass);
		lineEditNivSupprimer->setObjectName(
				QString::fromUtf8("lineEditNivSupprimer"));
		lineEditNivSupprimer->setGeometry(QRect(110, 40, 201, 27));
		label = new QLabel(SupprimerVehiculeClass);
		label->setObjectName(QString::fromUtf8("label"));
		label->setGeometry(QRect(110, 10, 191, 20));
		label->setAlignment(Qt::AlignCenter);
		labelNivSupprimer = new QLabel(SupprimerVehiculeClass);
		labelNivSupprimer->setObjectName(
				QString::fromUtf8("labelNivSupprimer"));
		labelNivSupprimer->setGeometry(QRect(80, 50, 31, 17));
		buttonSupprimer = new QPushButton(SupprimerVehiculeClass);
		buttonSupprimer->setObjectName(QString::fromUtf8("buttonSupprimer"));
		buttonSupprimer->setGeometry(QRect(150, 80, 85, 27));

		retranslateUi(SupprimerVehiculeClass);
		QObject::connect(buttonSupprimer, SIGNAL(clicked()),
				SupprimerVehiculeClass, SLOT(validerSupprimer()));

		QMetaObject::connectSlotsByName(SupprimerVehiculeClass);
	} // setupUi

	void retranslateUi(QDialog *SupprimerVehiculeClass) {
		SupprimerVehiculeClass->setWindowTitle(
				QApplication::translate("SupprimerVehiculeClass",
						"Supprimer Vehicule", 0, QApplication::UnicodeUTF8));
		label->setText(
				QApplication::translate("SupprimerVehiculeClass",
						"Supprimer un vehicule", 0, QApplication::UnicodeUTF8));
		labelNivSupprimer->setText(
				QApplication::translate("SupprimerVehiculeClass", "NIV", 0,
						QApplication::UnicodeUTF8));
		buttonSupprimer->setText(
				QApplication::translate("SupprimerVehiculeClass", "Supprimer",
						0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class SupprimerVehiculeClass: public Ui_SupprimerVehiculeClass {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERVEHICULE_H
