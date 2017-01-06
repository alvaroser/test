/********************************************************************************
 ** Form generated from reading UI file 'saisiecamion.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.7
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_SAISIECAMION_H
#define UI_SAISIECAMION_H

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

class Ui_saisieCamionClass {
public:
	QLineEdit *lineEditNiv;
	QLineEdit *lineEditImmatriculation;
	QLineEdit *lineEditPoids;
	QLineEdit *lineEditEssieux;
	QLabel *labelNiv;
	QLabel *label_soustitre_camion;
	QLabel *labelImmatriculation;
	QLabel *LabelPoids;
	QLabel *labelEssieux;
	QPushButton *pushButtonSaisieCamionOk;

	void setupUi(QDialog *saisieCamionClass) {
		if (saisieCamionClass->objectName().isEmpty())
			saisieCamionClass->setObjectName(
					QString::fromUtf8("saisieCamionClass"));
		saisieCamionClass->resize(308, 222);
		lineEditNiv = new QLineEdit(saisieCamionClass);
		lineEditNiv->setObjectName(QString::fromUtf8("lineEditNiv"));
		lineEditNiv->setGeometry(QRect(120, 50, 181, 27));
		lineEditImmatriculation = new QLineEdit(saisieCamionClass);
		lineEditImmatriculation->setObjectName(
				QString::fromUtf8("lineEditImmatriculation"));
		lineEditImmatriculation->setGeometry(QRect(120, 80, 181, 27));
		lineEditPoids = new QLineEdit(saisieCamionClass);
		lineEditPoids->setObjectName(QString::fromUtf8("lineEditPoids"));
		lineEditPoids->setGeometry(QRect(120, 110, 81, 27));
		lineEditEssieux = new QLineEdit(saisieCamionClass);
		lineEditEssieux->setObjectName(QString::fromUtf8("lineEditEssieux"));
		lineEditEssieux->setGeometry(QRect(120, 140, 81, 27));
		labelNiv = new QLabel(saisieCamionClass);
		labelNiv->setObjectName(QString::fromUtf8("labelNiv"));
		labelNiv->setGeometry(QRect(10, 50, 55, 17));
		label_soustitre_camion = new QLabel(saisieCamionClass);
		label_soustitre_camion->setObjectName(
				QString::fromUtf8("label_soustitre_camion"));
		label_soustitre_camion->setGeometry(QRect(90, 10, 151, 20));
		labelImmatriculation = new QLabel(saisieCamionClass);
		labelImmatriculation->setObjectName(
				QString::fromUtf8("labelImmatriculation"));
		labelImmatriculation->setGeometry(QRect(10, 80, 91, 17));
		LabelPoids = new QLabel(saisieCamionClass);
		LabelPoids->setObjectName(QString::fromUtf8("LabelPoids"));
		LabelPoids->setGeometry(QRect(10, 120, 55, 17));
		labelEssieux = new QLabel(saisieCamionClass);
		labelEssieux->setObjectName(QString::fromUtf8("labelEssieux"));
		labelEssieux->setGeometry(QRect(10, 150, 111, 17));
		pushButtonSaisieCamionOk = new QPushButton(saisieCamionClass);
		pushButtonSaisieCamionOk->setObjectName(
				QString::fromUtf8("pushButtonSaisieCamionOk"));
		pushButtonSaisieCamionOk->setEnabled(true);
		pushButtonSaisieCamionOk->setGeometry(QRect(210, 190, 85, 27));

		retranslateUi(saisieCamionClass);

		QMetaObject::connectSlotsByName(saisieCamionClass);
	} // setupUi

	void retranslateUi(QDialog *saisieCamionClass) {
		saisieCamionClass->setWindowTitle(
				QApplication::translate("saisieCamionClass",
						"Ajouter un camion", 0, QApplication::UnicodeUTF8));
		labelNiv->setText(
				QApplication::translate("saisieCamionClass", "NIV", 0,
						QApplication::UnicodeUTF8));
		label_soustitre_camion->setText(
				QApplication::translate("saisieCamionClass",
						"Informations du camion", 0,
						QApplication::UnicodeUTF8));
		labelImmatriculation->setText(
				QApplication::translate("saisieCamionClass", "Immatriculation",
						0, QApplication::UnicodeUTF8));
		LabelPoids->setText(
				QApplication::translate("saisieCamionClass", "Poids", 0,
						QApplication::UnicodeUTF8));
		labelEssieux->setText(
				QApplication::translate("saisieCamionClass", "Nombre d'essieux",
						0, QApplication::UnicodeUTF8));
		pushButtonSaisieCamionOk->setText(
				QApplication::translate("saisieCamionClass", "OK", 0,
						QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class saisieCamionClass: public Ui_saisieCamionClass {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAISIECAMION_H
